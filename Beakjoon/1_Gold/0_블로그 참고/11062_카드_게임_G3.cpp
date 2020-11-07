#include <iostream>
#include <cstring>

using namespace std;

int n;
int dp[2][1001][1001];
int arr[1001];

int DFS(int turn, int left, int right){
    if(left == right){
        if(turn == 0){
            return arr[left];
        }
        else{
            return 0;
        }
    }

    int ret = dp[turn][left][right];
    if(ret != -1){
        return ret;
    }

    if(turn == 0){
        ret = max(DFS(1, left+1, right)+arr[left], DFS(1, left, right-1)+arr[right]);
    }
    else{
        ret = min(DFS(0, left+1, right), DFS(0, left, right-1));
    }
    
    return ret;
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int t; cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int ans = DFS(0, 0, n-1);
        cout << ans << "\n";
    }
}