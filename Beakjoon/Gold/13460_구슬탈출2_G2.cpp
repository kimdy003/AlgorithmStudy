#include <iostream>
using namespace std;
int n ,m, ans = 987654321;
char map[10][10];
pair<int, int> Red, Blue;
pair<int, int> movdir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int Cal_Dist(int y, int x, int yy, int xx){
    return abs(yy - y) + abs(xx - x);
}

int Inverse(int d){
    if(d == 0) return 2;
    else if(d == 1) return 3;
    else if(d == 2) return 0;
    
    return 1;
}

void DFS(int Ry, int Rx, int By, int Bx, int cnt, int dir){
    if(cnt >= ans) return;
    if(cnt > 10) return;

    bool Red_flag = false;
    bool Blue_flag = false;

    int nRy = Ry + movdir[dir].first;
    int nRx = Rx + movdir[dir].second;
    while(1){
        if(map[nRy][nRx] == '#') break;
        if(map[nRy][nRx] == 'O'){
            Red_flag = true;
            break;
        }
        nRy += movdir[dir].first;
        nRx += movdir[dir].second;
    }
    nRy -= movdir[dir].first;
    nRx -= movdir[dir].second;

    int nBy = By + movdir[dir].first;
    int nBx = Bx + movdir[dir].second;
    while(1){
        if(map[nBy][nBx] == '#') break;
        if(map[nBy][nBx] == 'O'){
            Blue_flag = true;
            break;
        }
        nBy += movdir[dir].first;
        nBx += movdir[dir].second;
    }
    nBy -= movdir[dir].first;
    nBx -= movdir[dir].second;

    if(Blue_flag) return;
    else{
        if(Red_flag){
            ans = min(ans, cnt);
            return;
        }
    }

    if(nRy == nBy && nRx == nBx){
        int Red_Dist = Cal_Dist(Ry, Rx, nRy, nRx);
        int Blue_Dist = Cal_Dist(By, Bx, nBy, nBx);
        if(Red_Dist > Blue_Dist){
            nRy -= movdir[dir].first;
            nRx -= movdir[dir].second;
        }
        else{
            nBy -= movdir[dir].first;
            nBx -= movdir[dir].second;
        }
    }

    for(int i=0; i<4; i++){
        if(i == dir) continue;
        if(i == Inverse(dir)) continue;

        DFS(nRy, nRx, nBy, nBx, cnt+1, i);
    }
}


int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                Red.first = i;
                Red.second = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'B'){
                Blue.first = i;
                Blue.second = j;
                map[i][j] = '.';
            }
        }
    }

    for(int i=0; i<4; i++){
        int y = Red.first;
        int x = Red.second;

        int yy = Blue.first;
        int xx = Blue.second;   
        DFS(y, x, yy, xx, 1, i);
    }
    
    if(ans > 10 || ans == 987654321){
        cout << -1;
    }
    else{
        cout << ans;
    }
}