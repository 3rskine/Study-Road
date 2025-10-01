#include <iostream>2
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n ;
    cin >> n;
    while (n--){
    int k;
    cin >> k ;
    vector<int> rel(k);

    for (int i =0; i<k; i++){
    cin >> rel[i];    
    }
    sort(rel.begin () , rel.end() );

    int med = rel [ k/ 2];
    int sum=0;
    for (int i=0 ; i <k ; i++){
    sum += abs( med - rel[i]);
    }

    cout << sum << endl;
    
    }

    return 0;
}