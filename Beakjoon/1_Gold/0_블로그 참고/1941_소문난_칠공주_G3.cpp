#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int ans;
int map[5][5];
bool visit[25];

pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool Four(){
    int cnt = 0;
    for(int i=0; i<25; i++){
        if(visit[i] == false) continue;

        int y = i/5;
        int x = i%5;
        if(map[y][x] == 2) cnt++;
    }

    if(cnt >= 4) return true;
    
    return false;
}

bool More_Lee(){
    queue<pair<int, int>> q;
    bool Check[5][5];
    bool Queue[5][5];
    bool flag = false;

    memset(Check, false, sizeof(Check));
    memset(Queue, false, sizeof(Queue));

    for(int i=0; i<25; i++){
        if(visit[i] == true){
            int y = i/5;
            int x = i%5;
            Check[y][x] = true;

            if(q.empty()){
                q.push({y, x});
                Queue[y][x] = true;
            }
        }
    }

    int cnt = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(cnt == 7){
            flag = true;
            break;
        }

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || 5 <= ny || nx < 0 || 5 <= nx) continue;
            if(Check[ny][nx] == true && Queue[ny][nx] == false){
                Queue[ny][nx] = true;
                q.push({ny, nx});
                cnt++;
            }
        }
    }

    return flag;
}

void DFS(int idx, int cnt){
    if(cnt == 7){
        if(Four() == true && More_Lee() == true){
            ans++;
        }
        return;
    }

    for(int i=idx; i<25; i++){
        if(visit[i] == true) continue;
        visit[i] = true;
        DFS(i+1, cnt+1);
        visit[i] = false;
    }
}

int main(){
    for(int i=0; i<5; i++){
        string s; cin >> s;
        for(int j=0; j<5; j++){
            if(s[j] == 'Y') map[i][j] = 1;
            else if(s[j] == 'S') map[i][j] = 2;
        }
    }

    DFS(0, 0);
    cout << ans;
    
    return 0;
}