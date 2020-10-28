#include <iostream>
#include <cmath>

using namespace std;

int n, m;
int weight[30];
int marble[7];
bool check[31][15001];

void DFS(int cnt, int result){
    if(cnt > n) return;
    if(check[cnt][result] == true) return;

    check[cnt][result] = true;
    
    DFS(cnt+1, result + weight[cnt]);
    DFS(cnt+1, abs(result - weight[cnt]));
    DFS(cnt+1, result);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }

    DFS(0, 0);

    cin >> m;
    for(int i=0; i<m; i++){
        int a; cin >> a;
        if(a > 15000) cout << "N ";
        else if(check[n][a] == true) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}