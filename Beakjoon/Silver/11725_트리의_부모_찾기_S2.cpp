#include <iostream>
#include <vector>

using namespace std;

int parent[100001] = {0};
bool visit[100001];
vector<int> tree[100001];

void Find_Parent(int node){
    visit[node] = true;

    for(int i=0; i<tree[node].size(); i++){
        int next = tree[node][i];

        if(visit[next] == false){
            parent[next] = node;
            Find_Parent(next);
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    Find_Parent(1);

    for(int i=2; i<=n; i++){
        cout << parent[i] << "\n";
    }
}