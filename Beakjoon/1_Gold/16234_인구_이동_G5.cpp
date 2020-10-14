#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int n, l, r, ans = 0;
bool flag = true;
int map[50][50] = {0};
queue<pair<int, int>> moving;
int check[50][50];
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void all_printf(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs(int group){
    int cnt = 1;
    int people = map[moving.front().first][moving.front().second];

    while(!moving.empty()){
        int y = moving.front().first;
        int x = moving.front().second;
        check[y][x] = group;
        moving.pop();

        for(int i=0; i<4; i++){
            int nexty = y + dir[i].first;
            int nextx = x + dir[i].second;

            if(nexty <0 || n <= nexty || nextx < 0 || n <= nextx)
                continue;
            if(check[nexty][nextx] == 0){
                int sub = abs(map[y][x] - map[nexty][nextx]);
                if( l <= sub && sub <= r){
                    check[nexty][nextx] = group;
                    moving.push({nexty, nextx});
                    people += map[nexty][nextx];
                    cnt++;
                }
            }
        }
    }

    if(cnt == 1){
        return;
    }

    int change = people/cnt;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == group)
                map[i][j] = change;
        }
    }
    flag = true;
}

int main(){
    cin >> n >> l >> r;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    while(flag){
        memset(check, 0, sizeof(check));
        flag = false;
        int group = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check[i][j] == 0){
                    moving.push({i, j});
                    bfs(group++);
                }
                if(!flag){
                    check[i][j] = -1;
                    group--;
                }
            }
        }
        
        if(flag){
            ans++;
        }
        //all_printf();
    }

    cout << ans ;
}