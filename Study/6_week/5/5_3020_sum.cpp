#include <iostream>
using namespace std;

int sum[500001] = {0};

int main(){
    int n, h;
    cin >> n >> h;
    n /= 2;

    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        --sum[a];
        ++sum[h-b];
    }

    int result = n, cnt = 1, curr = n;
    for(int i=1; i<h; i++){
        curr += sum[i];
        if(curr == result) cnt++;
        else if(curr < result){
            result = curr;
            cnt = 1;
        }
    }

    cout << result << " " << cnt;
}