#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[25][25] = {0};
bool check[25][25] = {0};
pair<int, int> movdir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<int> v;

void bfs(int sy, int sx){
    queue<pair<int, int>> q;
    q.push({sy, sx});
    check[sy][sx] = false;
    int cnt = 1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nexty = y + movdir[i].first;
            int nextx = x + movdir[i].second;
            
            if(nexty < 0 || n <= nexty || nextx < 0 || n <= nextx) continue;
            if(map[nexty][nextx] == 0) continue;

            if(check[nexty][nextx] == true){
                check[nexty][nextx] = false;
                q.push({nexty, nextx});
                cnt++;
            }
        }
    }

    v.push_back(cnt);
}

int main(){
    memset(check, true, sizeof(check));
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            map[i][j] = s[j] - '0';
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 0) continue;
            if(check[i][j] == false) continue;

            bfs(i, j);
        }
    }

    sort(v.begin(), v.end());

    cout << v.size()-1 << "\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
}