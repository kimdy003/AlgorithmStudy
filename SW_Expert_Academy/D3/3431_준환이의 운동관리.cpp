#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        int l,u,x;
        cin >> l >> u >> x;

        cout << "#" << test << " " ;
        if(u < x ){
            cout << -1 << "\n";
            continue;
        }
        
        if(l <= x && x <= u){
            cout << 0 << "\n";
            continue;
        }

        if(x < l){
            cout << l-x << "\n";
        }

    }

}