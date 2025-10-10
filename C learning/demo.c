#include <stdio.h>

typedef struct {
    int code;
    int weight;
    int points;
} Animal;

// 函數指標類型
typedef int (*CalcPointsFunc)(int weight, int index);

// 山豬積分
int f_boar(int w, int i){ return w + (w>100?50:0); }

// 山羌積分
int f_muntjac(int w, int i){ return i<5 ? w*2 : 0; }

// 水鹿積分
int f_sambar(int w, int i){ return w*3; }

int main(){
    Animal a;
    int total_count=0, total_weight=0, total_points=0, muntjac_index=0;

    // 代碼對應函數指標
    CalcPointsFunc funcs[4]={NULL,f_boar,f_muntjac,f_sambar};

    while(scanf("%d %d",&a.code,&a.weight) && a.code){
        total_count++;
        total_weight += a.weight;

        a.points = (a.code==2) ? funcs[a.code](a.weight,muntjac_index++) 
                               : funcs[a.code](a.weight,0);
        total_points += a.points;
    }

    printf("Total Animals Reported: %d\n", total_count);
    printf("Total Weight Reported: %d kg\n", total_weight);
    printf("Total Conservation Points: %d\n", total_points);
    return 0;
}
