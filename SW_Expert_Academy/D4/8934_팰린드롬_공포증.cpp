#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        string s;
        cin >> s;
        int cnt[3] = {0};
        int Min = 987654321;
        bool flag = true;

        for(int i=0; i<s.size(); i++){
            cnt[s[i] - 'a']++;
        }

        for(int i=0; i<3; i++){
            if(Min > cnt[i])
                Min = cnt[i];
        }

        for(int i=0; i<3; i++){
            cnt[i] -= Min;
            if(cnt[i] >= 2){
                flag = false;
                break;
            }
        }

        cout << "#" << test << " " ;
        if(flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";


    }
}