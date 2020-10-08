//크루스칼 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
int parent[100001];

vector<pair<int, pair<int, int>>> edges;
int result = 0;

int Find(int x){
    if(x == parent[x])
        return x;
    
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    cin >> v >> e;

    for(int i=1; i<=v; i++){
        parent[i] = i;
    }

    for(int i=0; i<e; i++){
        int a, b, cost; cin >> a >> b >> cost;
        edges.push_back({cost, {a, b}});
    }

    sort(edges.begin(), edges.end());

    //간선을 하나씩 확인하며 사이클 여부 확인
    for(int i=0; i<edges.size(); i++){
        int cost = edges[i].first;
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;

        if(Find(node1) != Find(node2)){
            Union(node1, node2);
            result += cost;
        }
    }

    cout << result;
}
