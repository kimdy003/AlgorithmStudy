#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
int V, E, K;
int Dist[20001] = {0};
vector<pair<int, int>> vec[20001];

void Dijstra(){
    priority_queue<pair<int, int>> pq;
    // 가중치, 노드 순서 (가중치에 대한 오름차순을 만들기 위해)
    pq.push({0, K});
    Dist[K] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i=0; i<vec[cur].size(); i++){
            int next = vec[cur][i].first;
            int ncost = vec[cur][i].second;

            if(Dist[next] > cost + ncost){
                Dist[next] = cost + ncost;
                pq.push({-Dist[next], next});
            }
        }
    }
}

int main(){
    cin >> V >> E >> K;
    for(int i=0; i<E; i++){
        int a, b, w;
        cin >> a >> b >> w;
        //노드, 가중치 순서
        vec[a].push_back({b, w});
    }

    for(int i=1; i<=V; i++){
        Dist[i] = INF;
    }

    Dijstra();

    for(int i=1; i<=V; i++){
        if(Dist[i] == INF)
            cout << "INF" << "\n";
        else
            cout << Dist[i] << "\n";
    }
}