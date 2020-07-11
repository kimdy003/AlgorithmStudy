#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n, m;
vector<vector<int>> v;
bool check[11];
int ans;

void dfs(int node, int sum){
    check[node] = false;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next]){
            dfs(next, sum+1);
        }
    }

    check[node] = true;
    ans = max(ans, sum);
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        memset(check, false, sizeof(check));
        ans = 0;
        cin >> n >> m;
        v = vector<vector<int>>(n+1,vector<int>());
        for(int i=1; i<=n; i++){
            check[i] = true;
        }

        int x, y;
        for(int i=0; i<m; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int i=1; i<=n; i++){
            dfs(i,1);
        }
        cout << "#" << test <<" " << ans << "\n";

    }
}