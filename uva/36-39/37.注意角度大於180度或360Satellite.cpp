#include <bits/stdc++.h>

using namespace std;

int main(){
    const double R = 6440.0;
    const double PI = 3.14159265358979323846; 
    double aboveEarthDistance , xthedegree; 
    string unit;

    while (cin >> aboveEarthDistance >> xthedegree >> unit)
    {   double arc  , chord = 0;
        double r = aboveEarthDistance + R;
        double theta = 0;

        if(unit == "deg"){
            theta = xthedegree * PI / 180.0;
        }
        if(unit == "min"){
            theta = (xthedegree / 60.0) * PI / 180.0;
        }

        theta = fmod(theta, 2 * PI); //fmod (一直被拿的數 ， 拿多少數)
        if (theta > PI) {
            theta = 2 * PI - theta;
        }

        arc = r * theta;
        chord = 2 * r * sin(theta / 2);
        printf("%.6f %.6f\n" , arc ,chord);
    }
    
    
    return 0;
}