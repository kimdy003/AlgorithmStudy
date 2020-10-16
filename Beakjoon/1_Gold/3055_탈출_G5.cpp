#include <iostream>
#include <queue>

using namespace std;

int n, m, ans = 987654321;
char map[50][50];
bool visit[50][50];

queue<pair<int, int>> water;
pair<int, int> Start;
pair<int, int> movdir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void Move_Water(){
    if(!water.empty()){
        int size = water.size();

        for(int cur = 0; cur<size; cur++){
            int y = water.front().first;
            int x = water.front().second;
            water.pop();

            for(int i=0; i<4; i++){
                int ny = y + movdir[i].first;
                int nx = x + movdir[i].second;

                if(ny < 0 || n <= ny || nx < 0 || m <= nx)
                    continue;
                
                if(map[ny][nx] == '.'){
                    map[ny][nx] = '*';
                    water.push({ny, nx});
                }
            }
        }
    }
}

void BFS(){
    queue<pair<int, int>> q;
    q.push({Start.first, Start.second});
    visit[Start.first][Start.second] = true;

    int cnt = 1;
    while(!q.empty()){
        int size = q.size();

        for(int cur = 0; cur < size; cur++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int ny = y + movdir[i].first;
                int nx = x + movdir[i].second;
                
                if(ny < 0 || n <= ny || nx < 0 || m <= nx)
                    continue;

                if(map[ny][nx] == 'D'){
                    ans = cnt;
                    return;
                }

                if(visit[ny][nx] == true)
                    continue;

                if(map[ny][nx] == '.'){
                    visit[ny][nx] = true;

                    bool flag = true;
                    for(int dir = 0; dir<4; dir++){
                        int nny = ny + movdir[dir].first;
                        int nnx = nx + movdir[dir].second;

                        if(nny < 0 || n <= nny || nnx < 0 || m <= nnx)
                            continue;
                        
                        if(map[nny][nnx] == '*'){
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        q.push({ny, nx});
                }
            }
        }
        cnt++;
        Move_Water();
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'S'){
                Start.first = i;
                Start.second = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == '*'){
                water.push({i, j});
            }
        }
    }

    BFS();
    if(ans == 987654321 || ans == 0)
        cout << "KAKTUS";
    else
        cout << ans;
}