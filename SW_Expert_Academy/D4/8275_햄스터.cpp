// 햄스터
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n, x, m, sum_max;        // n: 햄스터 우리, x : 각 우리의 햄스터 수, m: 기록 수
int cage[7];
int ans[7];
vector<pair<pair<int, int>, int>> v;

bool check(){
    for(int i=0; i<v.size(); i++){
        int l = v[i].first.first;
        int r = v[i].first.second;
        int s = v[i].second;

        int temp = 0;
        for(int k =l; k<=r; k++){
            temp += cage[k];
        }

        if(temp != s){
            return false;
        }
    }
    return true;
}


void dfs(int cage_idx, int sum){
    if(cage_idx == n+1){
        if(check()){
            if(sum > sum_max){
                sum_max = sum;
                for(int i=1; i<=n; i++){
                    ans[i] = cage[i];
                }
            }
        }
        return;
    }

    for(int i=0; i<=x; i++){
        cage[cage_idx] = i;
        dfs(cage_idx+1, sum+i);
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;

    for(int test=1; test<=T; test++){
        memset(cage, 0, sizeof(cage));
        memset(ans, -1, sizeof(ans));
        v.clear();
        sum_max = -1;
        cin >> n >> x >> m;

        int l, r, s;
        for(int i=0; i<m; i++){
            cin >> l >> r >> s;
            v.push_back(make_pair(make_pair(l, r), s));
        }

        dfs(1, 0);

        bool flag = true;
        cout << "#" << test << " " ;
        for(int i=1; i<=n; i++){
            if(ans[i] == -1){
                cout << -1 ;
                flag = false;
                break;
            }
        }

        if(flag){
            for(int i=1; i<=n; i++){
                cout << ans[i] << " ";
            }
        }
        cout << "\n";
    }
}