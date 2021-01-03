#include <iostream>
#include <vector>

const int INF = 1e9;
using namespace std;

int n, m;
vector<pair<pair<int, int>, int>> graph;
int Dist[501];
bool Cycle = false;

void Bellman_Ford(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<graph.size(); j++){
            int start = graph[j].first.first;
            int end = graph[j].first.second;
            int cost = graph[j].second;

            if(Dist[start] == INF) continue;
            if(Dist[end] > Dist[start] + cost){
                Dist[end] = Dist[start] + cost;
                if(i == n){
                    Cycle = true;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({{a,b}, c});
    }

    fill(Dist, Dist+n+1, INF);
    Dist[1] = 0;
    Bellman_Ford();

    if(Cycle){
        cout << -1;
        return 0;
    }

    for(int i=2; i<=n; i++){
        cout << (Dist[i] != INF ? Dist[i] : -1) << "\n";
    }
}