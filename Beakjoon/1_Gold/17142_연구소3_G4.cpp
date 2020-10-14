#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n, m, emptyplace = 0;
vector<pair<int, int>> virus;
int map[50][50] = {0};
bool check[10];
pair<int, int> movdir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans = 987654321;
bool q_check[50][50];


void active_virus(){
    memset(q_check, false, sizeof(q_check));
    queue<pair<int, int>> q;
    int temp[50][50] = {0};
    int total = 0;
    int place = 0;

    for(int i=0; i<virus.size(); i++){
        if(check[i]){
            q.push({virus[i].first, virus[i].second});
            q_check[virus[i].first][virus[i].second] = true;
        }
    }

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nexty = y + movdir[i].first;
            int nextx = x + movdir[i].second;

            if(nexty < 0 || n <= nexty || nextx < 0 || n <= nextx)  continue;
            if(map[nexty][nextx] == 1) continue;
            if(q_check[nexty][nextx]) continue;


            temp[nexty][nextx] = temp[y][x] + 1;
            q_check[nexty][nextx] = true;
            if(map[nexty][nextx] == 0){
                place++;
                total = temp[nexty][nextx];
            }
            q.push({nexty, nextx});
        }        
    }

    if(emptyplace == place){
        ans = min(ans, total);
    }
}


void dfs(int idx, int cnt){
    if(cnt == m){
        active_virus();
        return;
    }

    for(int i=idx; i<virus.size(); i++){
        if(!check[i]){
            check[i] = true;
            dfs(i+1, cnt+1);
            check[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];

            if(map[i][j] == 0){
                emptyplace++;
            }
            else if(map[i][j] == 2){
                virus.push_back({i, j});
            }
        }
    }

    dfs(0, 0);

    if(ans == 987654321){
        cout << "-1";
    }
    else{
        cout << ans;
    }
}