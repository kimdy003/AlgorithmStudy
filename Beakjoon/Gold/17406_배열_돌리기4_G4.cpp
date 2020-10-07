#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k, ans = 987654321;
int map[51][51] = {0};
vector<pair<pair<int, int>, int>> cycle;
bool check[6];
pair<int, int> movdir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void all_print(){
    cout << "\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void Make_Cycle(int idx, bool flag){
    int temp[51][51] = {0};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            temp[i][j] = map[i][j];
        }
    }

    //실행
    if(flag){
        int r = cycle[idx].first.first;
        int c = cycle[idx].first.second;
        int s = cycle[idx].second;

        while(1){
            int y = r - s;
            int x = c - s;

            if(y == r && x == c) break;

            for(int dir = 0; dir < 4; dir++){
                for(int i=0; i<2*s; i++){
                    int nexty = y + movdir[dir].first;
                    int nextx = x + movdir[dir].second;

                    temp[nexty][nextx] = map[y][x];
                    y = nexty;
                    x = nextx;
                }
            }
            s -= 1;
        }
    }
    //되돌리기
    else{
        int r = cycle[idx].first.first;
        int c = cycle[idx].first.second;
        int s = cycle[idx].second;

        while(1){
            int y = r - s;
            int x = c - s;

            if(y == r && x == c) break;

            for(int dir = 3; dir >= 0; dir--){
                for(int i=0; i<2*s; i++){
                    int nexty = y - movdir[dir].first;
                    int nextx = x - movdir[dir].second;

                    temp[nexty][nextx] = map[y][x];
                    y = nexty;
                    x = nextx;
                }
            }

            s -= 1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            map[i][j] = temp[i][j];
        }
    }
}

void Calculator(){
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=1; j<=m; j++){
            sum += map[i][j];
        }
        ans = min(ans, sum);
    }
}

void DFS(int cnt){
    if(cnt == k){
        Calculator();
        return;
    }

    for(int i=0; i<k; i++){
        if(check[i] == false) continue;
        check[i] = false;
        Make_Cycle(i, true);

        DFS(cnt+1);

        Make_Cycle(i, false);
        check[i] = true;
    }
}


int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<k; i++){
        int r, c, s;
        cin >> r >> c >> s;
        cycle.push_back({{r, c}, s});
    }

    memset(check, true, sizeof(check));
    DFS(0);

    cout << ans ;
}