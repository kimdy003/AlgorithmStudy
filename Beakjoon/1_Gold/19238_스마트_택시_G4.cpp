#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct _Taxi{
    int y;
    int x;
    int oil;
}Taxi;

typedef struct _Customer{
    int y;
    int x;
    int arry;
    int arrx;
    int distance;
}Customer;

typedef struct _INFO{
    int y;
    int x;
    int idx;
}INFO;

Taxi taxi;
Customer customer[401];
int n, m, li;
int map[21][21] = {0};
bool check[21][21];
bool flag = true;
vector<INFO> now_pass;
pair<int, int> movdir[4] = {{0,1}, {1,0}, {0,-1},{-1,0}};

bool cmp(INFO a, INFO b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}


void move(int use_fuel){
    taxi.oil -= use_fuel;

    sort(now_pass.begin(), now_pass.end(), cmp);

    //(2) 택시가 가는 도중 연로가 바닥나는 경우
    if(taxi.oil < customer[now_pass[0].idx].distance){
        flag = false;
        return;
    }
    else{
        map[customer[now_pass[0].idx].y][customer[now_pass[0].idx].x] = 0;
        taxi.oil += customer[now_pass[0].idx].distance;
        taxi.y = customer[now_pass[0].idx].arry;
        taxi.x = customer[now_pass[0].idx].arrx;
        now_pass.clear();
    }
    
}


void driving(){
    queue<pair<int, int>> q;
    q.push({taxi.y, taxi.x});
    check[taxi.y][taxi.x] = false;
    int cnt = 0;
    
    //(1) 택시가 있는 곳에 손님이 존재하는 경우
    if(map[taxi.y][taxi.x] > 0){
        now_pass.push_back({taxi.y, taxi.x, map[taxi.y][taxi.x]-1});
        if(taxi.oil <= cnt){
            flag = false;
            return;
        }
        move(0);
        return;
    }

    while(!q.empty()){
        int currentsize = q.size();
        cnt++;

        for(int current=0; current<currentsize; current++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nexty = y + movdir[i].first;
                int nextx = x + movdir[i].second;

                if(nexty <= 0 || n < nexty || nextx <= 0|| n < nextx) continue;
                if(map[nexty][nextx] == -1 ) continue;
                if(!check[nexty][nextx]) continue;

                if(map[nexty][nextx] > 0){
                    now_pass.push_back({nexty, nextx, map[nexty][nextx]-1});
                    //(2) 택시가 가는 도중 연로가 바닥나는 경우
                    if(taxi.oil <= cnt){
                        flag = false;
                        return;
                    }
                }

                check[nexty][nextx] = false;
                q.push({nexty, nextx});
            }
        }
        
        //(2) 손님을 찾을 경우
        if(!now_pass.empty()){
            move(cnt);
            return;
        }
    }
    //(3) 택시가 움직이지를 못하거나, 손님을 찾지 못하는 경우
    flag = false;
}

void passenger_distance(int idx){
    queue<pair<int, int>> pass;
    pass.push({customer[idx].y, customer[idx].x});
    check[customer[idx].y][customer[idx].x] = false;
    int cnt = 0;

    while(!pass.empty()){
        int size = pass.size();
        cnt++;

        for(int cur = 0; cur <size; cur++){
            int y = pass.front().first;
            int x = pass.front().second;
            pass.pop();

            for(int i=0; i<4; i++){
                int nexty = y + movdir[i].first;
                int nextx = x + movdir[i].second;

                if(nexty <= 0 || n < nexty || nextx <= 0|| n < nextx) continue;
                if(map[nexty][nextx] == -1 ) continue;
                if(!check[nexty][nextx]) continue;

                if(nexty == customer[idx].arry && nextx == customer[idx].arrx){
                    customer[idx].distance = cnt;
                    return;
                }

                check[nexty][nextx] = false;
                pass.push({nexty, nextx});
            }
        }
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n >> m >> li;
    taxi.oil = li;
    for(int i=1; i<=n; i++){
        for(int j= 1; j<=n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1)
                map[i][j] = -1;
        }
    }

    cin >> taxi.y >> taxi.x;

    //1. 손님의 정보를 저장 및 출발지에서 도착지까지의 거리
    for(int i=0; i<m; i++){
        memset(check, true, sizeof(check));
        cin >> customer[i].y >> customer[i].x >> customer[i].arry >> customer[i].arrx;
        map[customer[i].y][customer[i].x] = i+1;
        passenger_distance(i);
        //(1) 손님이 출발지에서 도착지로 못 가는 경우 ( 벽에 막혀서)
        if(customer[i].distance == 0){
            flag = false;
        }
    }

    //2. 택시의 위치에서 가장 가까운 손님까지의 위치 및 연료 계산
    int count = 0;
    while(flag){
        if(count == m) break;

        flag = true;
        memset(check, true, sizeof(check));
        driving();
        if(flag){
            count++;
        }
    }

    if(flag)
        cout << taxi.oil;
    else{
        cout << "-1";
    }

}