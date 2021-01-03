#include <iostream>
#include <queue>

const int MAX = 20;
using namespace std;

int n, m, ans = 0;
char map[MAX][MAX];
int alpha[26] = {0};

pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void DFS(int y, int x, int cnt){
    ans = max(ans, cnt);

    for(int i=0; i<4; i++){
        int ny = y + movdir[i].first;
        int nx = x + movdir[i].second;

        if(ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
        if(alpha[map[ny][nx] - 'A'] == 0){
            alpha[map[ny][nx] - 'A'] = 1;
            DFS(ny, nx, cnt+1);

            alpha[map[ny][nx] - 'A'] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    alpha[map[0][0] - 'A'] = 1;
    DFS(0, 0, 1);
    cout << ans;
}