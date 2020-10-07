#include <iostream>
#include <string>
using namespace std;

int n, ans = -987654321;
string str;

int Cal(int a, int b, char oper){
    int result = a;
    if(oper == '+')
        result += b;
    else if(oper == '-')
        result -= b;
    else
        result *= b;

    return result;
}

void recur(int idx, int cur){
    if(idx > n -1){
        ans = max(ans, cur);
        return;
    }

    char oper = (idx == 0) ? '+' : str[idx-1];

    if(idx+2 < n){
        int GwalHo = Cal(str[idx]-'0', str[idx+2]-'0', str[idx+1]);
        recur(idx+4, Cal(cur, GwalHo, oper));
    }

    recur(idx+2, Cal(cur, str[idx]-'0', oper));
}

int main(){
    cin >> n >> str;

    recur(0, 0);
    cout << ans;
}