//¼ø¿­
#include <iostream>
#include <vector>

const int MAX= 5;
using namespace std;
 
int arr[MAX];
int Select[MAX];
bool visit[MAX];
vector<int> v;

#if 1
void DFS(int cnt){
    if(cnt == 3){
        for(int i=0; i<MAX; i++){
            if(visit[i] == true)
                cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<MAX; i++){
        if(visit[i] == true) continue;
        visit[i] = true;
        v.push_back(arr[i]);
        
        DFS(cnt+1);
        v.pop_back();
        visit[i] = false;
    }
}
#else
void DFS(int cnt){
    if(cnt == 3){
        for(int i=0; i<3; i++){
            cout << Select[i] << " " ;
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<MAX; i++){
        Select[cnt] = arr[i];
        DFS(cnt+1);
    }
}
#endif

int main(){
    for(int i=0; i<MAX; i++){
        arr[i] = i+1;
    }

    DFS(0);
}