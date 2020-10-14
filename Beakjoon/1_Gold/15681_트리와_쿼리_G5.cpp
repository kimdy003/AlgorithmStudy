#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;
int N, Root, Q, ans;
vector<vector<int>> v;
bool visit[MAX];
int node_num[MAX] = {0};

int DFS(int node){
    if(node_num[node] != 0){
        return node_num[node];
    }

    visit[node] = false;

    int cnt = 1;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(visit[next] == false) continue;
        cnt += DFS(v[node][i]);
    }

    node_num[node] = cnt;
    return cnt;
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    
    cin >> N >> Root >> Q;
    v = vector<vector<int>>(N+1, vector<int>());


    for(int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visit, true, sizeof(visit));
    node_num[Root] = DFS(Root);

    

    for(int i=0; i<Q; i++){
        int q; cin >> q;
        cout << node_num[q] << "\n";
    }
}