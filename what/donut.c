#include <stdio.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 26
#define HIDE_CURSOR() printf("\033[?25l")
#define SHOW_CURSOR() printf("\033[?25h")
#define PI 3.1415926

int main() {
    float A=0, B=0;
    float z[WIDTH*HEIGHT];
    char b[WIDTH*HEIGHT+1];
    HIDE_CURSOR();
    printf("\x1b[2J");

    for(;;){
        memset(b,' ', WIDTH*HEIGHT);
        memset(z,0,sizeof(z));

        for(float j=0;j<6.28;j+=0.07){
            for(float i=0;i<6.28;i+=0.04){
                float c = sin(i), d=cos(j), e=sin(A), f=sin(j), g=cos(A);
                float h = d+2;
                float D = 1/(c*h*e + f*g + 5);
                float l = cos(i), m=cos(B), n=sin(B);
                float t = c*h*g - f*e;
                int x = WIDTH/2 + (int)(30*D*(l*h*m - t*n));
                int y = HEIGHT/2 + (int)(15*D*(l*h*n + t*m));
                int o = x + WIDTH*y;
                int N = 8*((f*e - c*d*g)*m - c*d*e - f*g - l*d*n);
                if(y>=0 && y<HEIGHT && x>=0 && x<WIDTH && D>z[o]){
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N>0?N:0];
                }
            }
        }

        b[WIDTH*HEIGHT] = '\0';
        printf("\x1b[H");
        for(int k=0;k<HEIGHT;k++){
            fwrite(b+k*WIDTH, 1, WIDTH, stdout);
            putchar('\n');
        }

        A += 0.04;
        B += 0.02;
    }

    SHOW_CURSOR();
    return 0;
}
