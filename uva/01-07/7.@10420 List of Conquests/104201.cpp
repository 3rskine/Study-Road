#include  <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;


int main () {
    int s;
    cin >> s;
    cin.ignore();

    map<string , int> count;

    while (s--)
    {
        string whole;
        getline(cin, whole); //cin一個字串，但會讀取整行(包括空格)

        stringstream extract(whole); //stringstream 是一個屬性，可以讀取第一個字（直到第一個空格）
        string country;
        extract >> country; //將第一個字放進country這個屬性是string的變數裡
        count[country]++; //count本身的屬性是int。但它讀取的是字串，也就是如果有相同的字串，次數就會疊加
    }

    
    for( auto&p : count ){ // 遍歷整個 map
    cout << p.first << " " << p.second << endl;
    }
    return 0 ;
}