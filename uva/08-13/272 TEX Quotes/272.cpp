#include <iostream>
#include <string>
using namespace std;
int main() {
    string n;
    bool state = 1;
    
    while(getline(cin , n)){
        for(char c : n){
            if(c == '"'){
                if(state) cout<<"``";
                else cout<<"''";
                state = !state;
            }
            else cout<< c;
        }
        cout<<endl;
    }
    return 0 ;
}