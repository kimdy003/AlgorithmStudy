#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<vector<int>> v;
int n, ans = 0;
int check[1001];

void solution(int prev, int cur, int depth){
    check[cur] = depth;
    for(int i=0; i<v[cur].size(); i++){
        int next = v[cur][i];
        if(ans != 0){
            return;
        }
        if(check[next] != 0){
            if(next != prev){
                ans = check[cur] - check[next] +1;
                return;
            }
        }
        else{
            solution(cur, next, depth+1);
        }
    }
}


int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        ans = 0;
        cin >> n;
        v = vector<vector<int>>(n+1, vector<int>());
        memset(check, 0, sizeof(check));

        for(int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        solution(0, 1, 1);

        cout << "#" << test << " " << ans << "\n";
    }
}