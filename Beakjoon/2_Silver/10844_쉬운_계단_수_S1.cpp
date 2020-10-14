#include <iostream>
using namespace std;
long long dp[101][11] = {0};

int main(){
    int n;
    cin >> n;

    for(int i=1; i<10; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i-1][1];
        for(int j=1; j<10; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }

    long long sum = 0;
    for(int i=0; i<10; i++){
        sum += dp[n][i];
    }
    cout << sum;
}