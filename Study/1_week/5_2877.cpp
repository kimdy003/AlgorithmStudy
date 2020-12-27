#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s = "";

    n += 1;
    while (n != 0){
        s = to_string(n%2) + s;
        n /= 2;
    }

    for(int i=1; i<s.length(); i++){
        if(s[i] == '0')
            cout << 4;
        else
            cout << 7;
    }
}