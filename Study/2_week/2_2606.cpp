#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int v, e, ans = 0;
vector<int> graph[101];
bool visit[101];

void BFS(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i];
            if(visit[next] == false){
                visit[next] = true;
                q.push(next);
                ans++;
            }
        }
    }
}

int main(){
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    BFS(1);
    cout << ans;
}