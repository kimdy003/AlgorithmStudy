#include <iostream>

using namespace std;

int v, e;
int parent[100001];

int Find(int x){
    if(parent[x] == x)
        return x;
    
    //��Ʈ ��带 ã�� ������ ��� ȣ��
    return Find(parent[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    //�� ���� ��尡 �θ� ����...
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

    cout << "�� ���Ұ� ���� ���� \n";
    for(int i=1; i<=v; i++){
        cout << Find(i) << " ";
    }
    cout << "\n";

    cout << "�θ� ��� ���̺� \n";
    for(int i=1; i<=v; i++){
        cout << parent[i] << " ";
    }
    cout << "\n";
}