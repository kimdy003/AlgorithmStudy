#include <iostream>
#include <cstring>
using namespace std;
int map[49][49];
int ans;

int main(){
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        memset(map, 0, sizeof(map));
        ans = 0;

        int n;
        cin >> n;
        string s;
        for(int i=0; i<n; i++){
            cin >> s;
            for(int j=0; j<n; j++){
                map[i][j] = s[j] - '0';
            }
        }

        int cnt = n/2;
        int x = 1;
        for(int i=0; i<n; i++){
            if(i < n/2){
                for(int k=0; k<x; k++){
                    ans += map[i][cnt+k];
                }
                cnt -= 1;
                x += 2;
            }
            else if(i == n/2){
                for(int k=0; k<x; k++){
                    ans += map[i][cnt+k];
                }
                cnt += 1;
                x -= 2;
            }
            else{
                for(int k=0; k<x; k++){
                    ans += map[i][cnt+k];
                }
                cnt += 1;
                x -= 2;
            }
        }

        cout << "#" << test << " " << ans << "\n";

    }
}
