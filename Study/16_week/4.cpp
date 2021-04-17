#include <iostream>
#include <vector>

using namespace std;

int n, k;
int dp[101][100001];
vector<pair<int, int>> walk, bike;

int main(){
    cin >> n >> k;
    int a[4];
    for(int i=0; i<n; i++){
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        walk.push_back({a[0], a[1]});
        bike.push_back({a[2], a[3]});
    }

    for(int i=0; i<n; i++){
        
        }
    }
}