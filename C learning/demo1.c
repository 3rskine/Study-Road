#include <stdio.h>

typedef struct Farmer {
    int cropType;    // 1=Rice,2=Pomelo,3=Watermelon
    int age;
    int isOrganic;   // 1=yes,0=no
    double area;

    double baseRate;
    double organicMult;
    double youngMult;
    double subsidy;
} Farmer;

/* rules */
void baseRule(Farmer *f) {
    if (f->cropType == 1) f->baseRate = 10000.0;
    else if (f->cropType == 2) f->baseRate = 8000.0;
    else f->baseRate = 6000.0;
    /* 初步把 subsidy 設為 base * area（特殊例外可能改寫） */
    f->subsidy = f->baseRate * f->area;
}

void organicRule(Farmer *f) {
    f->organicMult = f->isOrganic ? 1.5 : 1.0;
}

void ageRule(Farmer *f) {
    f->youngMult = (f->age <= 40) ? 1.2 : 1.0;
}

/* special exceptions (優先處理、會修改 multipliers / 計算方式) */
void specialRule(Farmer *f) {
    /* Pomelo 有機例外：有機倍率從 1.5 變 1.8 */
    if (f->cropType == 2 && f->isOrganic) f->organicMult = 1.8;

    /* Watermelon 小面積：不適用年輕加成 */
    if (f->cropType == 3 && f->area < 0.5) f->youngMult = 1.0;

    /* Rice 大戶：前 5 公頃正常，超過部分 80% rate */
    if (f->cropType == 1 && f->area > 5.0) {
        double first5 = 5.0 * f->baseRate;
        double extra  = (f->area - 5.0) * f->baseRate * 0.8;
        f->subsidy = (first5 + extra) * f->organicMult * f->youngMult;
    } else {
        /* 一般情況：整塊地套用 multiplier */
        f->subsidy = f->baseRate * f->area * f->organicMult * f->youngMult;
    }
}

/* cap */
void capRule(Farmer *f) {
    if (f->subsidy > 200000.0) f->subsidy = 200000.0;
}

/* calculate：把規則放到函數指標陣列，依序套用 */
void calculate(Farmer *f) {
    void (*rules[])(Farmer*) = { baseRule, organicRule, ageRule, specialRule, capRule };
    int n = sizeof(rules) / sizeof(rules[0]);
    for (int i = 0; i < n; ++i) rules[i](f);
}

int main(void) {
    Farmer f;
    if (scanf("%d %d %d %lf", &f.cropType, &f.age, &f.isOrganic, &f.area) != 4) return 0;
    calculate(&f);
    printf("Final Subsidy: %d\n", (int)f.subsidy); /* 小數部分截斷 */
    return 0;
}
