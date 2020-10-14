#include <iostream>
using namespace std;

int main(){
   int dp[100000] = {0};
   int arr[100000] = {0};
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    int ans = dp[0];
    
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1]+ arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
}