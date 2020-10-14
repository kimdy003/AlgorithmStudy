#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
int t, n, pre[1010], in[1010];
map<int, int> mp;
 
void go(int s, int e,int x, int y) {
 
    if (s > e || x > y) return;
 
    int root = pre[s];
    int pos = mp[pre[s]];
 
    go(s + 1, s + (pos - x), x, pos - 1);
    go(s + (pos - x) + 1, e, pos + 1, y);
    printf("%d ", root);
}
int main() {
    scanf(" %d", &t);
    while (t--) {
        memset(pre, 0, sizeof(pre));
        mp.clear();
        scanf(" %d", &n);
        for (int i = 1; i <= n; i++) scanf(" %d", &pre[i]);
        for (int i = 1; i <= n; i++) {
            int x; scanf(" %d", &x);
            in[i] = x;
            mp[x] = i;
        }
        go(1, n, 1, n); puts("");
    }
}
