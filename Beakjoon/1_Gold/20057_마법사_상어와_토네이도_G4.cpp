#include <iostream>
#include <queue>

const int MAX = 500;
using namespace std;

int n, num = 1, cnt = 0, ans = 0;
int map[MAX][MAX];
bool flag = true;

pair<pair<int, int>, int> pivot;
pair<int, int> movdir[] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int dir_map[4][5][5] = {
    {
        {0, 0, 2, 0, 0},
        {0, 10, 7, 1, 0},
        {5, 0, 0, 0, 0},
        {0, 10, 7, 1, 0},
        {0, 0, 2, 0, 0}
    },
    {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {2, 7, 0, 7, 2},
        {0, 10, 0, 10, 0},
        {0, 0, 5, 0, 0}
    },
    {
        {0, 0, 2, 0, 0},
        {0, 1, 7, 10, 0},
        {0, 0, 0, 0, 5},
        {0, 1, 7, 10, 0},
        {0, 0, 2, 0, 0}
    },
    {
        {0, 0, 5, 0, 0},
        {0, 10, 0, 10, 0},
        {2, 7, 0, 7, 2},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    }
};

void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void Move_Sand(int y, int x, int dir){
    int temp = map[y][x];
    map[y][x] = 0;
    int full = 0;

    int temp_map[5][5] = {0};
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            temp_map[i][j] = (temp * dir_map[dir][i][j]) / 100;
            full += temp_map[i][j];
        }
    }

    temp -= full;
    int ny = 2 + movdir[dir].first;
    int nx = 2 + movdir[dir].second;
    temp_map[ny][nx] = temp;

    cout << "\n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << temp_map[i][j] << " ";
        }
        cout << "\n";
    }

    int row = 0, col = 0;
    for(int i= y-2; i<=y+2; i++){
        for(int j=x-2; j<=x+2; j++){
            if(0 <= i && i < n && 0 <= j && j < n){
                map[i][j] += temp_map[row][col];
            }
            else{
                ans += temp_map[row][col];
            }
            col += 1;
        }
        row += 1;
        col = 0;
    }
    all_print();
}

void Move_Finger(){
    int y = pivot.first.first;
    int x = pivot.first.second; 
    int dir = pivot.second;

    for(int i=0; i<num; i++){
        int ny = y + movdir[dir].first;
        int nx = x + movdir[dir].second;
        if(y < 0 || x < 0){
            flag = false;
            return;
        }

        Move_Sand(ny, nx, dir);

        y = ny;
        x = nx;
    }

    pivot.first.first = y;
    pivot.first.second = x;
    cnt += 1;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    pivot.first.first = n/2;
    pivot.first.second = n/2;
    pivot.second = 0;

    while(flag){
        
        Move_Finger();

        pivot.second = (pivot.second + 1 > 3) ? 0 : pivot.second + 1;
        if(cnt % 2 == 0){
            num += 1;
        }
    }

    cout << ans;
}