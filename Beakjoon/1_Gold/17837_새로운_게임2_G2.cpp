#include <iostream>
#include <vector>
using namespace std;

typedef struct _CHESS{
    int y;
    int x;
    int dir;
} CHESS;

typedef struct _MAP_INFO{
    //0: Èò»ö, 1: »¡°­, 2: ÆÄ¶û
    int color;
    vector<int> v;
} MAP_INFO;

int n, k;
MAP_INFO map[7][7];
CHESS Chess[11];
pair<int, int> movdir[5] = {{0,0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void all_print(){
    cout << "\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << map[i][j].v.size() << "  ";
        }
        cout << "\n";
    }
}

int Inverse_Dir(int d){
    if(d == 1) return 2;
    else if(d == 2) return 1;
    else if(d == 3) return 4;
    return 3;
}

void Moving(int idx, int nexty, int nextx, int y, int x, int color, vector<int> temp){
    if(color == 0){
        for(int i=0; i<temp.size(); i++){
            map[nexty][nextx].v.push_back(temp[i]);
            Chess[temp[i]].y = nexty;
            Chess[temp[i]].x = nextx;
        }
    }
    else if(color == 1){
        for(int i=temp.size()-1; i>=0; i--){
            map[nexty][nextx].v.push_back(temp[i]);
            Chess[temp[i]].y = nexty;
            Chess[temp[i]].x = nextx;
        }
    }
    else{
        int re_dir = Inverse_Dir(Chess[idx].dir);
        Chess[idx].dir = re_dir;
        nexty = y + movdir[re_dir].first;
        nextx = x + movdir[re_dir].second;
        if(nexty <= 0 || n < nexty || nextx <= 0 || n < nextx || map[nexty][nextx].color == 2){
            for(int i=0; i<temp.size(); i++){
                map[y][x].v.push_back(temp[i]);
            }
            return;
        }
        
        Moving(idx, nexty, nextx, y, x, map[nexty][nextx].color, temp);
    }
}

bool Check(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j].v.size() >= 4){
                return true;
            }
        }
    }

    return false;
}

int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j].color;
        }
    }

    for(int i=1; i<=k; i++){
        int y, x, d;
        cin >> y >> x >> d;
        Chess[i].y = y;
        Chess[i].x = x;
        Chess[i].dir = d;

        map[y][x].v.push_back(i);
    }

    int turn;
    bool flag = true;
    for(turn=0; turn < 1001 && flag; turn++){
        flag = true;
        for(int i=1; i<=k; i++){
            int y = Chess[i].y;
            int x = Chess[i].x;
            int dir = Chess[i].dir;

            vector<int> temp;
            if(map[y][x].v.size() == 1){
                temp.push_back(i);
                map[y][x].v.pop_back();
            }
            else{
                for(int j=0; j<map[y][x].v.size(); j++){
                    if(map[y][x].v[j] == i){
                        for(int k=j; k<map[y][x].v.size(); k++){
                            temp.push_back(map[y][x].v[k]);
                        }
                        map[y][x].v.erase(map[y][x].v.begin()+j, map[y][x].v.end());
                    }
                }
            }

            int ny = y + movdir[dir].first;
            int nx = x + movdir[dir].second;

            if(0 < ny && ny <= n && 0 < nx && nx <= n){
                Moving(i, ny, nx, y, x, map[ny][nx].color, temp);
            }
            else{
                Moving(i, ny, nx, y, x, 2, temp);
            }

            if(Check() == true){
                flag = false;
                break;
            }
        }
    }

    if(turn > 1000){
        cout << -1;
        return 0;
    }
    cout << turn;
}

