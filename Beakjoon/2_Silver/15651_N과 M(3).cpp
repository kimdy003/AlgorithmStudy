#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void DFS(){
    if(v.size() == m){
        for(int i=0; i<v.size()-1; i++)
            cout << v[i] << " ";
        cout << v[v.size()-1] << "\n";
        return;
    }

    for(int i=1; i<=n; i++){
        v.push_back(i);
        DFS();
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    DFS();
}