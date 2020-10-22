#include <iostream>

const int INF = 987654321;
using namespace std;

int n, m;
int Dist[101][101] = {0};

int main(){
    cin >> n >> m;

    for(int i=0; i<101; i++){
        fill(Dist[i], Dist[i]+101, INF);
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n;j ++){
            if(i==j){
                Dist[i][j] = 0;
            }
        }
    }

    for(int i=0; i<m; i++){
        int a, b; 
        cin >> a >> b;

        Dist[a][b] = 1;
        Dist[b][a] = 1;
    }

    for(int k=0; k<=n; k++){
        for(int i = 0; i<=n; i++){
            for(int j=0; j<=n; j++){
                Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j= 1; j<=n ;j++){
            sum += Dist[i][j];
        }
        Dist[i][0] = sum;
    }
    
    int Min = INF;
    int idx = 0;
    for(int i=1; i<=n; i++){
        if(Min > Dist[i][0]){
            Min = Dist[i][0];
            idx = i;
        }   
    }
    cout << idx;
}