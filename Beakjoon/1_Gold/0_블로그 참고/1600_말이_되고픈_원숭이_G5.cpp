#include <iostream>
#include <queue>

const int MAX = 200;
using namespace std;

typedef struct _MONKEY{
    int y;
    int x;
    int c;
    int h;
}MONKEY;

int k, n, m;
int map[MAX][MAX];

//[y][x][z] = (y, x)좌표까지 horse 움직임을 z번 사용
bool visit[MAX][MAX][31];

MONKEY monkey;
pair<int, int> movdir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pair<int, int> h_mov[8] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

void BFS(){
    queue<MONKEY> q;
    q.push({0, 0, 0, 0});
    visit[0][0][0] = true;

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().c;
        int h_cnt = q.front().h;
        q.pop();

        if(y == n-1 && x == m-1){
            cout << cnt;
            return;
        }

        if(h_cnt <= k){
            for(int i=0; i<8; i++){
                int ny = y + h_mov[i].first;
                int nx = x + h_mov[i].second;

                if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
                if(map[ny][nx] == 1) continue;

                if(visit[ny][nx][h_cnt+1] == false){
                    visit[ny][nx][h_cnt+1] = true;
                    q.push({ny, nx, cnt+1, h_cnt+1});
                }
            }
        }

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if(map[ny][nx] == 1) continue;

            if(visit[ny][nx][h_cnt] == false){
                visit[ny][nx][h_cnt] = true;
                q.push({ny, nx, cnt+1, h_cnt});
            }
        }
    }

    cout << -1;
}

int main(){
    cin >> k >> m >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    
    BFS();
}