#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
    (1) ��� ��带 ����
    (2) �ִ� �Ÿ� �迭�� �������� �ʱ�ȭ
    (3) �湮 ���� �ʴ� ��� �߿��� �ִ� �Ÿ��� ���� ª�� ��带 ����
    (4) �ش� ��带 ���� �ٸ� ���� ���� ����� ����Ͽ� �ִ� �Ÿ� �迭�� ����
    (5) (3)~(4)�� �ݺ�
*/

const int INF = 1e9; //������ �ǹ�, 10��
//���, ����, ���� ���
int n, m, start;
vector<pair<int, int>> graph[10001];
//�湮 üũ bool �迭
bool visit[10001];
//�ִ� �Ÿ� ���� �迭
int Dist[10001];

int GetSmallestNode(){
    int Min_value = INF;
    int Idx = 0;
    for(int i=0; i<= n; i++){
        if(Dist[i] < Min_value && visit[i] == true){
            Min_value = Dist[i];
            Idx = i;
        }
    }

    return Idx;
}

void Dijkstra(int start){
    Dist[start] = 0;
    visit[start] = false;
    for(int i=0; i<graph[start].size(); i++){
        Dist[graph[start][i].first] = graph[start][i].second;
    }

    //���� ��带 ������ ��ü ��忡 ���� �ݺ�
    for(int i=0; i<n-1; i++){
        //���� �ִ� �Ÿ��� ���� ª�� ��带 ����, �湮 ó��
        int now = GetSmallestNode();
        visit[now] = false;

        for(int j=0; j<graph[now].size(); j++){
            int cost = Dist[now] + graph[now][j].second;

            if(cost < Dist[graph[now][j].first])
                Dist[graph[now][j].first] = cost;
        }
    }
}

int main(){
    memset(visit, true, sizeof(visit));
    cin >> n >> m >> start;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    //(���� �ּ�, ������ ���� ����, ���� ��)
    fill_n(Dist, 10001, INF);
    //fill(Dist, Dist+10001, INF);

    Dijkstra(start);

    for(int i=0; i<=n; i++){
        //���� �� �� ���� ���
        if(Dist[i] == INF)
            cout << "����" << "\n";
        else
            cout << Dist[i] << "\n";
    }
}

