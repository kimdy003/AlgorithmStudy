#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void DFS(int idx){
    if(v.size() == m){
        for(int i=0; i<v.size()-1; i++)
            cout << v[i] << " ";
        cout << v[v.size()-1] << "\n";
        return;
    }

    for(int i=idx; i<=n; i++){
        v.push_back(i);
        DFS(i);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    DFS(1);
}