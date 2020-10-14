#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;
vector<int> graph[MAX];
int compliment[MAX] = {0};

void DFS(int node){
    for(int i=0; i<graph[node].size(); i++){
        int next = graph[node][i];
        compliment[next] += compliment[node];
        DFS(next);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        int parent; cin >> parent;
        graph[parent].push_back(i);
    }

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        compliment[a] += b;
    }

    DFS(1);
    for(int i=1; i<=n; i++){
        cout << compliment[i] << " " ;
    }
}