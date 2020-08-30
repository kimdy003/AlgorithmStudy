#include <iostream>
using namespace std;

int main(){
    int dp[10001] = {0};
    int arr[10001] = {0};

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    int Max = dp[2];
    for(int i=3; i<=n; i++){
        dp[i] = max(dp[i-3]+arr[i-1]+arr[i], dp[i-2] + arr[i]);
        dp[i] = max(dp[i], dp[i-1]);
        Max = max(Max, dp[i]);
    }
    
    cout << Max;
}