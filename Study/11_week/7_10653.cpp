#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

const int MAX = 500;
using namespace std;

int n, k;
vector<pair<int, int>> pos;
int dis[MAX][MAX];
int dp[MAX][MAX];

int Solve(int idx, int k){
    if(idx == 1) return 0;
    if(dp[idx][k] != -1) return dp[idx][k];

    int Min = 1e9;
    for(int i=0; i<=k; i++){
        if(idx-i-1 < 1) break;    // 첫번째 체크포인터는 무조건 밟아야되기 때문에
        int ii = dis[idx-i-1][idx];
        Min = min(Solve(idx-i-1, k-i) + dis[idx-i-1][idx], Min);
    }

    return dp[idx][k] = Min;
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        pos.push_back({a, b});
    }
    
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            dis[i+1][j+1] = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
        }
    }

    cout << Solve(n, k);
}