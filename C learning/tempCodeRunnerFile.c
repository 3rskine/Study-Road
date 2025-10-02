#include <stdio.h>

/*Step 1: Determine the "Base Rate"(Subsidy per hectare)

Rice: $10,000 / hectare
Pomelo: $8,000 / hectare
Watermelon: $6,000 / hectare

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



typedef struct farmer
{   
    int crop_type , age ,isOrg;
    double area , result;
}person;

void baseMul(person *f){
    f->result = (f->crop_type == 1 ? 10000 : f->crop_type == 2 ? 8000 : 6000)* f->area;
}
void OrgniRule(person *f){
   (f->crop_type == 2 && f->isOrg == 1) ? f->result *= 1.8 : f->result *= (f->isOrg == 1 ? 1.5 : 1)
}

void ageRule(person *f){
    f->result *= !(f->crop_type == 3 && f->area <= 0.5) && f->age <= 40 ? 1.2 : 1 ;
}
void riceRule(person *f){
    f->result = (f->crop_type == 1 && f->area >= 5 ? 
        double extra =  f->area - 5 * 10000 *0.8;
        double base_rice = 50000;
        (f->isOrg == 1 ? base_rice*1.5 : base_rice) += extra : result );
}
void maxRule(person *f){
    f->result = f->result >= 200000 ? 200000 ; f->result;
}
void Calculator(person *f){
    void(*cmd)(person *) = {baseMul , OrgniRule , ageRule ,riceRule};
    for (int i = 0; i < count; i++) cmd[i](f);
}

int main(){
    person a;
    scanf("%d %d %d %lf" ,&a.cropType,&a.age,&a.isOrganic,&a.area );
    Calculator(&a);
    printf("Final Subsidy: %d\n",(int)a.subsidy);
    return 0;
}