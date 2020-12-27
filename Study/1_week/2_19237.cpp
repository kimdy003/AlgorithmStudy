#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 20;
using namespace std;

typedef struct _SHARK{
    int y;
    int x;
    int dir;
    bool live;
    vector<int> priority[5];
} SHARK;

typedef struct _INFO{
    int host;
    int time;
    vector<int> v;
} INFO;

int n, m, k;
INFO map[MAX][MAX];
SHARK shark[MAX*MAX];
//위 아래 왼쪽 오른쪽
pair<int, int> movdir[] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};


bool check(){
    for(int i=2; i<=m; i++){
        if(shark[i].live == true)
            return false;
    }
    return true;
}

void Smell(int time){
    for(int i=1; i<=m; i++){
        if(shark[i].live == false) continue;

        int y = shark[i].y;
        int x = shark[i].x;  
        map[y][x].host = i;
        map[y][x].time = time+k;
    }
}

void Move(int time){
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

        for(int d=0; d<shark[i].priority[dir].size(); d++){
            int ndir = shark[i].priority[dir][d];
            int ny = y + movdir[ndir].first;
            int nx = x + movdir[ndir].second;

            if(0 <= ny && ny < n && 0 <= nx && nx < n ){
                if(map[ny][nx].time <= time){
                    flag = true;
                    shark[i].y = ny;
                    shark[i].x = nx;
                    shark[i].dir = ndir;
                    map[ny][nx].v.push_back(i);
                    break;
                }
                else{
                    if(map[ny][nx].host == i && self_y == -1){
                        self_y = ny;
                        self_x = nx;
                        self_dir = ndir;
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

void Kill(){
    for(int i=1; i<=m; i++){
        if(shark[i].live == false) continue;

        int y = shark[i].y;
        int x = shark[i].x;

        if(map[y][x].v.size() >= 2){
            sort(map[y][x].v.begin(), map[y][x].v.end());
            int num = map[y][x].v[0];
            
            for(int j=1; j<map[y][x].v.size(); j++){
                int kill = map[y][x].v[j];
                shark[kill].live = false;
            }

            map[y][x].v.clear();
            map[y][x].v.push_back(num);
            map[y][x].host = num;
        }
    }
}

int main(){
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int a; cin >> a;
            if (a != 0){
                map[i][j].v.push_back(a);
                shark[a].y = i;
                shark[a].x = j;
            }

            map[i][j].host = 0;
            map[i][j].time = 0;
        }
    }

    for(int i = 1; i<=m; i++){
        cin >> shark[i].dir;
        shark[i].live = true;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=4; j++){
            int a[4];
            cin >> a[0] >> a[1] >> a[2] >> a[3];

            for(int d=0; d<4; d++){
                shark[i].priority[j].push_back(a[d]);
            }
        }
    }

    for(int t=0; t<1001; t++){
        if(check() == true){
            cout << t;
            return 0;
        }

        Smell(t);
        Move(t);
        Kill();
    }

    cout << -1;
}