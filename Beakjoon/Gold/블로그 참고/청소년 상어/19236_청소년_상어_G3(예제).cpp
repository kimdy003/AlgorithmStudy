#include <iostream>

using namespace std;
typedef struct _FISH{
    int y;
    int x;
    int dir;
    bool live;
} FISH;

int ans = 0;
int map[4][4];
FISH fish[17] = {0};
pair<int, int> mov[9] = {{0,0}, {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},
                                {0,1},{-1,1}};

void Copy_State(int a[][4], FISH f[], int t_a[][4], FISH t_f[]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            t_a[i][j] = a[i][j];
        }
    }

    for(int i=1; i<17; i++){
        t_f[i] = f[i];
    }
}

void Swap_Fish(int idx, int iidx){
    FISH temp = fish[idx];
    fish[idx].y = fish[iidx].y;
    fish[idx].x = fish[iidx].x;

    fish[iidx].y = temp.y;
    fish[iidx].x = temp.x;
}

void Move_Fish(){
    for(int i=1; i<17; i++){

        if(fish[i].live == false) continue;

        int y = fish[i].y;
        int x = fish[i].x;
        int dir = fish[i].dir;

        int ny = y + mov[dir].first;
        int nx = x + mov[dir].second;
        bool flag = false;
        if(0 <= ny && ny < 4 && 0 <= nx && nx <4){
            if(map[ny][nx] == 0){
                flag = true;
                fish[i].y = ny;
                fish[i].x = nx;
                map[ny][nx] = i;
                map[y][x] = 0;
            }
            else if(map[ny][nx] != -1){
                flag = true;
                Swap_Fish(i, map[ny][nx]);
                swap(map[y][x], map[ny][nx]);
            }
        }

        if(flag == false){
            int ndir = dir +1;
            if(ndir == 9) ndir = 1;
            int ny = y + mov[ndir].first;
            int nx = x + mov[ndir].second;

            while(ndir != dir){
                if(0 <= ny && ny <4 && 0 <= nx && nx <4){
                    if(map[ny][nx] == 0){
                        fish[i].y = ny;
                        fish[i].x = nx;
                        map[ny][nx] = i;
                        map[y][x] = 0;
                        fish[i].dir = ndir;
                        break;
                    }
                    else if(map[ny][nx] != -1){
                        Swap_Fish(i, map[ny][nx]);
                        swap(map[y][x], map[ny][nx]);
                        fish[i].dir = ndir;
                        break;
                    }
                }
                ndir++;
                if(ndir == 9) ndir = 1;
                ny = y+ mov[ndir].first;
                nx = x + mov[ndir].second;
            }
        }
    }
}

void Make_State(int y, int x, int ny, int nx, int num, bool flag){
    if(flag == true){
        map[y][x] = 0;
        map[ny][nx] = -1;
        fish[num].live = false;
    }
    else{
        map[y][x] = -1;
        map[ny][nx] = num;
        fish[num].live = true;
    }
}

void DFS(int y, int x, int dir, int eat){
    ans = max(ans, eat);

    int t_map[4][4];
    FISH t_fish[17] = {0};
    Copy_State(map, fish, t_map, t_fish);

    Move_Fish();

    for(int i=1; i<=3; i++){
        int ny = y + (mov[dir].first * i);
        int nx = x + (mov[dir].second * i);

        if(0 <= ny && ny <4 && 0 <= nx && nx <4){
            if(map[ny][nx] == 0) continue;

            int fish_num = map[ny][nx];
            int ndir = fish[fish_num].dir;

            Make_State(y, x, ny, nx, fish_num, true);
            DFS(ny, nx, ndir, eat+fish_num);
            Make_State(y, x, ny, nx, fish_num, false);
        }
        else break;
    }
    Copy_State(t_map, t_fish, map, fish);
}

int main(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int a, b;
            cin >> a >> b;
            map[i][j] = a;
            fish[a] = {i, j, b, true};
        }
    }

    int temp = map[0][0];
    int dir = fish[temp].dir;
    fish[temp].live = false;
    map[0][0] = -1;

    DFS(0, 0, dir, temp);
    cout << ans;
}