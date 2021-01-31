#include <iostream>

using namespace std;

int dp[1001][1001];

int main(){
    int ans = 0;
    string str1, str2;
    cin >> str1 >> str2;

    for(int i=1; i<=str1.length(); i++){
        for(int j=1; j<=str2.length(); j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            ans = max(ans, dp[i][j])
        }
    }

    cout << ans;
}