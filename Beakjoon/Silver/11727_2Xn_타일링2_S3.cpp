#include <iostream>
using namespace std;
long long dp[1001] = {0};

int main(){
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 3;

    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-2] + dp[i-2] + dp[i-1]) % 10007;
    }

    cout << dp[n];
}