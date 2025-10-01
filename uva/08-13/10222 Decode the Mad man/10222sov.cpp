#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string keyboard = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    string word;
    while(getline (cin,word)){
        for (char ch : word){
        
            if( ch == ' ') {
                cout <<' ';
        }
        else{
            char lowerCh = tolower(ch);
            size_t gpstheCh = keyboard.find(lowerCh);
            if (gpstheCh !=string::npos && gpstheCh >=2 )
            {
                cout << keyboard[gpstheCh - 2];
            }
        } 
        }
        cout<< endl;
    }
    return 0;
}