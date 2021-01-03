#include <iostream>
#include <vector>

const int MAX = 50;
using namespace std;

int n, m, t;
int map[MAX][MAX];
vector<pair<int, int>> air_con;
pair<int, int> movdir[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int cc[] = {1, 0, 3, 2};
int c[] = {3, 0, 1, 2};

void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void Dust(){
    int temp[MAX][MAX] = {0};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] > 0){
                int cnt = 0;
                int num = map[i][j]/5;

                for(int d =0; d<4; d++){
                    int ny = i + movdir[d].first;
                    int nx = j + movdir[d].second;

                    if(0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] != -1){
                        cnt += 1;
                        temp[ny][nx] += num;
                    }
                }

                temp[i][j] += (map[i][j] - (num*cnt));
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            map[i][j] = temp[i][j];
        }
    }
    
    for(int i=0; i<2; i++){
        map[air_con[i].first][air_con[0].second] = -1;
    }
    //all_print();
}

void Cycle(){
    int y = air_con[0].first -1;
    int x = air_con[0].second;

    //cc회전
    int idx = 0;
    while(1){
        int ny = y + movdir[cc[idx]].first;
        int nx = x + movdir[cc[idx]].second;

        if(ny < 0 || air_con[0].first < ny || nx < 0 || m <= nx){
            idx += 1;
            continue;
        }

        if(ny == air_con[0].first && nx == air_con[0].second){
            map[y][x] = 0;
            break;
        }
        
        map[y][x] = map[ny][nx];
        y = ny;
        x = nx;
    }

    y = air_con[1].first +1;
    x = air_con[1].second;
    //c회전
    idx = 0;
    while(1){
        int ny = y + movdir[c[idx]].first;
        int nx = x + movdir[c[idx]].second;

        if(ny < air_con[1].first || n <= ny || nx < 0 || m <= nx){
            idx += 1;
            continue;
        }

        if(ny == air_con[1].first && nx == air_con[1].second){
            map[y][x] = 0;
            break;
        }
        
        map[y][x] = map[ny][nx];
        y = ny;
        x = nx;
    }
    //all_print();
}

int amount(){
    int total = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == -1) continue;

            total += map[i][j];
        }
    }

    return total;
}

int main(){
    cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == -1){
                air_con.push_back({i, j});          
            }
        }
    }

    for(int i=0; i<t; i++){
        Dust();
        Cycle();
    }
    cout << amount();
}