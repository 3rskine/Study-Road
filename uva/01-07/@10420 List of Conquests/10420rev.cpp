#include <iostream>
#include <map>
#include <sstream>
#include <map>
using  namespace std;
int main() {
    int n ;
    cin >> n ;
    cin.ignore();

    map<string , int> information;
        while (n--)
        {   
            string wholeinfo , country;
            getline(cin , wholeinfo);
            stringstream extract(wholeinfo);
            extract>>country;
            information[country]++; //他就是一個整數，所以可以++
        }
    for( auto&p : information){
    cout<< p.first << " " << p.second <<endl;
    }
    return 0;
}
