#include <iostream>
#include <vector>

const int MAX = 51;
using namespace std;

typedef struct _FIRE{
    int y;
    int x;
    int m; // 질량
    int s; // 속력
    int d; // 방향
    bool live;
} FIRE;

typedef struct _SUM{
    int m;
    int s;
    int all;
    bool flag;
} SUM;

int n, m, k;
vector<FIRE> FireBall;
vector<int> map[MAX][MAX];
pair<int, int> movdir[] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

// 파이어볼 이동_d방향으로 s만큼 이동 map에 위치
// 파이어볼 위치 갱신
void Move(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            map[i][j].clear();
        }
    }

    for(int i=0; i<FireBall.size(); i++){
        if(FireBall[i].live == false) continue;

        FIRE Cur = FireBall[i];

        Cur.s %= n;
        for(int t=0; t<Cur.s; t++){
            Cur.y += movdir[Cur.d].first;
            Cur.x += movdir[Cur.d].second;

            if(Cur.y <= 0){
                Cur.y = n;
            }
            
            if(n < Cur.y){
                Cur.y = 1;
            }

            if(Cur.x <= 0){
                Cur.x = n;
            }

            if(n < Cur.x){
                Cur.x = 1;
            }
        }

        map[Cur.y][Cur.x].push_back(i);
        FireBall[i].y = Cur.y;
        FireBall[i].x = Cur.x;
    }
}

/*
    1. map 확인 -> 2개 이상의 파이어볼 
    2. 하나로 합치기
    3. 4개로 나눠지기 (문제에 나와 있는 조건에 맞춰서)
    4. 파이어볼 이동
*/
void Calculation(){
    vector<FIRE> temp;
    for(int i=0; i<FireBall.size(); i++){
        if(FireBall[i].live == false) continue;

        int y = FireBall[i].y;
        int x = FireBall[i].x;

        if(map[y][x].size() >= 2){
            SUM Fire = {0,0,0,true};
            Fire.all = (FireBall[i].d % 2);
            for(int idx : map[y][x]){
                FireBall[idx].live = false;
                Fire.m += FireBall[idx].m;
                Fire.s += FireBall[idx].s;
                
                // 모두 홀수 or 짝수 검사 
                if(Fire.flag == true){
                    int d = FireBall[idx].d % 2;
                    if(Fire.all != d){
                        Fire.flag = false;  // 하나라도 아니면 홀수 방향으로 이동
                    }
                }
            }

            Fire.m /= 5;
            Fire.s /= map[y][x].size();
            if(Fire.m == 0) continue;

            int carry = 0;
            for(int i=0; i<8; i+=2){  //0, 2, 4, 6
                if(Fire.flag == false){
                    carry = 1;
                }

                int d = i + carry;
                temp.push_back({y, x, Fire.m, Fire.s, d, true});
            }
        }

        else{
            temp.push_back(FireBall[i]);
        }
    }

    FireBall.clear();
    for(int i=0; i<temp.size(); i++){
        FireBall.push_back(temp[i]);
    }
}

void Answer(){
    int ans = 0;
    for(int i=0; i<FireBall.size(); i++){
        if(FireBall[i].live == false) continue;
        ans += FireBall[i].m;
    }
    cout << ans;
}

int main(){
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        FIRE a;
        cin >> a.y >> a.x >> a.m >> a.s >> a.d;
        a.live = true;
        FireBall.push_back(a);
    }

    for(int i=0; i<k; i++){
        Move();
        Calculation();
    }

    Answer();
    return 0;
}