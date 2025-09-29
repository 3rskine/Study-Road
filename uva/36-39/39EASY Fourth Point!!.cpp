#include <bits/stdc++.h>
using namespace std;

bool issame (double a , double b){
    return fabs(a - b) < 1e-10;
}

int main(){
    double x1,x2,x3,x4,y1,y2,y3,y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        double resX = 0 ,resY = 0;
        if(issame(x1 , x3) && issame (y1 , y3)){
            resX = x2 + x4 - x1;
            resY = y2 + y4 - y1;
        }
        else if(issame(x1 , x4) && issame (y1 , y4)){
            resX = x2 + x3 - x1;
            resY = y2 + y3 - y1;
        }
        else if(issame(x2 , x3) && issame (y2 , y3)){
            resX = x1 + x4 - x2;
            resY = y1 + y4 - y2;
        }
        else if (issame(x2 , x4) && issame (y2 , y4)){
            resX = x1 + x3 - x2;
            resY = y1 + y3 - y2;
        }
        else {
            resX= 0;
            resY = 0;
        }
        printf("%.3f %.3f\n", resX , resY);
    }
    return 0;
}