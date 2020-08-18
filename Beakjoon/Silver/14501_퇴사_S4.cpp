#include <iostream>
using namespace std;
int n;
pair<int, int> data[16];
int dp[16] = {0};
int ans = 0;

int main(){
    cin >> n;
    int t, p;
    for(int i=0; i<n; i++){
        cin >> t >> p;
        data[i].first = t;
        data[i].second = p;
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] = max(dp[i], dp[j]);

            if(j+data[j].first == i){
                dp[i] = max(dp[i], dp[j] + data[j].second);
            }
        }
    }

    for(int i=0; i<=n; i++)
        ans = max(ans, dp[i]);

    cout << ans <<"\n";

    return 0;
    
}