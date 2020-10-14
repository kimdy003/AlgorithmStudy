#include <iostream>
using namespace std;
long long dp[91] = {0};

long long function(int n){
    if(n <= 1){
        return n;
    }
    else{
        if(dp[n] > 0){
            return dp[n];
        }

        dp[n] = function(n-1) + function(n-2);
        return dp[n];
    }
}

int main(){
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;

    cout << function(n);

}
