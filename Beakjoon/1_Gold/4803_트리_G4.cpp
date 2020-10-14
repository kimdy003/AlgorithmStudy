#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;

int main(){
    int tc = 0;
    while(1){
        cin >> n >> m;

        if(n == 0 && m == 0) return 0;

        vector<int> graph[501];
        bool visit[501];
        fill(visit, visit+501, false);

        int cnt = 0;

        for(int i=0; i<m; i++){
            int a, b; cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> q;
        for(int i=1; i<=n; i++){
            int edge = 0;
            int node = 0;

            if(visit[i] == false){
                q.push(i);
                cnt++;

                while(!q.empty()){
                    int cur = q.front();
                    q.pop();

                    if(visit[cur]) 
                        continue;

                    node++;
                    visit[cur] = true;

                    for(int j=0; j<graph[cur].size(); j++){
                        edge++;
                        q.push(graph[cur][j]);
                    }
                }

                if(edge/2 != node-1)
                    cnt--;
            }
        }

        if (cnt >= 2)
            printf("Case %d: A forest of %d trees.\n", ++tc, cnt);
        else if (cnt == 1)
            printf("Case %d: There is one tree.\n", ++tc);
        else
            printf("Case %d: No trees.\n", ++tc);

    }
}