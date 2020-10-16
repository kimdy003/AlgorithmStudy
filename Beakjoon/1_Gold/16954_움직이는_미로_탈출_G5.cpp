#include <iostream>
#include <queue>

const int n = 8;
using namespace std;

char map[n][n];
pair<int, int> movdir[9] = {
{0, 0}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, 
{1, 0}, {1, -1}, {0, -1}, {-1, -1}
};

void Move_wall(){
    for(int i=0; i<n; i++){
        map[7][i] = '.';
    }

    for(int i=6; i>=0; i--){
        for(int j=0; j<n; j++){
            map[i+1][j] = map[i][j];
            map[i][j] = '.';
        }
    }

    // cout << "\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << map[i][j];
    //     }
    //     cout << "\n";
    // }
}

bool BFS(int Sy, int Sx){
    queue<pair<pair<int, int>, int>> q;
    q.push({{Sy, Sx}, 0});

    while(!q.empty()){
        int size = q.size();

        for(int cur = 0; cur < size; cur++){
            int y = q.front().first.first;
            int x = q.front().first.second;
            int t = q.front().second;
            q.pop();

            if(map[y][x] == '#')
                continue;

            if(y == 0){
                return true;
            }

            for(int i=0; i<9; i++){
                int ny = y + movdir[i].first;
                int nx = x + movdir[i].second;
                int nt = t + 1;

                if(nt >= 8)
                    return true;

                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(map[ny][nx] == '.' && map[ny-1][nx] != '#'){
                        q.push({{ny, nx}, nt});
                    }
                }
            }
        }
        Move_wall();
    }

    return false;
}

int main(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    bool ans = BFS(7, 0);
    cout << ans;
    return 0;
}