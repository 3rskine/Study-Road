#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
int main(){
    vector<long long> A(2 , 0);
    while(1){
    
        
        for(int i = 0; i<A.size() ; i++){
        if (!(cin>>A[i])) return 0;
        }
    
    cout << llabs(A[1]-A[0]) <<endl ;
    
    }
return 0;
}
