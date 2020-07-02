#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        string s;
        cin >> s;
        int size;
        bool flag = true;
        size = s.size()-1;

        for(int i=0, j=s.size()-1; i<s.size(); i++, j--){
            if(s[i] != s[j]){
                flag = false;
                break;
            }
        }
        cout << "#" << test << " ";
        if(flag){
            cout << 1 << "\n";
        }else{
            cout << 0 << "\n";
        }



    }
}