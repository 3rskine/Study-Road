#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main (){
        vector<string> sentences;
        string line;
        int Maxlen = 0;
    while (getline(cin,line) && !line.empty())
    {
        sentences.push_back(line);
        if (line.length() > Maxlen) Maxlen= line.length();      
    }
    for (auto &s : sentences)
    {
        while (s.length()<Maxlen)
        {
            s+= " ";
        }
    }
    for(int col = 0; col < Maxlen ; col ++){
        for (int row = sentences.size()-1; row>=0 ; row--)
        {
            cout<< sentences[row][col];
        }
    cout<<endl;
    }
    return 0 ;    
}

    
    
    