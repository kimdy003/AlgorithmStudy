#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
    �켱 ���� ť�� ����� ���ͽ�Ʈ��
    (�̰��� ���� ���)
    ������ ������ Org_Dijkstra.cpp ����
*/

const int INF = 1e9; //������ �ǹ�, 10��
//���, ����, ���� ���
int n, m, start;
vector<pair<int, int>> graph[10001];
//�ִ� �Ÿ� ���� �迭
int Dist[10001];

void Dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    // ����ġ, ��� ���� (����ġ�� ���� ���������� ����� ����)
    pq.push({0, K});
    Dist[start] = 0;

    while(!pq.empty()){
        //-��ȣ�� �ٿ��� ���� ���� ��ȯ
        int dist = -pq.top().first;
        int Cur = pq.top().second;
        pq.pop();

        for(int i=0; i<graph[Cur].size(); i++){
            int next = graph[Cur][i].first;
            int n_dist = graph[Cur][i].second;

            if(dist + n_dist < Dist[next]){
                Dist[next] = dist + n_dist;
                //-��ȣ�� �������μ� �ּ��� �켱���� ť�� ���� �� �ִ�.
                pq.push({-Dist[next], next});
            }
        }
    }

}

int main(){
    cin >> n >> m >> start;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        //���, ����ġ ����
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