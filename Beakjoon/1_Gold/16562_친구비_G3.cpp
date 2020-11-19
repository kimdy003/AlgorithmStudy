#include <iostream>
#include <vector>
#include <queue>

const int MAX = 10001;
using namespace std;

int n, m, k;
int money[MAX];
vector<int> v[MAX];
bool visit[MAX];

int BFS(int start){
    queue<int> q;
    q.push(start);
    int Min_money = money[start];
    visit[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(visit[next] == true) continue;

            visit[next] = true;
            Min_money = min(Min_money, money[next]);
            q.push(next);
        }
    }

    return Min_money;
}

int main(){
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++)
        cin >> money[i];
    

    for(int i=1; i<=m; i++){
        int a ,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(visit[i] == true) continue;
        ans += BFS(i);
    }

    if(k < ans)
        cout << "oh no";
    else
        cout << ans;

}
