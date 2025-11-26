#include <iostream>
#include <string>
using namespace std;
int main (){
    string n;
    while (cin >> n && n != "0")
    {
        while (n.size() > 1)
        {
            int sum = 0;
            for (char units : n) sum += units - '0';
            
                n = to_string (sum);
        }
        cout << n <<endl;
    }
return 0 ;
}