#include <iostream>
#include <vector>

using namespace std;

int n, idx = 0, ans = 0;
vector<int> v, order;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    order.resize(n);

    while(1){
        if(order[v[idx]] == 1){
            int flag = 0, cnt = 0;
            ans++;
            for(int i=0; i<n; i++){
                if(order[i] == 0){
                    idx = i;
                    flag = 1;
                    break;
                }
                else 
                    cnt++;
            }
            if(flag == 0 || cnt == n) break;
        }
        else{
            order[v[idx]] = 1;
            idx = v[idx];
        }
    }

    int result = (ans == 1) ? 0 : ans;
    cout << result;
}