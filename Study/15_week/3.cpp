#include <iostream>
#include <vector>

const int MAX = 301;
using namespace std;

int n, m;
int lab[21][MAX];
int dp[21][MAX];
int path[21][MAX];

int main(){
    cin >> n;
    int a, b, c;
    for(int i=1; i<=n; i++){
        cin >> a;
        for(int j=1; j<=m; j++){
            cin >> lab[j][i];
        }
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<=j; k++){
                int val = dp[i-1][j-k] + lab[i][k];
                if(dp[i][j] < val){
                    dp[i][j] = val;
                    path[i][j] = k;
                }
            }
        }
    }

    cout << dp[m][n] << "\n";

    vector<int> ans;
    int cur = m, cost = n;
    while(cur > 0){
        int now = path[cur][cost];
        ans.push_back(now);

        cost -= now;
        cur--;
    }

    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }
}