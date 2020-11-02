#include <iostream>
#include <vector>
using namespace std;
vector<int> v[16];
bool check[16];
int weight[16][16];
int n, min = 999, temp_f=0;

void dfs(int node){
    check[node] = false;
    for(int i= 0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == true){
            temp_f += weight[node][next];
            dfs(next);
        }
        
    }
}


void init(){
    for(int i= 0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> weight[i][j];
        }
        check[i] = true;
        v[i].clear();
    }
}

int main(){
    cin >> n ;

    init();

    for(int i= 0; i<n; i++){
        for(int j= 0; j<n; j++){
            if(weight[i][j]){
                v[i].push_back(j);
            }
        }
        //시작한 도시로 돌아오기
        v[i].push_back(1);
    }


    dfs(1);
    int min = min > temp_f ? temp_f : min ;

    cout << min << endl;
}