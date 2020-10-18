#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

const int MAX = 50;
using namespace std;

typedef struct _STUFF{
    int y;
    int x;
    int cnt;
} STUFF;

int n, m, ans = 987654321;
char map[MAX][MAX];
bool visit[MAX][MAX];
bool Select[5];

vector<pair<int, int>> v, order;
pair<int, int> start, End;
pair<int, int> movdir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int BFS(int Sy, int Sx, int Ey, int Ex){
    memset(visit, false, sizeof(visit));
    queue<STUFF> q;
    q.push({Sy, Sx, 0});
    visit[Sy][Sx] = true;

    while (!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();

        if(y == Ey && x == Ex){
            return cnt;
        }

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || m <= nx)
                continue;

            if(map[ny][nx] == '.' && visit[ny][nx] == false){
                visit[ny][nx] = true;
                q.push({ny, nx, cnt+1});
            }
        }
    }
}

void Cal(){
    int Dist = BFS(start.first, start.second, order[0].first, order[0].second);
    for(int i=0; i<order.size()-1; i++){
        Dist += BFS(order[i].first, order[i].second, order[i+1].first, order[i+1].second);
    }
    Dist += BFS(order[order.size()-1].first, order[order.size()-1].second, End.first, End.second);
    ans = min(ans, Dist);
}

void DFS(int cnt){
    if(cnt == v.size()){
        Cal();
        return;
    }

    for(int i=0; i<v.size(); i++){
        if(Select[i] == false){
            Select[i] = true;
            order.push_back(v[i]);
            DFS(cnt+1);
            order.pop_back();
            Select[i] = false;
        }
    }   
}

int main(){
    cin >> n >> m;

    int idx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'S'){
                start.first = i;
                start.second = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'X'){
                v.push_back({i, j});
                map[i][j] = '.';
            }
            else if(map[i][j] == 'E'){
                End.first = i;
                End.second = j;
                map[i][j] = '.';
            }
        }
    }

    if(v.size() == 0){
        ans = BFS(start.first, start.second, End.first, End.second);
        cout << ans;
        return 0;
    }

    DFS(0);
    cout << ans;
}
