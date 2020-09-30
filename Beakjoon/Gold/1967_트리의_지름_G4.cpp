#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, ans = 0;
vector<vector<pair<int, int>>> v;
bool visit[10001];
int End_Point;

void DFS(int node, int diameter){
    if(!visit[node])
        return;

    visit[node] = false;
    if(ans < diameter){
        ans = diameter;
        End_Point = node;
    }
    
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i].first;
        int cost = v[node][i].second;

        DFS(next, diameter+cost);
    }
}

int main(){
    cin >> n;
    v.resize(n+1);

    int a, b, c;
    for(int i=0; i<n-1; i++){
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    memset(visit, true, sizeof(visit));
    DFS(1, 0);

    ans = 0;
    memset(visit, true, sizeof(visit));

    DFS(End_Point, 0);
    cout << ans;
}
