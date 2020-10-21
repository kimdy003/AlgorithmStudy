#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k, cnt = 0;
deque<int> dq;
deque<bool> check;


void Move_Contain(){
    //벨트 움직임
    dq.push_front(dq.back());
    dq.pop_back();
    //벨트가 움직임으로 인한 로봇 움직임
    check.push_front(check.back());
    check.pop_back();
    //로봇 내리기
    check[n-1] = false;

    //로봇이 스스로 움직임
    for(int i=n-2; i>=0; i--){
        if(check[i] == false) continue;

        if(check[i+1] == false && dq[i+1] > 0){
            dq[i+1] -= 1;
            check[i+1] = true;
            check[i] = false;
            if(dq[i+1] == 0){
                cnt += 1;
            }
        }
    }
    //로봇 내리기
    check[n-1] = false;

    //벨트 처음칸에 로봇이 없으면 로봇 올리기
    if(check[0] == false && dq[0] > 0){
        check[0] = true;
        dq[0] -= 1;
        if(dq[0] == 0){
            cnt += 1;
        }
    }
}

int main(){
    cin >> n >> k;

    for(int i=0; i<2*n; i++){
        int a; cin >> a;
        dq.push_back(a);
        check.push_front(false);
    }

    int ans = 1;
    while(1){
        Move_Contain();

        if(k <= cnt){
            cout << ans;
            break;
        }
        ans += 1;
    }
}