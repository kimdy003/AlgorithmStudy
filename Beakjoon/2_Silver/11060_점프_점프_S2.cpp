#include <iostream>
using namespace std;
int n;
int dir[1000] = {0};
int dp[1000];

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> dir[i];
        dp[i] = 987654321;
    }

    dp[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=1; j<= dir[i]; j++){
            if(i+j>=n)
                break;
            if(dp[i+j] > dp[i]+1)
                dp[i+j] = dp[i]+1;
        }
    }
    
    

    if(dp[n-1] == 987654321)
        cout << "-1" << "\n";
    else
        cout << dp[n-1] << "\n";
    
    return 0;
}