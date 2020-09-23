#include <iostream>
#include <queue>
using namespace std;
int n, ans = 0;
int map[17][17] = {0};
queue<pair<pair<int, int>, int>>  pipe;
pair<int, int> movdir[3] = {{0,1}, {1,0}, {1, 1}};

void BFS(){
    while(!pipe.empty()){
        int y = pipe.front().first.first;
        int x = pipe.front().first.second;
        int dir = pipe.front().second;
        pipe.pop();

        if(y == n && x == n){
            ans++;
            continue;
        }

        if(dir == 0){
            int nexty = y + movdir[dir].first;
            int nextx = x + movdir[dir].second;
            if(0 < nexty && nexty <= n && 0 < nextx && nextx <= n){
                if(map[nexty][nextx] == 0)
                    pipe.push({{nexty, nextx}, dir});
            }

            nexty = y + movdir[2].first;
            nextx = x + movdir[2].second;
            if(0 < nexty && nexty <= n && 0 < nextx && nextx <= n){
                if(map[y+1][x] == 0 && map[y][x+1] == 0 && map[nexty][nextx] == 0){
                    pipe.push({{nexty, nextx}, 2});
                }
            }
        }
        else if(dir == 1){
            int nexty = y + movdir[dir].first;
            int nextx = x + movdir[dir].second;
            if(0 < nexty && nexty <= n && 0 < nextx && nextx <= n){
                if(map[nexty][nextx] == 0)
                    pipe.push({{nexty, nextx}, dir});
            }

            nexty = y + movdir[2].first;
            nextx = x + movdir[2].second;
            if(0 < nexty && nexty <= n && 0 < nextx && nextx <= n){
                if(map[y+1][x] == 0 && map[y][x+1] == 0 && map[nexty][nextx] == 0){
                    if(map[nexty][nextx] == 0)
                        pipe.push({{nexty, nextx}, 2});
                }
            }
        }
        else if(dir == 2){
            int nexty = y + movdir[2].first;
            int nextx = x + movdir[2].second;
            if(0 < nexty && nexty <= n && 0 < nextx && nextx <= n){
                if(map[y+1][x] == 0 && map[y][x+1] == 0 && map[nexty][nextx] == 0){
                    pipe.push({{nexty, nextx}, dir});
                }
            }

            for(int i=0; i<2; i++){
                nexty = y + movdir[i].first;
                nextx = x + movdir[i].second;
                if(0 < nexty && nexty <= n && 0 < nextx && nextx <= n){
                    if(map[nexty][nextx] == 0)
                        pipe.push({{nexty, nextx}, i});
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    pipe.push({{1, 2}, 0});
    BFS();
    cout << ans;
}