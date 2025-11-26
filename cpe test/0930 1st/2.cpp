#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    while (getline(cin , line))
    {
        string word;
        stringstream sentence(line);
        bool hasbegin = 0;
        while (sentence >> word)
        {
            reverse(word.begin() , word.end());
            if(hasbegin) cout << " ";
            hasbegin = 1;
            cout << word;
        }
        cout << "\n";
    }
    return 0;
}