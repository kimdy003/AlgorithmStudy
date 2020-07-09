#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int map[100][100];
int total[100][100];
bool check[100][100];
int n;
pair<int, int> dir[4] = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

void bfs(){
    queue<pair<int, int>> q;
    q.push({0,0});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nexty = y + dir[i].first;
            int nextx = x + dir[i].second;

            if(nexty < 0 || n <= nexty || nextx < 0 || n <= nextx)
                continue;

            if(check[nexty][nextx] || total[nexty][nextx] > total[y][x] + map[nexty][nextx]){
                check[nexty][nextx] = false;
                total[nexty][nextx] = total[y][x] + map[nexty][nextx];
                q.push({nexty, nextx});
            }
        }
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        memset(map, 0, sizeof(map));
        memset(check, true, sizeof(check));
        memset(total, 0, sizeof(total));
        cin >> n;
        string s;

        for(int i=0; i<n; i++){
            cin >> s;
            for(int j=0; j<n; j++){
                map[i][j] = s[j] - '0';
            }
        }

        check[0][0] = false;
        bfs();

        cout << "#" << test << " " << total[n-1][n-1] << "\n";
    }
}