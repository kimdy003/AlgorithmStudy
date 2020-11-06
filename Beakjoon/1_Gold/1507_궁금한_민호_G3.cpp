#include <iostream>

const int MAX = 20;
using namespace std;

int n, result = 0;
int dist[MAX][MAX];
bool visit[MAX][MAX];

void Floyd(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j || j == k || i == k)
                    continue;
                else if(dist[i][j] > dist[i][k] + dist[k][j]){
                    result = -1;
                    return;
                }
                else if(dist[i][j] == dist[i][k] + dist[k][j]){
                    visit[i][j] = true;
                }
            }
        }
    }
}

int main(){
    cin >> n;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }

    Floyd();
    if(result != -1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visit[i][j] == false)
                    result += dist[i][j];
            }
        }
    }

    if(result == -1){
        cout << -1;
    }
    else{
        cout << result/2;
    }
}