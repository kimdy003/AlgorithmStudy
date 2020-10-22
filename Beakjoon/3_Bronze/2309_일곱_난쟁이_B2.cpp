#include <iostream>
#include <algorithm>

const int n = 9;
using namespace std;

int ans = 0;
bool flag = true;
int map[n];
bool visit[n];

void DFS(int idx, int cnt){
    if(cnt == 7){
        if(ans == 100){
            flag = false;
            return;
        }
    }

    for(int i=idx; i<n; i++){
        if(visit[i] == true) continue;
        visit[i] = true;
        ans += map[i];
        
        DFS(i+1, cnt+1);
        if(!flag) return;
        
        ans -= map[i];
        visit[i] = false;
    }
}

int main(){
    for(int i=0; i<n ;i++){
        cin >> map[i];
    }

    sort(map, map+n);
    DFS(0, 0);

    for(int i=0; i<n; i++){
        if(visit[i] == true){
            cout << map[i] << "\n";
        }
    }
}