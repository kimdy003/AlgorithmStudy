#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

const int INF = 1000;
using namespace std;

int n, m, ans = 0;
int area_num;
int map[10][10];
int Dist[7][7];
int parent[7];

bool visit[10][10];

vector<pair<int, int>> area[7];
vector<pair<int, pair<int, int>>> node;

pair<int, int> movdir[4] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void DFS(int y, int x, int dir, int size, int start, int end){
    int ny = y + movdir[dir].first;
    int nx = x + movdir[dir].second;

    if(ny < 0 || n <= ny || nx < 0 || m <= nx)
        return;
    
    if(map[ny][nx] == 0){
        DFS(ny, nx, dir, size+1, start, end);
    }
    else if(map[ny][nx] == end){
        if(size > 1){
            if(Dist[start][end] > size){
                Dist[start][end] = size;
                Dist[end][start] = size;
            }
        }
    }
    return;
}

void Make_Bridge(int start, int end){
    for(int i=0; i<area[start].size(); i++){
        int y = area[start][i].first;
        int x = area[start][i].second;

        for(int j=0; j<4; j++){
            int ny = y + movdir[j].first;
            int nx = x + movdir[j].second;

            if(0 <= ny && ny <n && 0 <= nx && nx < m){
                if(map[ny][nx] == 0){
                    DFS(y, x, j, 0, start, end);
                }
            }
        }
    }
}

int Find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a != b){
        if(a < b){
            parent[b] = a;
        }
        else
            parent[a] = b;
    }
}

bool SameParent(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x == y)
        return true;
    return false;
}

void Find_Distance(){
    for(int i=1; i<area_num; i++){
        for(int j=i+1; j<area_num; j++){
            Make_Bridge(i, j);
            if(Dist[i][j] == INF)
                continue;
            node.push_back({Dist[i][j], {i, j}});
        }
    }

    sort(node.begin(), node.end());
    for(int i=1; i<area_num; i++){
        parent[i] = i;
    }

    for(int cnt = 0; cnt <2; cnt++){
        for(int i=0; i<node.size(); i++){
            int cost = node[i].first;
            int a = node[i].second.first;
            int b = node[i].second.second;

            if(SameParent(a, b) == false){
                Union(a, b);
                if(cnt == 0){
                    ans += cost;
                }
            }
        }
    }
}

void Label(int a, int b, int cnt){
    queue<pair<int, int>> q;
    visit[a][b] = true;
    area[cnt].push_back({a, b});
    q.push({a, b});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i =0; i<4; i++){
            int nexty = y + movdir[i].first;
            int nextx = x + movdir[i].second;

            if(nexty < 0 || n <= nexty || nextx <0 || m <= nextx)
                continue;
            
            if(visit[nexty][nextx] == false && map[nexty][nextx] == 1){
                visit[nexty][nextx] = true;
                map[nexty][nextx] = cnt;
                area[cnt].push_back({nexty, nextx});
                q.push({nexty, nextx});
            }
        }
    }
}

void Label_Area(){
    int cnt = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && visit[i][j] == false){
                map[i][j] = cnt;
                Label(i, j, cnt++);
            }
        }
    }

    area_num = cnt;
}

bool check(){
    int pivot = parent[1];
    for(int i=2; i<area_num; i++){
        if(pivot != parent[i])
            return false;
    }
    return true;
}

int main(){
    cin >> n >> m;

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            Dist[i][j] = INF;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    Label_Area();
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