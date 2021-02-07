#include <iostream>
#include <algorithm>

const int MAX = 1e9+1;
using namespace std;

int n;
pair<int, int> hw[1000000];
bool day[MAX];

bool cmp(pair<int, int> a, pair<int, int> b){
    //끝내야되는 날(a.second, b.second)이 첫번째 기준 내림차순
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> hw[i].first >> hw[i].second;
    }

    sort(hw, hw+n, cmp);
    int idx = MAX;
    for(int i=0; i<n; i++){
#if 1
        int d = hw[i].first;
        if(hw[i].second <= idx){
            idx = hw[i].second-hw[i].first;
        }
        else{
            idx = idx - hw[i].first;
        }
#else 
        int d = hw[i].first;

        if(day[hw[i].second] == false){
            idx = hw[i].second;
            while(d--){
                day[idx--] = true;
            }
        }
        else{
            while(d--){
                day[idx--] = true;
            }
        }
#endif
    }

    cout << idx;
}