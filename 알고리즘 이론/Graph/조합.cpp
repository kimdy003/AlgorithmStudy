//а╤гу
#include<iostream>
 
#define MAX 5
using namespace std;
 
int arr[MAX];
int Select[MAX];
bool visit[MAX];

#if 1
void DFS(int idx, int cnt){
    if(cnt == 3){
        for(int i=0; i<MAX; i++){
            if(visit[i] == true)
                cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=idx; i<MAX; i++){
        if(visit[i] == true) continue;

        visit[i] = true;
        
        DFS(i, cnt+1);
        visit[i] = false;
    }
}
#else
void DFS(int idx, int cnt){
    if(cnt == 3){
        for(int i=0; i<3; i++){
            cout << Select[i] << " " ;
        }
        cout << "\n";
        return;
    }

    for(int i=idx; i<MAX; i++){
        Select[cnt] = arr[i];
        DFS(i, cnt+1);
    }
}
#endif

int main(){
    for(int i=0; i<MAX; i++){
        arr[i] = i+1;
    }

    DFS(0, 0);
}