#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int map[1000] = {0};
int ans, Max;

int main(){
    int T = 10;
    for(int test=1; test<= T; test++){
        ans = 0;
        Max = 99999;
        int temp1, temp2;
        int n, x;
        cin >> n;
        for(int i=0; i< n; i++){
            cin >> x;
            map[i] = x;
            if(i >= 4){
                temp1 = max(map[i-4], map[i-3]);
                temp2 = max(map[i-1], map[i]);
                Max = max(temp1, temp2);
                if(map[i-2] > Max)
                    ans += map[i-2] - Max;
                
            }
            else{
                continue;
            }
        }
        cout << "#" << test << " " << ans << "\n";
    }
    return 0;
}