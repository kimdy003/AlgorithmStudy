#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int map[15][15] = {0};
int Max = 0;

void check(int y, int x){
    int sum = 0;
    for(int i= y; i <y+m; i++){
        for(int j= x; j<x+m; j++){
            sum += map[i][j];
        }
    }
    Max = max(Max, sum);
}

int main(){
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        Max = 0;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
            }
        }

        for(int i=0; i<=n-m; i++){
            for(int j=0; j<=n-m; j++){
                check(i, j);
            }
        }
        cout << "#" << test << " " << Max << "\n";
    }
}