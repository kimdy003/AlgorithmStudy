#include <iostream>
using namespace std;

const int INF = 1e9;
//n : ����� ����, m : ������ ����
int n, m;
//����� ������ �ִ� 500���� ����
int graph[501][501];

int main(){
    cin >> n >> m;

    //�������� �ʱ�ȭ, 2���� �迭
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

    //a���� b���� ���� �Ÿ� ����� c
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    //�÷��̵�_���� ��ȭ�� ����
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
                cout << "����"<< "\n";
            }
            else
                cout << graph[i][j] << "\n";
        }
    }
}