# joystick_oled_minimal.py
# MicroPython for ESP32
# 顯示：Centered X/Y、Direction(英文)、BTN 狀態 (R=Released, P=Pressed)
# 接線：URx=27 URy=35 SW=17 SDA=21 SCL=22

from machine import Pin, ADC, I2C
import time

# ===== user pins =====
JOYSTICK_X_PIN = 27
JOYSTICK_Y_PIN = 35
JOYSTICK_BUTTON_PIN = 17
I2C_SDA_PIN = 21
I2C_SCL_PIN = 22

OLED_WIDTH = 128
OLED_HEIGHT = 64   # 如果是 128x32 改成 32

# ===== parameters =====
MOVING_AVG_WINDOW = 5
DEADZONE = 200
REFRESH_INTERVAL = 0.12

# ===== init ADC & button =====
adc_x = ADC(Pin(JOYSTICK_X_PIN))
adc_y = ADC(Pin(JOYSTICK_Y_PIN))
button = Pin(JOYSTICK_BUTTON_PIN, Pin.IN, Pin.PULL_UP)  # 0=pressed

try:
    adc_x.atten(ADC.ATTN_11DB)
    adc_y.atten(ADC.ATTN_11DB)
except:
    pass
try:
    adc_x.width(ADC.WIDTH_12BIT)
    adc_y.width(ADC.WIDTH_12BIT)
except:
    pass

# ===== init I2C & OLED (optional) =====
try:
    i2c = I2C(0, scl=Pin(I2C_SCL_PIN), sda=Pin(I2C_SDA_PIN), freq=400000)
except Exception:
    i2c = I2C(scl=Pin(I2C_SCL_PIN), sda=Pin(I2C_SDA_PIN), freq=400000)

oled = None
try:
    import ssd1306
    oled = ssd1306.SSD1306_I2C(OLED_WIDTH, OLED_HEIGHT, i2c)
except Exception as e:
    oled = None
    # 若沒有 OLED，會把結果印到序列埠，方便除錯
    print("OLED not available (ssd1306.py missing or init error). I2C scan:", i2c.scan(), "err:", e)

# ===== smoothing buffer =====
buffer_x = []
buffer_y = []
def push_and_average(buffer, value, maxlen):
    buffer.append(value)
    if len(buffer) > maxlen:
        buffer.pop(0)
    return sum(buffer) // len(buffer)

# ===== center calibration (once at boot) =====
def calibrate_center(samples=80, delay=0.01):
    sx = 0
    sy = 0
    for _ in range(samples):
        sx += adc_x.read()
        sy += adc_y.read()
        time.sleep(delay)
    return sx // samples, sy // samples

print("Calibrating center... keep joystick still")
center_x, center_y = calibrate_center()
print("Calibrated: cX =", center_x, " cY =", center_y)
time.sleep(0.1)

# ===== direction detection (input: centered dx, dy) =====
def get_direction_english(dx, dy, deadzone):
    adx = abs(dx)
    ady = abs(dy)
    if adx < deadzone and ady < deadzone:
        return "Center"
    up = dy < -deadzone
    down = dy > deadzone
    left = dx < -deadzone
    right = dx > deadzone
    # diagonal if both axes significant and similar
    if (left or right) and (up or down):
        ratio = 0.6
        if adx * ratio <= ady and ady * ratio <= adx:
            if up and left: return "Up-Left"
            if up and right: return "Up-Right"
            if down and left: return "Down-Left"
            if down and right: return "Down-Right"
    if up: return "Up"
    if down: return "Down"
    if left: return "Left"
    if right: return "Right"
    return "Unknown"

# ===== minimal OLED display =====
def show_minimal_on_oled(centered_x, centered_y, direction_text, btn_state):
    # If no OLED, print to serial
    if oled is None:
        print("X:{:+5d} Y:{:+5d}  DIR:{}  BTN:{}".format(centered_x, centered_y, direction_text, btn_state))
        return
    oled.fill(0)
    # line 1: centered X/Y
    oled.text("X:{:+5d}  Y:{:+5d}".format(centered_x, centered_y), 0, 0)
    # line 2: direction and button
    oled.text("DIR: {}".format(direction_text), 0, 20)
    oled.text("BTN: {}".format(btn_state), 0, 40)
    oled.show()

# ===== main loop =====
try:
    last_show = 0
    while True:
        raw_x = adc_x.read()
        raw_y = adc_y.read()

        smooth_x = push_and_average(buffer_x, raw_x, MOVING_AVG_WINDOW)
        smooth_y = push_and_average(buffer_y, raw_y, MOVING_AVG_WINDOW)

        # centered coordinates (center = 0,0)
        centered_x = smooth_x - center_x
        centered_y = smooth_y - center_y
        # if Y appears inverted, use: centered_y = center_y - smooth_y

        direction_text = get_direction_english(centered_x, centered_y, DEADZONE)
        btn_state = "P" if button.value() == 0 else "R"

        if (time.time() - last_show) >= REFRESH_INTERVAL:
            show_minimal_on_oled(centered_x, centered_y, direction_text, btn_state)
            last_show = time.time()

        time.sleep(0.01)

except KeyboardInterrupt:
    print("Stopped")
