#include <iostream>
#include <cstring>
#include <queue>

const int MAX = 100;
using namespace std;

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];

pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout <<map[i][j] << " ";
        }
        cout << "\n";
    }
}

bool Check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1)
                return false;
        }
    }

    return true;
}

void Del(){
    memset(visit, true, sizeof(visit));

    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = false;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx)
                continue;
            
            if(visit[ny][nx] == true){
                visit[ny][nx] = false;
                if(map[ny][nx] == 0){
                    q.push({ny, nx});
                }
                else if(map[ny][nx] == 1){
                    map[ny][nx] = 0;
                }
            }
        }
    }
}

int Piece(){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    int time = 0;
    int ret = 0;
    while (1){
        if(Check() == true){
            break;
        }

        ret = Piece();
        Del();
        time++;
    }

    cout << time << "\n" << ret;
}