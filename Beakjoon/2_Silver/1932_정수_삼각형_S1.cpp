#include <iostream>
using namespace std;
int map[501][501] = {0};
int dp[501][501] = {0};

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> map[i][j];
        }
    }

    dp[1][1] = map[1][1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j == 1){
                dp[i][j] = dp[i-1][j] + map[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i-1][j-1] + map[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + map[i][j];
            }
        }
    }

    int Max = 0;
    for(int i=1; i<=n; i++){
        Max = max(Max, dp[n][i]);
    }

    cout << Max;
}