#include <iostream>
#include <vector>

const int MAX = 101;
const int INF = 987654321;
using namespace std;

int n, m;
int Dist[MAX][MAX];

void all_print(){
    cout << "\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << Dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        Dist[a][b] = 1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(Dist[i][k] && Dist[k][j])
                    Dist[i][j] = 1;
            }
        }
    }

    all_print();
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(i == j) continue;

            if(Dist[i][j] == 0 && Dist[j][i] == 0){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}