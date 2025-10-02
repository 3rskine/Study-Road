#include <stdio.h>

// 作物結構
typedef struct { 
    int type;       // 1=稻米, 2=文旦, 3=西瓜
    double base_rate;    
} Crop;

// 農民結構
typedef struct Farmer {
    int age;
    int is_organic;        // 1=有機, 0=非有機
    double area;           // 土地面積（公頃）
    Crop crop;             // 所種作物
    int (*calculate_subsidy)(struct Farmer*); // 函數指標
} Farmer;

// 補助計算函數
int default_subsidy(Farmer *farmer) {
    // 設定作物基本補助
    if (farmer->crop.type == 1) farmer->crop.base_rate = 10000;    // 稻米
    else if (farmer->crop.type == 2) farmer->crop.base_rate = 8000; // 文旦
    else farmer->crop.base_rate = 6000;                             // 西瓜

    // 計算倍率
    double organic_multiplier = 1.0;
    if (farmer->is_organic) {
        if (farmer->crop.type == 2) organic_multiplier = 1.8; // 文旦有機特殊條款
        else organic_multiplier = 1.5;                        // 其他作物有機
    }

    double young_multiplier = 1.0;
    if (farmer->age <= 40 && !(farmer->crop.type == 3 && farmer->area < 0.5)) {
        young_multiplier = 1.2; // 年輕農民加成（西瓜小面積例外）
    }

    // 計算補助
    double subsidy;
    if (farmer->crop.type == 1 && farmer->area > 5) {
        // 稻米大戶條款
        subsidy = 5 * farmer->crop.base_rate * organic_multiplier * young_multiplier +
                  (farmer->area - 5) * farmer->crop.base_rate * 0.8 * organic_multiplier * young_multiplier;
    } else {
        subsidy = farmer->area * farmer->crop.base_rate * organic_multiplier * young_multiplier;
    }

    // 補助上限
    if (subsidy > 200000) subsidy = 200000;

    return (int)subsidy; // 捨去小數
}

int main() {
    Farmer farmer;

    // 輸入：作物種類 年齡 是否有機 土地面積
    scanf("%d %d %d %lf", &farmer.crop.type, &farmer.age, &farmer.is_organic, &farmer.area);

    // 將函數指標指向補助計算函數
    farmer.calculate_subsidy = default_subsidy;

    // 呼叫函數指標計算補助
    printf("Final Subsidy: %d\n", farmer.calculate_subsidy(&farmer));

    return 0;
}
