#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, ans = 0;
bool visit[101];
vector<vector<int>> v;
queue<int> q;

void BFS(){
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(!visit[next]){
                visit[next] = true;
                q.push(next);
                ans++;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    v = vector<vector<int>>(n+1, vector<int>());

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    q.push(1);
    visit[1] = true;
    BFS();

    cout << ans;
}