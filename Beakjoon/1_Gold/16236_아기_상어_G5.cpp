//?? ??
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct _shark
{
    int y;
    int x;
    int size = 2;
    int eating = 0;

}Shark;
int n, ans_time;
int map[20][20] = {0};
bool check[20][20];
Shark shark;
bool flag;
vector<pair<int, int>> eat;
pair<int, int> movdir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 

void all_print(){
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

void calculation(int cnt){
    if(eat.size() > 1){
        sort(eat.begin(), eat.end(), cmp);
    }

    ans_time += cnt;
    shark.eating++;
    map[eat[0].first][eat[0].second] = 0;
    shark.y = eat[0].first;
    shark.x = eat[0].second;

    if(shark.eating == shark.size){
        shark.size++;
        shark.eating = 0;
    }

    eat.clear();
}

void bfs(int cur_y, int cur_x){
    queue<pair<int, int>> q;
    int cnt = 1;
    q.push(make_pair(cur_y,cur_x));
    check[cur_y][cur_x] = false;

    while(!q.empty()){
        int current_size = q.size();
        for(int i=0; i<current_size; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nexty = y + movdir[i].first;
                int nextx = x + movdir[i].second;

                if(nexty < 0 || n <= nexty || nextx < 0 || n <= nextx || !check[nexty][nextx]) continue;
                if(map[nexty][nextx] > shark.size) continue;

                if(map[nexty][nextx] != 0 && map[nexty][nextx] < shark.size){
                    eat.push_back(make_pair(nexty, nextx));
                }

                check[nexty][nextx] = false;
                q.push(make_pair(nexty, nextx));
            }
        }

        if(eat.size() > 0){
            flag = true;
            calculation(cnt);
            return;
        }
        cnt++;
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                map[i][j] = 0;
                shark.y = i;
                shark.x = j;
            }
        }
    }

    flag = true;
    while(flag){
        memset(check, true, sizeof(check));
        flag = false;
        bfs(shark.y, shark.x);
        //all_print();
    }

    cout << ans_time;
}