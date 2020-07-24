#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> v;
bool check[101];
int n, m;

void dfs(int node){
    check[node] = false;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next]){
            dfs(next);
        }
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        cin >> n >> m;
        v = vector<vector<int>>(n+1, vector<int>());
        memset(check, true, sizeof(check));

        int x, y;
        for(int i=0; i<m; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(check[i]){
                cnt++;
                dfs(i);
            }
        }
        
        cout << "#" << test << " " << cnt << "\n";
    }
}