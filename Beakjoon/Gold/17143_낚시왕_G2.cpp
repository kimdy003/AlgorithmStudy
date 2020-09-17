#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _SHARK{
    int y;
    int x;
    int speed;
    int dir;
    int size;
    bool live;
} SHARK;

int R, C, M, ans = 0;
vector<int> map[101][101];
SHARK Shark[10000];
pair<int,int> movdir[5] = {{0,0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool cmp(int a, int b){
    return Shark[a].size > Shark[b].size;
}

int Inverse_Dir(int dir){
    if(dir == 1) return 2;
    else if(dir == 2) return 1;
    else if(dir == 3) return 4;
    return 3;
}

void Catch_Fisher(int Cur){
    for(int i = 1; i<=R; i++){
        if(!map[i][Cur].empty()){
            int Shark_num = map[i][Cur][0];
            ans += Shark[Shark_num].size;
            Shark[Shark_num].live = false;
            return;
        }
    }
}

void Move_Shark(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            map[i][j].clear();
        }
    }

    for(int i=0; i<M; i++){
        if(Shark[i].live == false) continue;

        int y = Shark[i].y;
        int x = Shark[i].x;
        int dir = Shark[i].dir;
        int speed = Shark[i].speed;
        if(dir == 1 || dir == 2){
            speed = speed %((R-1)*2);
        }
        else{
            speed = speed %((C-1)*2);
        }

        int ny = y, nx = x;
        while(1){
            if(speed == 0) break;

            ny = y + movdir[dir].first;
            nx = x + movdir[dir].second;

            if(0 < ny && ny <= R && 0 < nx && nx <= C){
                y = ny;
                x = nx;
                speed--;
            }
            else{
                dir = Inverse_Dir(dir);
            }
        }
        

        Shark[i].y = ny;
        Shark[i].x = nx;
        Shark[i].dir = dir;
        map[ny][nx].push_back(i);
    }
}

void Kill_Shark(){
    for(int i=1; i<= R; i++){
        for(int j=1; j<=C; j++){
            if(map[i][j].size() >= 2){
                sort(map[i][j].begin(), map[i][j].end(), cmp);
                for(int k=1; k<map[i][j].size(); k++){
                    int idx = map[i][j][k];
                    Shark[idx].live = false;
                }
            }
        }
    }

}


int main(){
    cin >> R >> C >> M;
    if(M == 0){
        cout << 0;
        return 0;
    }

    for(int i=0; i<M; i++){
        cin >> Shark[i].y >> Shark[i].x >> Shark[i].speed >> Shark[i].dir >> Shark[i].size;
        Shark[i].live = true;
        map[Shark[i].y][Shark[i].x].push_back(i);
    }

    for(int i=1; i<=C; i++){
        Catch_Fisher(i);
        if(i == C) break;
        
        Move_Shark();
        Kill_Shark();

    }

    cout << ans;
}