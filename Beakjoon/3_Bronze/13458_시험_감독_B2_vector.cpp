#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    long long ans =0;

    int n;
    cin >> n;
    while(n--){
        int x, flag = 1;
        cin >> x;
        for(int i=0; i<v.size(); i++){
            if(v[i].first == x){
                v[i].second++;
                flag = 0;
                break;
            }
        }
        if(flag)
            v.push_back({x, 1});
    }

    int b,c;
    cin >> b >> c;
    for(int i=0; i<v.size(); i++){
        long long temp = 1;
        v[i].first -= b;

        if(v[i].first > 0){
            if(v[i].first % c == 0){
                temp += v[i].first/c;
            }
            else{
                temp += (v[i].first/c +1);
            }
        }

        temp *= v[i].second;
        ans += temp;
    }
    cout << ans << "\n";
}