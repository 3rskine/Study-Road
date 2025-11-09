#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    queue<string> stringQueue;
    vector<string> allStrings;

    for(auto letter : alphabet){
        string singleString(1, letter); //將singlestring宣告為letter字串
        
        stringQueue.push(singleString);
        allStrings.push_back(singleString);
    }

    while(!stringQueue.empty()){
        string currentString = stringQueue.front();
        stringQueue.pop();

        for(auto letter : alphabet){
            if(currentString.back() < letter){
                string newString = currentString + letter;
                if(newString.size() > 5) continue;
                stringQueue.push(newString);
                allStrings.push_back(newString);
            }
        }
    }

    string inputString;
    while(cin >> inputString){
        auto it = find(allStrings.begin(), allStrings.end(), inputString);
        if(it == allStrings.end()){
            cout << 0 << endl;
        } else {
            cout << (it - allStrings.begin() + 1) << endl;
        }
    }

    return 0;
}
