#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
    (1) 출발 노드를 설정
    (2) 최단 거리 배열을 무한으로 초기화
    (3) 방문 하지 않는 노드 중에서 최단 거리가 가장 짧은 노드를 선택
    (4) 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 배열을 갱신
    (5) (3)~(4)번 반복
*/

const int INF = 1e9; //무한을 의미, 10억
//노드, 간선, 시작 노드
int n, m, start;
vector<pair<int, int>> graph[10001];
//방문 체크 bool 배열
bool visit[10001];
//최단 거리 저장 배열
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

    //시작 노드를 제외한 전체 노드에 대해 반복
    for(int i=0; i<n-1; i++){
        //현재 최단 거리가 가장 짧은 노드를 꺼내, 방문 처리
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

