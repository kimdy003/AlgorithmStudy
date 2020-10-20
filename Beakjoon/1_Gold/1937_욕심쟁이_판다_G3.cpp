#include <iostream>
#include <vector>

const int MAX = 500;
using namespace std;

int n, ans = 0;
int map[MAX][MAX];
int dp[MAX][MAX] = {0};
bool visit[MAX][MAX];

pair<int, int> movdir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int DFS(int y, int x){
    if(dp[y][x] != 0){
        return dp[y][x];
    }
    dp[y][x] = 1;

    for(int i=0; i<4; i++){
        int ny = y + movdir[i].first;
        int nx = x + movdir[i].second;

        if(ny < 0 || n <= ny || nx < 0 || n <= nx)
            continue;
        
        if(visit[ny][nx] == false){
            if(map[y][x] < map[ny][nx]){
                visit[ny][nx] = true;
                dp[y][x] = max(dp[y][x], DFS(ny, nx)+1);
                visit[ny][nx] = false;
            }
        }
    }

    return dp[y][x];
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visit[i][j] = true;
            ans = max(ans, DFS(i, j));
            visit[i][j] = false;
        }
    }
    
    cout << ans;
}