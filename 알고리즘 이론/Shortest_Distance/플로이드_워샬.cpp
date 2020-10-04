#include <iostream>
using namespace std;

const int INF = 1e9;
//n : 노드의 개수, m : 간선의 개수
int n, m;
//노드의 개수를 최대 500개로 가정
int graph[501][501];

int main(){
    cin >> n >> m;

    //무한으로 초기화, 2차원 배열
    for(int i=0; i<501; i++){
        fill(graph[i], graph[i]+501, INF);
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i == j){
                graph[i][j] == 0;
            }
        }
    }

    //a에서 b까지 가는 거리 비용이 c
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    //플로이드_워샬 점화식 적용
    for(int k=0; k<=n; k++){
        for(int i = 0; i<=n; i++){
            for(int j=0; j<=n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(graph[i][j] == INF){
                cout << "무한"<< "\n";
            }
            else
                cout << graph[i][j] << "\n";
        }
    }
}