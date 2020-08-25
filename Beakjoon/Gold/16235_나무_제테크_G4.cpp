//나무 제테크
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
int map[11][11];
int eat_add[11][11];
vector<int> tree[11][11];
pair<int, int> movdir[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
                                {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void vec_sort(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(tree[i][j].size() == 0) continue;
            sort(tree[i][j].begin(), tree[i][j].end());
        }
    }
}

void spring_summer(){
    //나이만큼 양분 먹고 나이 1증가(어린 나무부터)
    //양분을 못 먹으면 죽음
    //죽은 나무는 양분으로
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(tree[i][j].size() == 0) continue;
            int save = 0;
            int k;
            vector<int> temp;
            for(k=0; k<tree[i][j].size(); k++){
                if(tree[i][j][k] <= map[i][j]){
                    map[i][j] -= tree[i][j][k];
                    temp.push_back(tree[i][j][k]+1);
                    continue;
                }
                break;
            }
            for(int die = k; die<tree[i][j].size(); die++){
                save += (tree[i][j][die]/2);
            }

            tree[i][j].clear();
            for(int l = 0; l<temp.size(); l++){
                tree[i][j].push_back(temp[l]);
            }
            map[i][j] += save;
        }
    }
}

void fall(){
    //나이가 5의 배수 나무들 번식
    //인접한 8칸에 나무 증가

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<tree[i][j].size(); k++){
                if(tree[i][j][k] % 5 != 0) continue;

                for(int add = 0; add <8; add++){
                    int nexty = i + movdir[add].first;
                    int nextx = j + movdir[add].second;

                    if(nexty <= 0 || n < nexty || nextx <= 0 || n < nextx)
                        continue;
                    
                    tree[nexty][nextx].push_back(1);
                }
            }
        }
    }
}

void winter(){
    //로봇이 돌아다니면서 양분 추가
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            map[i][j] += eat_add[i][j];
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> eat_add[i][j];
            map[i][j] = 5;
        }
    }

    for(int i=0; i<m; i++){
        int x, y, age;
        cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }

    while(k--){
        vec_sort();
        spring_summer();
        fall();
        winter();
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!tree[i][j].empty())
                cnt += tree[i][j].size();
        }
    }

    cout << cnt;
}