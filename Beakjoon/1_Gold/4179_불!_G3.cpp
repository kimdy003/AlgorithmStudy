#include <iostream>
#include <queue>
#include <vector>

const int MAX = 1000;
using namespace std;

int n, m, ans = 987654321;
char map[MAX][MAX];

bool flag = true;
bool visit[MAX][MAX];

pair<int, int> Jihoon;
queue<pair<int, int>> fire;
pair<int, int> movdir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void Move_Fire(){
    int size = fire.size();

    for(int cur = 0; cur<size; cur++){
        int y = fire.front().first;
        int x = fire.front().second;
        fire.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx)
                continue;
            
            if(map[ny][nx] == '.'){
                map[ny][nx] = 'F';
                fire.push({ny, nx});
            }
        }
    }
}

void BFS(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{Jihoon.first, Jihoon.second}, 0});
    visit[Jihoon.first][Jihoon.second] == true;

    while(!q.empty()){
        Move_Fire();
        int size = q.size();

        for(int cur = 0; cur < size; cur++){
            int y = q.front().first.first;
            int x = q.front().first.second;
            int time = q.front().second;
            q.pop();

            if(y == 0 || x == 0 || y == n-1 || x == m -1){
                ans = time+1;
                return;
            }
            
            for(int i = 0; i<4; i++){
                int ny = y + movdir[i].first;
                int nx = x + movdir[i].second;

                if(ny < 0 || n <= ny || nx < 0 || m <= nx)
                    continue;
                if(visit[ny][nx] == false && map[ny][nx] == '.'){
                    visit[ny][nx] = true;
                    q.push({{ny, nx}, time+1});
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'J'){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    cout << "1";
                    return 0;
                }

                Jihoon = {i, j};
                map[i][j] = '.';
            }
            else if(map[i][j] == 'F'){
                fire.push({i, j});
            }
        }
    }

    BFS();

    if(ans == 987654321)
        cout << "IMPOSSIBLE";
    else   
        cout << ans;
}