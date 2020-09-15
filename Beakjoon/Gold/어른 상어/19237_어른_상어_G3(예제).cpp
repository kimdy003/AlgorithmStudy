#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct _SHARK{
    int y;
    int x;
    int dir;
    bool live;
    vector<int> priority[5];
} SHARK;

typedef struct _INFO{
    vector<int> v;
    int t;
    int host;
} INFO;

int n, m, k;
INFO map[20][20];
SHARK shark[401];
pair<int, int> mov[5] {{0,0}, {-1,0}, {1,0},{0, -1}, {0, 1}};

bool check(){
    for(int i=2; i<=m; i++){
        if (shark[i].live == true) return false;
    }
    return true;
}

void Smell(int time){
    for(int i=1; i<=m; i++){
        if(shark[i].live == false) continue;

        int y = shark[i].y;
        int x = shark[i].x;
        map[y][x].t = time + k;
        map[y][x].host = i;
    }
}

void Move_Shark(int time){
    for(int i=1; i<=m; i++){
        if(shark[i].live == false) continue;
        int y = shark[i].y;
        int x = shark[i].x;
        map[y][x].v.clear();
    }

    for(int i=1; i<=m; i++){
        if(shark[i].live == false) continue;

        int y = shark[i].y;
        int x = shark[i].x;
        int dir = shark[i].dir;
        int self_y, self_x, self_dir;
        self_y = self_x = self_dir = -1;
        bool flag = false;

        for(int j=0; j<shark[i].priority[dir].size(); j++){
            int ndir = shark[i].priority[dir][j];
            int ny = y + mov[ndir].first;
            int nx = x + mov[ndir].second;
            if(0 <= ny && ny <n && 0 <= nx && nx <n){
                if(map[ny][nx].t <= time){
                    flag = true;
                    map[ny][nx].v.push_back(i);
                    shark[i].y = ny;
                    shark[i].x = nx;
                    shark[i].dir = ndir;
                    break;
                }
                else{
                    if(map[ny][nx].host == i){
                        if(self_y == -1){
                            self_y = ny;
                            self_x = nx;
                            self_dir = ndir;
                        }
                    }
                }
            }
        }
        if(flag == false){
            map[self_y][self_x].v.push_back(i);
            shark[i].y = self_y;
            shark[i].x = self_x;
            shark[i].dir = self_dir;
        }

    }
}

void Kill_Shark(){
    for(int i=1; i<=m; i++){
        if(shark[i].live == false) continue;

        int y = shark[i].y;
        int x = shark[i].x;
        if(map[y][x].v.size() >= 2){
            sort(map[y][x].v.begin(), map[y][x].v.end());
            int live_num = map[y][x].v[0];
            for(int j=1; j<map[y][x].v.size(); j++){
                int shark_num = map[y][x].v[j];
                shark[shark_num].live = false;
            }
            map[y][x].v.clear();
            map[y][x].v.push_back(live_num);
            map[y][x].host = live_num;
        }
    }
}

int main(){
    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a; 
            cin >> a;
            if(a != 0){
                map[i][j].v.push_back(a);
                shark[a].y = i;
                shark[a].x = j;
            }
            map[i][j].t = 0;
            map[i][j].host = 0;
        }
    }

    for(int i=1; i<=m; i++){
        cin >> shark[i].dir;
        shark[i].live = true;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=4; j++){
            int arr[4];
            cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
            for(int k=0; k<4; k++){
                shark[i].priority[j].push_back(arr[k]);
            }
        }
    }

    for(int Time=0; Time <1001; Time++){
        if(check() == true){
            cout << Time;
            return 0;
        }
        Smell(Time);
        Move_Shark(Time);
        Kill_Shark();
    }
    cout << -1;
}