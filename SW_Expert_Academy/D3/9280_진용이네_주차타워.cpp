#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m;
int r_i[101];
int check_r[101];
int w_i[10001];
int ans;


int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        ans = 0;
        queue<int> q;
        memset(r_i, 0, sizeof(r_i));
        memset(w_i, 0, sizeof(w_i));
        memset(check_r, 0, sizeof(check_r));
        
        cin >> n >> m;

        for(int i=1; i<=n; i++){
            cin >> r_i[i];
        }
        for(int i=1; i<=m; i++){
            cin >> w_i[i];
        }

        int x;
        int price;
        bool full;
        for(int i=0; i<2*m; i++){
            cin >> x;
            if(x >0){
                for(int j=1; j<=n; j++){
                    if(check_r[j] == 0){
                        full = false;
                        check_r[j] = x;
                        price = r_i[j];
                        break;
                    }
                    full = true;
                }

                if(!full){
                    ans += price * w_i[x];
                }
                else{
                    q.push(x);
                }
            }
            else{
                for(int j=1; j<=n; j++){
                    int temp = check_r[j] + x;
                    if(temp == 0){
                        check_r[j] = 0;
                        if(q.size() != 0){
                            check_r[j] = q.front();
                            price = r_i[j];
                            ans += price * w_i[q.front()];
                            q.pop();
                        }
                        break;
                    }
                }

            }
        }

        cout << "#" << test << " " << ans << "\n";


    }
}