#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct _ENEMY{
    int y;
    int x;
    int dist;
} ENEMY;

int n, m, d, ans, result;
int map[15][15] = {0};
int c_map[15][15] = {0};
bool visit[15][15];
bool Choice[15];
vector<pair<int, int>> v;
vector<int> Archer;

void Copy_Map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            c_map[i][j] = map[i][j];
        }
    }
}

void all_print()
{
    cout << "\n" ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << c_map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool check(){
    bool flag = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(c_map[i][j] == 1){
                v.push_back({i, j});
                flag = false;
            }
        }
    }
    return flag;
}

int Dist(int y, int x, int yy, int xx){
    return abs(x - xx) + abs(y - yy);
}

bool cmp(ENEMY A, ENEMY B){
    if(A.dist == B.dist){
        return A.x < B.x;
    }
    return A.dist < B.dist;
}

void Shot(){
    pair<int, int> target[3];

    for(int i=0; i<Archer.size(); i++){
        int y = n;
        int x = Archer[i];
        vector<ENEMY> attack_Enemy;

        for(int j=0; j<v.size(); j++){
            int yy = v[j].first;
            int xx = v[j].second;
            int distance = Dist(y, x, yy, xx);

            if(distance <= d){
                attack_Enemy.push_back({yy, xx, distance});
            }
        }

        int kill_num = attack_Enemy.size();
        if(kill_num == 1){
            target[i].first = attack_Enemy[0].y;
            target[i].second = attack_Enemy[0].x;
        }
        else if(kill_num > 1){
            sort(attack_Enemy.begin(), attack_Enemy.end(), cmp);
            target[i].first = attack_Enemy[0].y;
            target[i].second = attack_Enemy[0].x;
        }
        else{
            target[i].first = -1;
            target[i].second = -1;
        }
    }

    for(int i=0; i<3; i++){
        int y = target[i].first;
        int x = target[i].second;

        if(y == -1 && x == -1) continue;
        if(visit[y][x] == false){
            visit[y][x] = true;
            c_map[y][x] = 0;
            result++;
        }
    }
}

void Move_Enemy(){
    for(int i=v.size() -1; i>=0; i--){
        int y = v[i].first;
        int x = v[i].second;

        if(c_map[y][x] == 0) continue;
        if(y == n-1){
            c_map[y][x] = 0;
        }
        else{
            c_map[y][x] = 0;
            c_map[y+1][x] = 1;
        }
    }
}

void Calculate(){
    Copy_Map();
    while(1){
        v.clear();
        memset(visit, false, sizeof(visit));

        if(check() == true) break;
        Shot();
        all_print();
        Move_Enemy();
        all_print();
    }
}

void Choice_Archer(int idx, int cnt){
    if(cnt == 3){
        result = 0;
        Calculate();
        ans = max(ans, result);
        return;
    }

    for(int i=idx; i<m; i++){
        if(Choice[i] == true) continue;

        Choice[i] = true;
        Archer.push_back(i);

        Choice_Archer(i, cnt+1);

        Archer.pop_back();
        Choice[i] = false;
    }
}

int main(){
    cin >> n >> m >> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    Choice_Archer(0, 0);
    cout << ans;
}