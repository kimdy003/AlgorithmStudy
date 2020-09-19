#include <iostream>
using namespace std;
int array[2][100000];
int dp[2][100000] = {0};

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T; cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        int n; cin >> n;

        for(int i=0; i<2; i++){
            for(int j=1; j<=n; j++){
                cin >> array[i][j];
            }
        }

        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = array[0][1];
        dp[1][1] = array[1][1];
        for(int j = 1; j <= n; j++){
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + array[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + array[1][j];
        }

        cout << max(dp[0][n], dp[1][n]) << "\n";
        
    }
}