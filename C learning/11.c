#include <stdio.h>
typedef struct animalinfo
{
    int type, weight ,score;
}animal;

int apigrule(int w , int i){
    return w + (w > 100 ? 50 : 0);
}

int athreegunrule(int w , int i){
    return (i < 5) ? w * 2 : 0;
}

int adeerrula(int w, int i){
    return w*3;
}

int main() {
    animal a;
    int count = 0, sumweight = 0, score = 0;
    int gunnum = 0;

    int (*rule_funcs[4])(int, int) = {NULL, apigrule, athreegunrule, adeerrula};

    while(scanf("%d %d", &a.type, &a.weight) && a.type != 0){
        count++;
        sumweight += a.weight;

        if(a.type == 2){ // threegun spec rule
            a.score = rule_funcs[a.type](a.weight, gunnum);
            gunnum++;
        } else {
            a.score = rule_funcs[a.type](a.weight, -1);
        }
        score += a.score;
    }

    printf("Total Animals Reported: %d\n", count);
    printf("Total Weight Reported: %d kg\n", sumweight);
    printf("Total Conservation Points: %d\n", score);

    return 0;
}