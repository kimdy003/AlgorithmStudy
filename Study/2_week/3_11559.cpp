#include <iostream>
#include <cstring>
#include <queue>

const int n = 12, m = 6;
using namespace std;


char map[n][m];
bool visit[n][m];
bool flag;
pair<int, int> movdir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }
}

void BFS(int a, int b){
    queue<pair<int, int>> q;
    queue<pair<int, int>> save;
    q.push({a, b});
    save.push({a, b});

    char stand = map[a][b];
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if(visit[ny][nx] == true && map[ny][nx] == stand){
                visit[ny][nx] = false;
                q.push({ny, nx});
                save.push({ny, nx});
            }
        }
    }

    if(save.size() >= 4){
        while(!save.empty()){
            int y = save.front().first;
            int x = save.front().second;
            save.pop();

            map[y][x] = '.';
        }
        flag = true;
    }
}

bool Boom(){
    flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == '.') continue;
            if(visit[i][j] == true){
                visit[i][j] = false;
                BFS(i, j);
            }
        }
    }

    return flag;
}

void Gravity(){
    for(int j=0; j<m; j++){
        int idx = n-1;
        for(int i = n-1; i>=0; i--){
            if(map[i][j] == '.') continue;
            if(idx != i){
                map[idx][j] = map[i][j];
                map[i][j] = '.';
            }
            idx--;
        }
        
    }
}

int main(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    while(1){
        memset(visit, true, sizeof(visit));
        if(Boom() == false)
            break;
        Gravity();
        cnt++;
    }

    cout << cnt;
}