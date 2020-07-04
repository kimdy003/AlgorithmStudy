#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        string s;
        cin >> s;
        bool flag = true;

        for(int i=0, j=s.size()-1; i<s.size(); i++, j--){
            if(s[i] != s[j]){
                flag = false;
                break;
            }
        }

        cout << "#" << test << " " << flag << "\n";
    }
}