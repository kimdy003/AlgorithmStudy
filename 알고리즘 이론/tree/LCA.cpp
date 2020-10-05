#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 10001;
//depth : ����� ����
//ac[x][y] : x�� 2^y���� ������ �Ǹ�
int depth[MAX];
int ac[MAX][20];
vector<int> graph[MAX];
int max_level;

void GetTree(int cur, int parent){
    //cur�� ���̴� �θ������ +1 
    depth[cur] = depth[parent]+1;

    //cur�� 1��°(2^0)������ �θ���
    ac[cur][0] = parent;

    //MAX(10001)���� ��忡 ���� �ִ� ����
    //2^max_level���� �� �� �ִ�.
    max_level = (int)floor(log2(MAX));
    for(int i=1; i<=max_level; i++){
        //temp : cur�� 2^(i-1)��° ����
        int temp = ac[cur][i-1];

        // cur�� 2^i��° ������ 
        // cur�� 2^(i-1)��° ����(temp)�� 2^(i-1)��° ����� ���ٴ� �ǹ�
        ac[cur][i] = ac[temp][i-1];
    }

    //dfs �˰���
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

    //��Ʈ����� 1���� tree ����
    GetTree(1, 0);

    //������ ����
    while(m--){
        int a, b;
        cin >> a >> b;

        if(depth[a] != depth[b]){
            //depth[b] >= depth[a]�� �ǵ��� swap
            if(depth[a] > depth[b])
                swap(a, b);

            //b�� �÷��� depth�� �����ش�.
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