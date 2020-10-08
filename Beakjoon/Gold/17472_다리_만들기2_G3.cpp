#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1000;

int n, m, ans = 0;
int area_num;
int map[10][10];
int Dist[7][7];
int parent[7];

bool Visit[10][10];

vector<pair<int, int>> v[7];
vector<pair<int, pair<int, int>>> node;

pair<int, int> movdir[4] = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void Island(int a, int b, int cnt){
    queue<pair<int, int>> q;
    q.push({a, b});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx)
                continue;
            
            if(visit[ny][nx] == true && map[ny][nx] == 1){
                visit[ny][nx] = false;
                map[ny][nx] = cnt;
                v[cnt].push_back({ny, nx});
                q.push({ny, nx});
            }
        }
    }
}

void Lable_Island(){
    memset(visit, true, sizeof(visit));
    int cnt = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visit[i][j] && map[i][j] == 1){
                visit[i][j] = false;
                map[i][j] = cnt;
                v[cnt].push_back({i, j});
                Island(i, j, cnt++);
            }
        }
    }

    area_num = cnt;
}

void Distance(int y, int x, int dir, int size, int start, int end){
    int ny = y + movdir[dir].first;
    int nx = x + movdir[dir].second;

    if(map[ny][nx] == 0)
        Distance(ny, nx, dir, size+1, start, end);
    
    else if(map[ny][nx] == end){
        if(size > 1){
            if(Dist[start][end] > size){
                Dist[start][end] = size;
                Dist[end][start] = size;
            }
            return;
        }
    }
    return;
}

void Make_Bridge(int start, int end){
    for(int i=0; i<v[start].size(); i++){
        int y = v[start][i].first;
        int x = v[start][i].second;

        for(int j=0; j<4; j++){
            int nexty = y + movdir[j].first;
            int nextx = x + movdir[j].second;

            if(0<= nexty && nexty < n && 0 <= nextx && nextx <m){
                if(map[nexty][nextx] == 0){
                    Distance(y, x, j, 0, start, end);
                }
            }
        }
    }
}

int Find(int x){
    if(parent[x] == x)
        return x;

    return Find(parent[x]);
}

void Union(int x, int y){
    int px = Find(x);
    int py = Find(y);

    if(px != py){
        if(px < py){
            parent[y] = px;
        }
        else
            parent[x] = py;
    }
}

bool SameParent(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x != y)
        return false;
    return true;
}

void Min_Distance(){
    //시작섬의 모든 좌표에서 끝섬까지 갈 수 있는지 확인
    for(int i=1; i<=area_num; i++){
        for(int j=i+1; j<=area_num; j++){
            Make_Bridge(i, j);
            if(Dist[i][j] == INF)
                continue;
            node.push_back({Dist[i][j],{i, j}});
        }
    }

    sort(node.begin(), node.end());
    for(int i=1; i<area_num; i++){
        parent[i] = i;
    }

    for(int check = 1; check <=2; check++){
        for(int i=0; i<node.size(); i++){
            int node1 = node[i].second.first;
            int node2 = node[i].second.second;

            if(SameParent(node1, node2) == false){
                Union(node1, node2);
                if(check == 1)
                    ans = ans + node[i].first;
            }
        }
    }
}

bool check(){
    int x = parent[1];
    for(int i=2; i<area_num; i++){
        int y = Find(i);
        if(y != x)
            return false;
    }

    return true;
}

int main(){
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            Dist[i][j] = INF;
        }
    }

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    Lable_Island();
    Find_Distance();

    if(ans == 0){
        cout << -1 << "\n";
    }

    else{
        if(check() == true){
            cout << ans << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
}