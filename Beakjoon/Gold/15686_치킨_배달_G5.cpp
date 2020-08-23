#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int n, m, del;
int ans = 987654321;
int map[51][51] = {0};
bool check[13];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int get_dir(){
    int result = 0;
    for(int i=0; i<house.size(); i++){
        int sum = 987654321;
        for(int j=0; j<chicken.size(); j++){
            if(check[j]){
                sum = min(sum, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
            }
        }
        result += sum;
    }

    return result;
}

void dfs(int idx, int cnt){
    if(cnt == m){
        ans = min(ans, get_dir());
        return;
    }

    for(int i=idx; i<chicken.size(); i++){
        if(check[i] == true)
            continue;

        check[i] = true;
        dfs(i, cnt+1);
        check[i] = false;
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                house.push_back({i,j});
            }
            else if(map[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    }

    dfs(0, 0);

    cout << ans ;
}
