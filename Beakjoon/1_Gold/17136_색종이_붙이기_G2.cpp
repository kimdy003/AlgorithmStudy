#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

const int MAX = 10;
using namespace std;

int ans = 987654321;
int paper[6] = {0};
int map[MAX][MAX];
bool visit[MAX][MAX];

vector<pair<int, int>> v;

void all_print(){
    cout << "\n";
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

bool Can_Search(int y, int x, int size){
    for(int i=0; i <size; i++){
        for(int j=0; j<size; j++){
            if(visit[y+i][x+j] == false)
                return false;
        }
    }    

    return true;
}

void Fill_paper(int y, int x, int size, bool flag){
    //부착 || 복구
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(flag)
                map[y+i][x+j] = 1;
            else
                map[y+i][x+j] = 0;

            visit[y+i][x+j] = flag;
        }
    }
}

void DFS(int idx, int cnt){
    if(idx == v.size()){
        ans = min(ans, cnt);
        return;
    }

    if(ans <= cnt)
        return;


    int y = v[idx].first;
    int x = v[idx].second;
    if(visit[y][x] == false){
        DFS(idx+1, cnt);
        return;
    }

    for(int p = 5; p > 0; p--){
        if(y + p > MAX || x + p > MAX || paper[p] == 5)
            continue;

        if(Can_Search(y, x, p) == true){
            //부착
            Fill_paper(y, x, p, false);
            paper[p]++;
            //all_print();
            DFS(idx+1, cnt+1);

            //원상 복구
            Fill_paper(y, x, p, true);
            paper[p]--;
            //all_print();
        }
    }
}

int main(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                visit[i][j] = true;
                v.push_back({i, j});
            }
        }
    }

    DFS(0, 0);

    if(ans == 987654321)
        cout << -1;
    else
        cout << ans;
}