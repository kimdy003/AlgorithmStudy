#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    long long ans =0;
    int room[1000000];

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> room[i];
    }

    int b,c;
    cin >> b >> c;
    for(int i=0; i<n; i++){
        room[i] -= b;
        ans++;

        if(room[i] > 0){
            if(room[i] % c == 0){
                ans += room[i]/c;
            }
            else{
                ans += (room[i]/c+1);
            }
        }

    }
    cout << ans << "\n";
}