#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;


int main (){
    int n;
    cin >> n ;
    cin.ignore();
    string word;
    map<char,int> counttimes;
    while (n--)
    {
        getline(cin,word);
        for( char wordUnits : word){
            
            if (isalpha(wordUnits))
            {
                char turnUnitsToUpper = toupper(wordUnits);
                counttimes[turnUnitsToUpper]++;
            }
            
        }
    }
    vector<pair<char,int>>arrangement (counttimes.begin(),counttimes.end());
    
    sort(arrangement.begin(),arrangement.end() , [] (const pair <char,int> &a ,const pair <char,int> &b ){
        if(a.second!=b.second) return a.second>b.second;
        else return a.first<b.first;
    });
    for ( auto &p : arrangement)
    {
        cout<< p.first << " " << p.second <<endl;
    }
    
    return 0 ;
}