#include <iostream>

using namespace std;

int v, e;
int parent[100001];

int Find(int x){
    if(parent[x] == x)
        return x;
    
    //루트 노드를 찾을 때까지 재귀 호출
    return Find(parent[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    //더 작은 노드가 부모 노드로...
    if(a < b)
        parent[b] = a;
    
    else
        parent[a] = b;
}

int main(){
    cin >> v >> e;

    for(int i=1; i<=v; i++){
        parent[i] = i;
    }

    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    cout << "각 원소가 속한 집합 \n";
    for(int i=1; i<=v; i++){
        cout << Find(i) << " ";
    }
    cout << "\n";

    cout << "부모 노드 테이블 \n";
    for(int i=1; i<=v; i++){
        cout << parent[i] << " ";
    }
    cout << "\n";
}