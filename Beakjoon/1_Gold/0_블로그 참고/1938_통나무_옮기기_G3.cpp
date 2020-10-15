#include <iostream>
#include <queue>

const int MAX = 50;
using namespace std;

typedef struct _SETTING{
    int y;
    int x;
    int s;
    int c;
}SETTING;

int n;
int map[50][50] = {0};

bool visit[50][50][2];

int T_shape, E_shape;
pair<int, int> tree[3], End[3], T_center, E_center;
pair<int, int> movdir[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int Check_Shape(pair<int, int> s[3]){
    if(s[0].first == s[1].first && s[1].first == s[2].first)
        return 0;
    return 1;
}

bool Can_Change(int y, int x, int S){
    if(S == 0){
        for(int i=0; i<8; i++){
            if(i == 3 || i == 4) continue;

            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || n <= nx)
                return false;;
            if(map[ny][nx] == 1) return false;
        }
    }
    else if(S == 1){
        for(int i=0; i<8; i++){
            if(i == 1 || i == 6) continue;

            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || n <= nx)
                return false;
            if(map[ny][nx] == 1) return false;
        }
    }

    return true;
}

int BFS(int a, int b){
    queue<SETTING> q;
    q.push({a, b, T_shape, 0});
    visit[a][b][T_shape] = true;
    
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int shape = q.front().s;
        int cnt = q.front().c;
        q.pop();

        if(y == E_center.first && x == E_center.second && shape == E_shape){
            return cnt;
        }
        
        if(shape == 0){ //¤Ñ ¸ð¾ç
            //up 
            int ny = y - 1;
            int nx = x;
            if(ny >= 0 && 0 <= nx -1 && nx + 1 < n && visit[ny][nx][shape] == false){
                if(map[ny][nx] == 0 && map[ny][nx-1] == 0 && map[ny][nx+1] == 0){
                    visit[ny][nx][shape] = true;
                    q.push({ny, nx, shape, cnt+1});
                }
            }

            //down
            ny = y + 1;
            nx = x;
            if(ny < n && 0 <= nx-1 && nx+1 < n && visit[ny][nx][shape] == false){
                if(map[ny][nx] == 0 && map[ny][nx-1] == 0 && map[ny][nx+1] == 0){
                    visit[ny][nx][shape] = true;
                    q.push({ny, nx, shape, cnt+1});
                }
            }

            //left
            ny = y;
            nx = x -1;
            if(nx -1 >= 0 && visit[ny][nx][shape] == false){
                if(map[ny][nx-1] == 0){
                    visit[ny][nx][shape] = true;
                    q.push({ny, nx, shape, cnt+1});
                }
            }

            //right
            ny = y;
            nx = x +1;
            if(nx + 1 < n && visit[ny][nx][shape] == false){
                if(map[ny][nx+1] == 0){
                    visit[ny][nx][shape] = true;
                    q.push({ny, nx, shape, cnt+1});
                }
            }

            //turn
            if(Can_Change(y, x, shape) == true && visit[y][x][1] == false){
                visit[y][x][1] = true;
                q.push({y, x, 1, cnt+1});
            }
        }
        else{
            //up
            int ny = y -1;
            int nx = x;
            if(ny - 1 >= 0 && visit[ny][nx][shape] == false){
                if(map[ny-1][nx] == 0){
                    visit[ny][nx][shape] = true;
                    q.push({ny, nx, shape, cnt+1});
                }
            }

            //down
            ny = y + 1;
            nx = x;
            if(ny + 1 < n && visit[ny][nx][shape] == false){
                if(map[ny+1][nx] == 0){
                    visit[ny][nx][shape] = true;
                    q.push({ny, nx, shape, cnt+1});
                }
            }

            //left
            ny = y;
            nx = x -1;
            if(nx >= 0 && 0 <= ny-1 && ny+1 < n && visit[ny][nx][shape] == false){
                if(map[ny][nx] == 0 && map[ny-1][nx] == 0 && map[ny+1][nx] == 0){
                    visit[ny][nx][shape] = true;
                    q.push({ny, nx, shape, cnt+1});
                }
            }

            ny = y;
            nx = x + 1;
            if(nx < n && 0<= ny && nx <n && visit[ny][nx][shape] == false){
                if(map[ny][nx] == 0 && map[ny-1][nx] == 0 && map[ny+1][nx] == 0){
                    visit[ny][nx][shape] = true;
                    q.push({ny, nx, shape, cnt+1});
                }
            }

            //turn
            if(Can_Change(y, x, shape) == true && visit[y][x][0] == false){
                visit[y][x][0] = true;
                q.push({y, x, 0, cnt+1});
            }
        }
    }

    return 0;
}

int main(){
    cin >> n;
    char c;
    int s = 0, e = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c;
            if(c == 'B'){
                tree[s].first = i;
                tree[s++].second = j;
            }
            else if(c == 'E'){
                End[e].first = i;
                End[e++].second = j;
            }
            else if(c == '1'){
                map[i][j] = 1;
                continue;
            }
            map[i][j] = 0;
        }
    }
    T_center.first = tree[1].first;
    T_center.second = tree[1].second;
    E_center.first = End[1].first;
    E_center.second = End[1].second;

    T_shape = Check_Shape(tree);
    E_shape = Check_Shape(End);

    int ans = BFS(T_center.first, T_center.second);
    cout << ans;
}
