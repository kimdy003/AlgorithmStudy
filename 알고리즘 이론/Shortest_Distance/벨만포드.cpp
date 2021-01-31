#include <iostream>
#include <vector>

const int INF = 1e9; //무한을 의미, 10억
using namespace std;

//노드, 간선
int N, M;
vector<pair<pair<int, int>, int>> graph;
//최단 거리 저장 배열
int Dist[10001];
//음수 싸이클 존재 여부
bool Cycle = false;


void Bellman_Fore(){
    for(int i=1; i <= N; i++){
        for(int j=0; j < graph.size(); j++){
            int start = graph[j].first.first;
            int end = graph[j].first.second;
            int cost = graph[j].second;

            if(Dist[start] == INF) continue;
            if(Dist[end] > Dist[start] + cost){
                Dist[end] = Dist[start] + cost;
                if(i == N){
                    Cycle = true;
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        //출발, 도착, 비용
        int a, b, c;

        graph.push_back({{a, b}, c});
    }


    fill(Dist, Dist+N, INF);
    Dist[1] = 0;

    Bellman_Fore();
    if(Cycle){
        cout << "음의 사이클이 존재하는 그래프" << "\n";
    }   
    else{
        cout << "음의 사이클이 존재하지 않는, 정상적인 그래프" << "\n";
    }
}