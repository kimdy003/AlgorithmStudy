#include <iostream>
#include <algorithm>
#include <vector>

const int MAX = 5;
using namespace std;

int n, sum;
int arr[MAX], color[MAX], total[MAX];
vector<pair<pair<int, int>, int>> v;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.first.first < b.first.first;
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        v.push_back({{b, a}, i});
    }

    sort(v.begin(), v.end());

    for(int i=0, j = 0; i<n; i++){
        while(v[j].first.first < v[i].first.first){
            sum += v[j].first.first;
            color[v[j].first.second] += v[j].first.first;
            j += 1;
        }
        // 모든 누적합 - 자기와 같은 색깔을 가지고 있는 볼
        total[v[i].second] = sum - color[v[i].first.second];
    }

    for(int i=0; i<n; i++){
        cout << total[i] << "\n";

    }

   
}