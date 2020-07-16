#include <iostream>
#include <cstring>
using namespace std;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        int n, ans = 0;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        for(int i=0; i<n; i++){
            if(s1[i] == s2[i])
                ans++;
        }
        cout << "#" << test << " " << ans << "\n";
    }
}