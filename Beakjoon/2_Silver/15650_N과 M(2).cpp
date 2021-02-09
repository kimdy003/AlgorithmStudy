#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visit[9];
vector<int> v;

void DFS(int idx){
    if(v.size() == m){
        for(int i=0; i<v.size()-1; i++)
            cout << v[i] << " ";
        cout << v[v.size()-1] << "\n";
        return;
    }

    for(int i=idx; i<=n; i++){
        if(visit[i] == false){
            visit[i] = true;
            v.push_back(i);
            DFS(i);
            v.pop_back();
            visit[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    DFS(1);
}