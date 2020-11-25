#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

const int MAX = 100;
const int INF = 987654321;
using namespace std;

int r, c, n;
int order, dict;
char map[MAX][MAX];
bool visit[MAX][MAX];
bool cluster[MAX][MAX];

vector<pair<int, int>> air;

pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool Throw_Stick(int h, int d){
    if(d == 0){
        for(int i=0; i<c; i++){
            if(map[h][i] == 'x'){
                map[h][i] = '.';
                return true;
            }
        }
    }
    else{
        for(int i=c-1; i>= 0; i--){
            if(map[h][i] == 'x'){
                map[h][i] = '.';
                return true;
            }
        }
    }

    return false;
}


void BFS(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visit[a][b] = true;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if(map[ny][nx] == 'x' && visit[ny][nx] == false){
                visit[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}


bool Cluster_Air(){
    for(int i=0; i<c; i++){
        if(map[r-1][i] == 'x' && visit[r-1][i] == false){
            BFS(r-1, i);
        }
    }

    //공중 미네랄
    bool flag = false;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] == 'x' && visit[i][j] == false){
                //존재
                flag = true;
                air.push_back({i, j});
                cluster[i][j] = true;
            }
        }
    }

    return flag;
}

int Gravity(int y, int x){
    int cnt = 0;
    for(int i=y+1; i<r; i++){
        if(map[i][x] == 'x'){
            if(cluster[i][x] == true) return INF;
            else return cnt;
        }
        else if(map[i][x] == '.') cnt++;
    }
    return cnt;
}


void Remake_Map(){
    int H = INF -1;
    for(int i=0; i<air.size(); i++){
        int y = air[i].first;
        int x = air[i].second;

        int temp = Gravity(y, x);
        if(temp == INF) continue;
        else H = min(H, temp);
    }

    sort(air.begin(), air.end());
    for(int i=air.size()-1; i>=0; i--){
        int y = air[i].first;
        int x = air[i].second;

        map[y][x] = '.';
        map[y+H][x] = 'x';
    }
}


int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
        }
    }
    
    cin >> n;
    for(int i=0; i<n; i++){
        air.clear();
        memset(visit, false, sizeof(visit));
        memset(cluster, false, sizeof(cluster));

        cin >> order;
        int height = r - order;

        dict = i%2;

        if(Throw_Stick(height, dict) == false) continue;
        
        if(Cluster_Air() == false) continue;
        else Remake_Map();
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}