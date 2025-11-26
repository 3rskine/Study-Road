#include <bits/stdc++.h>
using namespace std;

int main(){
    double L,W;
    double MX,mx;
    while (cin >> L >> W)
    {
        MX = (L + W) - sqrt(L*L - L*W + W*W) / 6.0;
        mx = min(L , W) * 0.5;
        printf("%.3lf %.3lf %.3lf" , MX + (1E-6) , 0.0 , mx + (1E-6));
    }
    return 0;
}