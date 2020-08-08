#include <iostream>
#include <algorithm>
using namespace std;
int dia[10000];

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        int n, k;
        cin >> n >> k;
        for(int i=0; i<n; i++){
            cin >> dia[i];
        }

        sort(dia, dia+n);

        int res, ans = 0;
        for(int i=0; i<n; i++){
            res = 1;
            for(int j = i+1; j<n; j++){
                if(dia[j] - dia[i] <= k)
                    res++;
                else
                    break;
            }
            ans = max(ans, res);
        }

        cout << "#" << test << " " << ans << "\n";

    }
}