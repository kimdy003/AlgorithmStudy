#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 10001;
//depth : 노드의 깊이
//ac[x][y] : x의 2^y번재 조상을 의마
int depth[MAX];
int ac[MAX][20];
vector<int> graph[MAX];
int max_level;

void GetTree(int cur, int parent){
    //cur의 깊이는 부모노드깊이 +1 
    depth[cur] = depth[parent]+1;

    //cur의 1번째(2^0)조상은 부모노드
    ac[cur][0] = parent;

    //MAX(10001)개의 노드에 대한 최대 깊이
    //2^max_level까지 갈 수 있다.
    max_level = (int)floor(log2(MAX));
    for(int i=1; i<=max_level; i++){
        //temp : cur의 2^(i-1)번째 조상
        int temp = ac[cur][i-1];

        // cur의 2^i번째 조상은 
        // cur의 2^(i-1)번째 조상(temp)의 2^(i-1)번째 조상과 같다는 의미
        ac[cur][i] = ac[temp][i-1];
    }

    //dfs 알고리즘
    for(int i=0; i<graph[cur].size(); i++){
        int next = graph[cur][i];
        if(next != parent){
            GetTree(next, cur);
        }
    }

}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    depth[0] = -1;

    //루트노드인 1부터 tree 생성
    GetTree(1, 0);

    //쿼리문 시작
    while(m--){
        int a, b;
        cin >> a >> b;

        if(depth[a] != depth[b]){
            //depth[b] >= depth[a]가 되도록 swap
            if(depth[a] > depth[b])
                swap(a, b);

            //b를 올려서 depth를 맞춰준다.
            for(int i=max_level; i>=0; i--){
                if(depth[a] <= depth[ac[b][i]])
                    b = ac[b][i];
            }
        }

        int lca = a;
        if(a != b){
            for(int i=max_level; i>=0; i--){
                if(ac[a][i] != ac[b][i]){
                    a = ac[a][i];
                    b = ac[b][i];
                }
                lca = ac[a][i];
            }
        }
        cout << lca;
    }
}