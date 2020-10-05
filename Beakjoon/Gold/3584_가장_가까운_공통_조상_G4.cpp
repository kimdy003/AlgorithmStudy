#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n;
const int MAX = 100001;
vector<vector<int>> v;
int ac[MAX][20];
int depth[MAX];
int parent[MAX];
int max_level;

void Make_Tree(int cur, int parent){
    depth[cur] = depth[parent] +1;
    ac[cur][0] = parent;

    for(int i=1; i<max_level; i++){
        int temp = ac[cur][i-1];
        ac[cur][i] = ac[temp][i-1];
    }

    max_level = (int)floor(log2(MAX));

    for(int i=0; i<v[cur].size(); i++){
        if(v[cur][i] != parent){
            Make_Tree(v[cur][i], cur);
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(depth, 0, sizeof(depth));
        memset(ac, 0, sizeof(ac));
        memset(parent, 0, sizeof(parent));
        for(int i=0; i<MAX; i++)
            v[i].clear();

        cin >> n;

        for(int i=0; i<n-1; i++){
            int a, b; cin >> a >> b;
            
            v[b].push_back(a);
            v[a].push_back(b);

            parent[b] = a;
        }

        int root;
        for(int i=1; i<=n; i++){
            if(parent[i] == 0){
                root = i;
                break;
            }
        }

        depth[0] = -1;
        Make_Tree(root, 0);

        int x, y;
        cin >> x >> y;
        
        if(depth[x] != depth[y]){
            if(depth[x] > depth[y])
                swap(x, y);
            
            for(int i = max_level-1; i>=0; i--){
                if(depth[x] <= depth[ac[y][i]])
                    y = ac[y][i];
            }
        }

        int lca = x;
        if(x != y){
            for(int i= max_level-1; i>=0; i--){
                if(ac[x][i] != ac[y][i]){
                    x = ac[x][i];
                    y = ac[y][i];
                }
                lca = ac[x][i];
            }
        }
        
        cout << lca << "\n";
    }
}