#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

const int MAX = 1001;
using namespace std;

int n, m, k, ans = 987654321;
int map[MAX][MAX];
bool visit[MAX][MAX][11];

pair<int, int> movdir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


void BFS(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{1, 1}, {1, 0}});
    visit[1][1][0] = true;

    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second.first;
        int wall = q.front().second.second;
        q.pop();

        if(y == n && x == m){
            cout << cnt;
            return;
        }

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny <= 0 || n < ny || nx <= 0 || m < nx) continue;
            if(map[ny][nx] == 0 && visit[ny][nx][wall] == false){
                visit[ny][nx][wall] = true;
                q.push({{ny, nx}, {cnt+1, wall}});
            }
            else if(map[ny][nx] == 1){
                if(wall < k && visit[ny][nx][wall+1] == false){
                    visit[ny][nx][wall+1] = true;
                    q.push({{ny, nx}, {cnt+1, wall+1}});
                }
            }
        }
    }

    cout << -1;
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++){
            map[i][j+1] = s[j]-'0';
        }
    }

    BFS();
}