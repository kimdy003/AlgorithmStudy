#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

const int MAX = 21;
using namespace std;

typedef struct _TAXI{
    int y;
    int x;
    int fuel;
} TAXI;

typedef struct _PASSENGER{
    int sy;
    int sx;
    int ey;
    int ex;
    int dist;
} PASSENGER;

int n, m;
int map[MAX][MAX];
bool flag = true;

TAXI taxi;
vector<PASSENGER> passenger;
pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void all_print(){
    cout << "\n";
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int Distance(int sy, int sx, int ey, int ex){
    //승객이 목적지까지 갈 수 있는지 확인
    bool visit[MAX][MAX];
    memset(visit, true, sizeof(visit));

    queue<pair<int, int>> q;
    q.push({sy, sx});
    visit[sy][sx] = false;

    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        cnt += 1;

        for(int cur = 0; cur <size; cur++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int ny = y + movdir[i].first;
                int nx = x + movdir[i].second;

                if(ny <= 0 || n < ny || nx <= 0 || n < nx) continue;
                if(map[ny][nx] == -1) continue;
                if(visit[ny][nx] == false) continue;

                if(ny == ey && nx == ex){
                    return cnt;
                }

                visit[ny][nx] = false;
                q.push({ny, nx});
            }
        }
    }

    return 0;
}

void Taxi_Move(vector<pair<int, int>> point){
    sort(point.begin(), point.end());
    int y = point[0].first;
    int x = point[0].second;

    int ey = passenger[map[y][x]-1].ey;
    int ex = passenger[map[y][x]-1].ex;
    int dist = passenger[map[y][x]-1].dist;

    if(taxi.fuel >= dist){
        map[y][x] = 0;
        taxi.fuel += dist;
        taxi.y = ey;
        taxi.x = ex;
    }
    else{
        flag = false;
        return;
    }
}

void Driving(){
    //택시 위치에 승객이 존재하는 경우 (택시와 승객의 거리 = 0)
    if(map[taxi.y][taxi.x] > 0){
        int dist = passenger[map[taxi.y][taxi.x] -1].dist;
        if(taxi.fuel >= dist){
            taxi.fuel += dist;
            int num = map[taxi.y][taxi.x];
            map[taxi.y][taxi.x] = 0;

            taxi.y = passenger[num-1].ey;
            taxi.x = passenger[num-1].ex;
            return;
        }
        else{
            flag = false;
            return;
        }
    }

    // 택시와 승객의 거리가 떨어져있는경우
    bool visit[MAX][MAX];
    memset(visit, true, sizeof(visit));

    vector<pair<int, int>> passenger_point;
    queue<pair<int, int>> q;
    q.push({taxi.y, taxi.x});
    visit[taxi.y][taxi.x] = false;

    int dist = 0;
    while(!q.empty()){
        int size = q.size();
        dist += 1;

        for(int cur = 0; cur < size; cur++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int ny = y + movdir[i].first;
                int nx = x + movdir[i].second;

                if(ny <= 0 || n < ny || nx <= 0 || n < nx) continue;
                if(map[ny][nx] == -1) continue;
                if(taxi.fuel <= dist){
                    //가는 도중 연료가 떨어지는 경우
                    flag = false;
                    return;
                }
                if(visit[ny][nx] == true){
                    visit[ny][nx] = false;
                    if(map[ny][nx] > 0){
                        passenger_point.push_back({ny, nx});
                    }
                    else if (map[ny][nx] == 0){
                        q.push({ny, nx});
                    }
                }
            }
        }

        if(passenger_point.size() > 0){
            taxi.fuel -= dist;
            Taxi_Move(passenger_point);
            return;
        }
    }
    flag = false;
}

int main(){
    cin >> n >> m >> taxi.fuel;

    //0 : 빈칸, -1 : 벽 ( 1 -> -1 )
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1)
                map[i][j] = -1;
        }
    }

    cin >> taxi.y >> taxi.x;

    for(int i=0; i<m; i++){
        int a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        map[a[0]][a[1]] = i+1;
        int dist = Distance(a[0], a[1], a[2], a[3]);
        passenger.push_back({a[0], a[1], a[2], a[3], dist});
        if(dist == 0){
            flag = false;
        }
    }

    int cnt = 0;
    while(flag){
        if(cnt == m){
            cout << taxi.fuel;
            return 0;
        }

        //all_print();
        Driving();
        cnt += 1;
    }
    cout << -1;
    return 0;
}