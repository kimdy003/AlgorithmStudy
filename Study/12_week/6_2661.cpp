#include <iostream>

using namespace std;

int n;
string ans = "";

void Backtrack(char str, int cnt){
    if(cnt-1 == n){
        cout << ans << "\n";
        exit(0);
    }

    ans += str;
    for(int i=1; i<= cnt/2; i++){
        string a = ans.substr(cnt - i, i);
        string b = ans.substr(cnt - (i*2), i);

        if(a == b){
            ans.erase(cnt-1);
            return;
        }
    }

    for(int i=1; i<=3; i++){
        Backtrack(i+'0', cnt+1);
    }

    ans.erase(cnt-1);

}

int main(){
    cin >> n;
    for(int i=1; i<=3; i++)
        Backtrack(i+'0', 1);
}