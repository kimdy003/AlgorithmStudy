#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m, ans = 987654321;
int map[100][100];
bool check[100][100];
pair<int, int> movdir[4] = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

void bfs(int sy, int sx){
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    check[sy][sx] = false;
    int cnt = 1;

    while(!q.empty()){
        int size = q.size();
        cnt++;
        
        for(int cur = 0; cur<size; cur++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nexty = y + movdir[i].first;
                int nextx = x + movdir[i].second;

                if(nexty == n-1 && nextx == m-1){
                    ans = cnt;
                    return;
                }

                if(nexty < 0 || n <= nexty || nextx < 0 || m <= nextx) continue;
                if(map[nexty][nextx] == 0) continue;

                if(check[nexty][nextx]){
                    check[nexty][nextx] = false;
                    q.push({nexty, nextx});
                }
            }
        }
    }
}

int main(){
    memset(check, true, sizeof(check));
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j] - '0';
        }
    }

    
    bfs(0, 0);

    cout << ans;
}