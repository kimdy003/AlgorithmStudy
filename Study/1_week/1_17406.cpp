#include <iostream>
#include <vector>

const int MAX = 51;
using namespace std;

typedef struct _INFO{
    int r;
    int c;
    int s;
} INFO;

int n, m, k, ans = 987654321;
int map[MAX][MAX];
bool visit[MAX];
vector<INFO> order;

pair<int, int> movdir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void all_print(){
    for (int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void Check(){
    for (int i=1; i<=n; i++){
        int temp = 0;
        for(int j=1; j<=m; j++){
            temp += map[i][j];
        }
        ans = min(ans, temp);
    }
}

void Rotation(int idx){
    
    int r = order[idx].r;
    int c = order[idx].c;
    int s = order[idx].s;

    while (s != 0){
        int first = map[r-s][c-s];
        int y = r-s; int x = c-s;
        
        for(int dir=0; dir<4; dir++){
            for(int j=0; j<s*2; j++){
                int ny = y + movdir[dir].first;
                int nx = x + movdir[dir].second;

                map[y][x] = map[ny][nx];
                y = ny;
                x = nx;
            }
        }

        map[r-s][c-s+1] = first;
        s-= 1;
    }
}

void Permutation(int cnt){
    if (cnt == k){
        Check();
        return;
    }

    int temp[MAX][MAX] = {0};
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            temp[i][j] = map[i][j];
        }
    }

    for (int i=0; i<k; i++){
        if (visit[i] == true) continue;
        visit[i] = true;

        Rotation(i);

        Permutation(cnt+1);

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                map[i][j] = temp[i][j];
            }
        }
        cout << "\n";
        all_print();
        visit[i] = false;
    }
}

int main(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }

    for (int i=0; i<k; i++){
        int r, c, s;
        cin >> r >> c >> s;
        order.push_back({r, c, s});
    }

    Permutation(0);
    cout << ans;
}