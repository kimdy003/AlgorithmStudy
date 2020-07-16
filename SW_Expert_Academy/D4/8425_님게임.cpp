#include <iostream>
#include <cstring>
using namespace std;
int n, ans;
int stone[1000];

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        ans = 0;
        memset(stone, 0, sizeof(stone));
        cin >> n;

        for(int i=0; i<n; i++){
            cin >> stone[i];
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            sum ^= stone[i];
        }

        cout << "#" << test << " ";
        if(sum == 0){
            cout << 0 << "\n";
            continue;
        }
        else{
            for(int i=0; i<n; i++){
                int temp = sum^stone[i];
                if((sum ^ stone[i]) <= stone[i])
                    ans++;
            }
            cout << ans << "\n";
        }
    }
    
}