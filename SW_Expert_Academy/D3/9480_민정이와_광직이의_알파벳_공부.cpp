#include <iostream>
#include <cstring>
using namespace std;
int alpha[26];
string words[15];
bool check[15];
int n, ans;

void search(){
    memset(alpha, 0, sizeof(alpha));
    for(int i=0; i<n; i++){
        if(!check[i]){
            for(int j=0; j<words[i].size(); j++){
                alpha[words[i][j]-97]++;
            }
        }
    }

    for(int i=0; i<26; i++){
        if(alpha[i] == 0){
            return;
        }
    }
    ans++;
}

void dfs(int idx, int cnt, int end){
    if(cnt == end){
        search();
        return;
    }

    for(int i=idx; i<n; i++){
        if(!check[i])
            continue;
        check[i] = false;
        dfs(i, cnt+1, end);
        check[i] = true;
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        memset(check, true, sizeof(check));
        ans = 0;

        cin >> n;
        string s;
        for(int i=0; i<n; i++){
            cin >> s;
            words[i] = s;
        }

        for(int i=1; i<=n; i++){
            dfs(0, 0, i);
        }

        cout << "#" << test <<" " << ans << "\n" ;
    }
}