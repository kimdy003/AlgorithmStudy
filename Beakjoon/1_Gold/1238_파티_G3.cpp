#include <iostream>

const int MAX = 1001;
const int INF = 987654321;
using namespace std;

int n, m, x;
int Dist[MAX][MAX];

int main(){
    cin >> n >> m >> x;

    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            if(i == j) Dist[i][j] = 0;
            else Dist[i][j] = INF;
        }   
    }

    for(int i=0; i<m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            Dist[a][b] = c;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                Dist[i][j] = min(Dist[i][j], Dist[i][k]+Dist[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(i == x) continue;
        ans = max(ans, Dist[i][x] + Dist[x][i]);
    }
    cout << ans;
}