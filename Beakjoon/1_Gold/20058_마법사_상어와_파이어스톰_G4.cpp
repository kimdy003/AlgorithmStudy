#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>

const int MAX = 70;
using namespace std;

int n, k, q;
int map[MAX][MAX] = {0};
int temp[MAX][MAX] = {0};
bool visit[MAX][MAX];
pair<int, int> movdir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << temp[i][j] << " ";
        }
        cout << "\n";
    }
}

void Copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = temp[i][j];
        }
    }
}

void Turning(int y, int x, int size){
    int row = y, col = x;
    for(int j=x+size-1; j>=x; j--){
        for(int i=y; i<y+size; i++){
            temp[i][j] = map[row][col];
            col += 1;
        }
        row += 1;
        col = x;
    }
}

int BFS(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visit[a][b] = true;

    int cnt = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || n <= nx)
                continue;

            if(map[ny][nx] > 0 && visit[ny][nx] == false){
                visit[ny][nx] = true;
                q.push({ny, nx});
                cnt += 1;
            }
        }
    }

    return cnt;
}


int main(){
    cin >> k >> q;
    n = pow(2, k);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    int L;
    for(int query=0; query<q; query++){
        cin >> L;
        memset(temp, 0, sizeof(temp));
        
        int num = pow(2, L);
        for(int i=0; i<n; i+=num){
            for(int j=0; j<n; j+=num){
                Turning(i, j, num);
            }
        }

        //temp의 값들을 map으로 copy
        if(L != 0)
            Copy();

        //녹이기
        memset(visit, false, sizeof(visit));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == 0) continue;

                int cnt = 0;
                for(int d=0; d<4; d++){
                    int ny = i + movdir[d].first;
                    int nx = j + movdir[d].second;

                    if(ny < 0 || n <= ny || nx < 0 || n <= nx)
                        continue;
                    
                    if(map[ny][nx] > 0){
                        cnt++;
                    }
                }

                if(cnt < 3){
                    visit[i][j] = true;
                }
            }
        }

        for(int i=0; i<n ;i++){
            for(int j=0; j<n; j++){
                if(visit[i][j] == true){
                    map[i][j]--;
                }
            }
        }
        //all_print();
    }

    int sum = 0, ans = 0;
    memset(visit, false, sizeof(visit));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j] == false && map[i][j] > 0){
                ans = max(ans, BFS(i, j));
            }
            sum += map[i][j];
        }
    }


    cout << sum << "\n" << ans << "\n";
}