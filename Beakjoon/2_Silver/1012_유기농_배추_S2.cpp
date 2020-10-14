#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, k, ans;
int map[51][51];
bool visit[51][51];
pair<int, int> movdir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if(map[ny][nx] == 0) continue;

            if(visit[ny][nx]){
                visit[ny][nx] = false;
                q.push({ny, nx});
            }
        }

    }
}

int main(){
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        memset(visit, true, sizeof(visit));
        memset(map, 0, sizeof(map));
        cin >> m >> n >> k;
        
        int x, y;
        for(int i=0; i<k; i++){
            cin >> x >> y;
            map[y][x] = 1;
        }

        ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visit[i][j] == true && map[i][j] == 1){
                    visit[i][j] = false;
                    BFS(i, j);
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }

}