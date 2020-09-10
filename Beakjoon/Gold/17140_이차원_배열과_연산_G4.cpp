#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int r, c, k;
int map[101][101] = {0};
int num_cnt[101];

void all_print(){
    cout << "\n";
    for(int i=1; i<20; i++){
        for(int j=1; j<20; j++){
            cout << map[i][j] << " " ;
        }
        cout << "\n";
    }
}

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main(){
    cin >> r >> c >> k;

    int row = 3;
    int col = 3;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            cin >> map[i][j];
        }
    }

    if(map[r][c] == k){
        cout << "0";
        return 0;
    }

    int time = 0;
    int ans = 0;
    while(1){
        if(time > 100){
            ans = -1;
            break;
        }

        if(map[r][c] == k){
            ans = time;
            break;
        }
        

        if(row >= col){
            for(int i=1; i<= row; i++){
                vector<pair<int, int>> v;
                memset(num_cnt, 0, sizeof(num_cnt));

                for(int j=1; j<= col; j++){
                    num_cnt[map[i][j]]++;
                }

                for(int j=1; j<101; j++){
                    if(num_cnt[j] == 0) continue;
                    v.push_back({num_cnt[j], j});
                }

                sort(v.begin(), v.end());
                for(int j=1; j <= col; j++){
                    map[i][j] = 0;
                }

                int idx = 1;
                for(int j=0; j<v.size(); j++){
                    map[i][idx++] = v[j].second;
                    map[i][idx++] = v[j].first;
                }
            }
        }
        else{
            for(int i=1; i<=col; i++){
                vector<pair<int, int>> v;
                memset(num_cnt, 0, sizeof(num_cnt));

                for(int j=1; j<=row; j++){
                    num_cnt[map[j][i]]++;
                }

                for(int j=1; j<101; j++){
                    if(num_cnt[j] == 0) continue;
                    v.push_back({num_cnt[j], j});
                }

                sort(v.begin(), v.end());
                for(int j=1; j<=row; j++){
                    map[j][i] = 0;
                }

                int idx = 1;
                for(int j = 0; j<v.size(); j++){
                    map[idx++][i] = v[j].second;
                    map[idx++][i] = v[j].first;
                }
            }
        }

        //all_print();

        for(int i=1; i<101; i++){
            for(int j=1; j<101; j++){
                if(map[i][j] == 0) continue;
                row = max(row, i);
                col = max(col, j);
            }
        }

        time++;
    }

    cout << ans;
}