#include <iostream>
#include <cstring>
using namespace std;
int score[100] = {0};
int check[10000] = {0};
int n;

int main(){
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        memset(score, 0 , sizeof(score));
        memset(check, 0, sizeof(check)); 
        check[0] = 1;
        cin >> n;
        int Max = 0, ans = 0;
        for(int i=0; i<n; i++){
            cin >> score[i];
            Max += score[i];
            for(int j=Max; j>= 0; j--){
                if(check[j]){
                    check[j+score[i]] = 1;
                }
            }
        }

        for(int i=0; i<= Max; i++){
            if(check[i])
                ans++;
        }

        cout << "#" << test << " " <<   ans   << "\n";

    }
}