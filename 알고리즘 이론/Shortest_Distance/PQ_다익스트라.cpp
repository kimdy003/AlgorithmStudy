#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
    우선 순위 큐를 사용한 다익스트라
    (이것을 많이 사용)
    세세한 설명은 Org_Dijkstra.cpp 참고
*/

const int INF = 1e9; //무한을 의미, 10억
//노드, 간선, 시작 노드
int n, m, start;
vector<pair<int, int>> graph[10001];
//최단 거리 저장 배열
int Dist[10001];

void Dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    // 가중치, 노드 순서 (가중치에 대한 오름차순을 만들기 위해)
    pq.push({0, K});
    Dist[start] = 0;

    while(!pq.empty()){
        //-부호를 붙여서 원래 수로 반환
        int dist = -pq.top().first;
        int Cur = pq.top().second;
        pq.pop();

        for(int i=0; i<graph[Cur].size(); i++){
            int next = graph[Cur][i].first;
            int n_dist = graph[Cur][i].second;

            if(dist + n_dist < Dist[next]){
                Dist[next] = dist + n_dist;
                //-부호를 붙임으로서 최소힙 우선순위 큐를 만들 수 있다.
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
        //노드, 가중치 순서
        graph[a].push_back({b, c});
    }

    //(시작 주소, 변경할 원소 개수, 변경 값)
    fill_n(Dist, 10001, INF);
    //fill(Dist, Dist+10001, INF);

    Dijkstra(start);

    for(int i=0; i<=n; i++){
        //도달 할 수 없는 경우
        if(Dist[i] == INF)
            cout << "무한" << "\n";
        else
            cout << Dist[i] << "\n";
    }
}