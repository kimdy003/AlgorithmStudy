#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int StartY, StartX;
char board[50][50];
bool visit[50][50];
bool flag;

pair<int, int> movdir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void DFS(int y, int x, int cnt){
    if(flag == true) return;

    for(int i=0; i<4 && !flag; i++){
        int ny = y + movdir[i].first;
        int nx = x + movdir[i].second;

        if(ny < 0 || n <= ny || nx < 0 || m <= nx)
            continue;
        if(board[ny][nx] != board[StartY][StartX])
            continue;

        if(visit[ny][nx] == false){
            visit[ny][nx] = true;
            DFS(ny, nx, cnt+1);
            visit[ny][nx] = false;
        }
        else{
            if(ny == StartY && nx == StartX && cnt >= 3){
                flag = true;
                return;
            }
        }
    }
}


int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    flag = false;
    for(int i=0; i<n && !flag; i++){
        for(int j=0; j<m && !flag; j++){
            memset(visit, false, sizeof(visit));
            visit[i][j] = true;
            StartY = i;
            StartX = j;
            DFS(i, j, 0);
        }
    }

    if(flag){
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }
}