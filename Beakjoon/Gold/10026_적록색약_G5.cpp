#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, cnt;
char map[100][100] = {0};
bool visit[100][100];
pair<int, int> movdir[4] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nexty = y + movdir[i].first;
            int nextx = x + movdir[i].second;

            if(nexty < 0 || n <= nexty || nextx < 0 || n <= nextx) continue;
            if(visit[nexty][nextx] == false) continue;

            if(map[nexty][nextx] == map[y][x]){
                visit[nexty][nextx] = false;
                q.push({nexty, nextx});
            }
        }
    }

}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    cnt = 0;
    memset(visit, true, sizeof(visit));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j] == true){
                visit[i][j] = false;
                BFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 'G')
                map[i][j] = 'R';
        }
    }

    cnt = 0;
    memset(visit, true, sizeof(visit));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j] == true){
                visit[i][j] = false;
                BFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
}