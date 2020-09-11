#include <iostream>
using namespace std;
int dp[1000001];

int main(){
    int temp = 0;

    dp[2] = 1;
    dp[3] = 1;
    for(int i=4; i<1000001; i++){
        dp[i] = dp[i-1] +1;

        if(i%2 == 0){
            temp = dp[i/2] + 1;
            if(dp[i] > temp)
                dp[i] = temp;
        }

        if(i%3 == 0){
            temp = dp[i/3] + 1;
            if(dp[i] > temp)
                dp[i] = temp;
        }
    }

    int n;
    cin >> n;
    cout << dp[n] << "\n";

}