#include <iostream>
using namespace std;
int snack[1000];
int ans;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        int n, m;
        cin >> n >> m;

        for(int i=0; i<n; i++){
            cin >> snack[i];
        }

        int sum;
        ans = 0;
        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                sum = snack[i] + snack[j];
                if(sum <= m){
                    if(ans < sum)
                        ans = sum;
                    flag = true;
                }
            }
        }

        cout << "#" << test << " " ;
        if(flag){
            cout << ans << "\n";
        }
        else{
            cout << "-1" << "\n";
        }
    }
}