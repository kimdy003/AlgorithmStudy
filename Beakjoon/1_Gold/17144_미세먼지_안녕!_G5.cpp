#include <iostream>
#include <queue>
using namespace std;

typedef struct _cleaner{
    int y;
    int x;
}Cleaner;

int n,m,t;
int map[50][50] = {0};
bool check[50][50];
Cleaner air_1, air_2;
pair<int, int> movdir[4] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
//반시계
int ccw[4] = {3, 0, 2, 1};
//시계
int cw[4] = {3, 1, 2, 0};
 
void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void dust(){
    int temp[50][50] = {0};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] > 0){
                int cnt = 0;
                for(int k=0; k<4; k++){
                    int nexty = i + movdir[k].first;
                    int nextx = j + movdir[k].second;

                    if(nexty < 0 || n <= nexty || nextx < 0 || m <= nextx) continue;
                    if(map[nexty][nextx] == -1) continue;

                    temp[nexty][nextx] += map[i][j]/5;
                    cnt++;
                }
                temp[i][j] += map[i][j] - ((map[i][j]/5)*cnt);
            }

            if(map[i][j] == -1){
                temp[i][j] = -1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            map[i][j] = temp[i][j];
        }
    }
    //all_print();
}

void air_clean(){
    int temp[50][50] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            temp[i][j] = map[i][j];
        }
    }

    int y1 = air_1.y;
    int x1 = air_1.x+1;
    map[y1][x1] = 0;
    for(int i=0; i<4; i++){
        while(1){
            int nexty = y1 + movdir[ccw[i]].first;
            int nextx = x1 + movdir[ccw[i]].second;

            if(nexty == air_1.y && nextx == air_1.x) break;
            if(!(0 <= nexty && nexty <n && 0<=nextx && nextx <m)) break;

            
            map[nexty][nextx] = temp[y1][x1];
            y1 = nexty;
            x1 = nextx;
        }
    }


    int y2 = air_2.y;
    int x2 = air_2.x+1;
    map[y2][x2] = 0;
    for(int i=0; i<4; i++){
        while(1){
            int nexty = y2 + movdir[cw[i]].first;
            int nextx = x2 + movdir[cw[i]].second;

            if(nexty == air_2.y && nextx == air_2.x) break;
            if(!(0 <= nexty && nexty <n && 0<=nextx && nextx <m)) break;

            
            map[nexty][nextx] = temp[y2][x2];
            y2 = nexty;
            x2 = nextx;
        }
    }

    //all_print();
    
}


int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n >> m >> t;
    bool flag = true;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == -1 && flag){
                flag = false;
                air_1.y = i;
                air_1.x = j;

                air_2.y = i+1;
                air_2.x = j;
            }
        }
    }

    while(t--){
        dust();
        air_clean();

    }

    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] > 0)
                sum += map[i][j];
        }
    }
    
    cout << sum ;
}