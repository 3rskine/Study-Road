#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
int main (){
    string s;
    while(getline(cin , s)){
        stringstream sentence(s); int isstart = 0;
        while (sentence >> s)
        {
            reverse(s.begin() , s.end() );
            if(isstart++) cout << " ";
            cout << s;
        }
        cout << "\n";
    }
    return 0;
}