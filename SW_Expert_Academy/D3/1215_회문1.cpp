#include <iostream>
using namespace std;
char map[8][8];
int n;
int ans = 0;

void palindrome(int y, int x){
    string temp[2];
    for(int i=0; i<2; i++)
        temp[i] += map[y][x];

    for(int i=1; i<n; i++){
        if(y+i < 8)
            temp[0] += map[y+i][x];

        if(x+i < 8)
            temp[1] += map[y][x+i];
    }

    bool flag;
    for(int i=0; i<2; i++){
        flag = true;
        if(temp[i].size() == n){
            string ss = temp[i];
            for(int i=0, j=n-1; j >= i; i++,j--){
                if(ss[i] != ss[j]){
                    flag = false;
                    break;
                }
            }

            if(flag)
                ans++;
        }
    }

}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    for(int test = 1; test <= 1; test++){
        cin >> n;
        ans = 0;
        string s;
        for(int i=0; i< 8; i++){
            cin >> s;
            for(int j=0; j<8; j++){
                map[i][j] = s[j];
            }
        }

        if(n == 1){
            ans = 64;
        }
        else{
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    palindrome(i,j);
                }
            }
        }

        cout << "#" << test << " " << ans << "\n";

    }
}