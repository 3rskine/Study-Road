/*Rice: $10,000 / hectare 1
Pomelo: $8,000 / hectare 2
Watermelon: $6,000 / hectare 3

Step 2:
is_organic == 1 -> *=1.5
farmer_age <= 40 ->  *= 1.2

Step3:
if isPomelo && it is_organic , *=1.8
isWatermelon && land area <= 0.5 hectares, "Young Farmer Bonus" = 0; (Step 2: *= 1;)
isRice && land area >= 5 hectares , exceeding 5 hectaresis reduced by 20% (*= 0.8)

Step4:
if >=200000 , == 200000

input : [crop_type] [farmer_age] [is_organic] [area]
output : Final Subsidy: [Final Amount]
*/

#include <stdio.h>

typedef struct farmer {
    int crop_type, age, isOrg;
    double area, result;
} person;

void baseRule(person *f){
    if(f->crop_type == 1) f->result = 10000 * f->area;       
    else if(f->crop_type == 2) f->result = 8000 * f->area;   
    else f->result = 6000 * f->area;                         
}


void OrgniRule(person *f){
    if(f->crop_type == 2 && f->isOrg == 1)f->result *= 1.8;  
    else if(f->isOrg == 1)f->result *= 1.5; 
}

void ageRule(person *f){
    f->result *= (f->crop_type == 3 && f->area < 0.5) ? 1 : (f->age <= 40 ? 1.2 : 1);
}

// Step 3: Rice Large Holder
void riceRule(person *f){
    if(f->crop_type == 1 && f->area > 5){
        double base = 5 * 10000; 
        if(f->isOrg) base *= 1.5;
        double extra_result = (f->area - 5) * 10000 * 0.8; 
        f->result = base + extra_result;
    }
}

void maxRule(person *f){
    if(f->result > 200000) f->result = 200000;
}

void Calculator(person *f){
    void(*cmd[])(person *) = {baseRule, OrgniRule, ageRule, riceRule, maxRule}; //function array
    for(int i=0; i<5; i++) cmd[i](f);
}

int main(){
    person a;
    scanf("%d %d %d %lf", &a.crop_type, &a.age, &a.isOrg, &a.area);
    Calculator(&a);
    printf("Final Subsidy: %d\n", (int)a.result); // truncate decimal
    return 0;
}
