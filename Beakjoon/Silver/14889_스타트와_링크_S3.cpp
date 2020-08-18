#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int n, ans = 987654321;
int s[21][21] = {0};
vector<int> start;
vector<int> link;


int get_min(){
    int s_power =0;
    int l_power =0;

    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            if(i==j)
                continue;

            s_power += s[start[i]][start[j]];
            l_power += s[link[i]][link[j]];
        }
    }
    
    return abs(s_power - l_power);
}

void dfs(int cnt){
    if(cnt == n+1){
        if(start.size() == n/2 && link.size() == n/2){
            ans = min(ans, get_min());
        }
        return;
    }

    start.push_back(cnt);
    dfs(cnt+1);
    start.pop_back();

    link.push_back(cnt);
    dfs(cnt+1);
    link.pop_back();

}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> s[i][j];
        }
    }

    dfs(1);

    cout << ans << "\n";
}