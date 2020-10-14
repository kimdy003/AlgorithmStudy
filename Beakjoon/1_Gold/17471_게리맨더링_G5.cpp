#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, ans = 987654321;
int people[11] = {0};
bool Select[11];
bool visit[11];
bool connect[11][11];

bool Check_connection(vector<int> area, bool T){
    memset(visit, false, sizeof(visit));
    queue<int> q;
    q.push(area[0]);
    visit[area[0]] = true;
    int cnt = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(connect[x][i] == true && Select[i] == T && visit[i] == false){
                visit[i] = true;
                cnt++;
                q.push(i);
            }
        }
    }

    if(area.size() == cnt)
        return true;
    return false;

}

bool check(){
    vector<int> a, b;
    for(int i=1; i<=n; i++){
        if(Select[i] == true) 
            a.push_back(i);
        else
            b.push_back(i);
    }

    if(a.size() == 0 || b.size() == 0) return false;

    bool a_state = Check_connection(a, true);
    if(a_state == false) return false;

    bool b_state = Check_connection(b, false);
    if(b_state == false) return false;

    return true;
}

void Calculate(){
    int a_num = 0, b_num = 0;

    for(int i=1; i<=n; i++){
        if(Select[i] == true)
            a_num += people[i];
        else
            b_num += people[i];
    }

    int sum = max(a_num, b_num) - min(a_num, b_num);
    ans = min(ans, sum);
}

void DFS(int idx, int cnt){
    if(cnt >= 1){
        if(check() == true){
            Calculate();
        }
    }

    for(int i=idx; i<=n; i++){
        if(Select[i] == false){
            Select[i] = true;
            DFS(i, cnt+1);
            Select[i] = false;
        }
    }
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> people[i];
    }

    for(int i=1; i<=n; i++){
        int a; cin >> a;
        for(int j=0; j<a; j++){
            int b; cin >> b;
            connect[i][b] = true;
            connect[b][i] = true;
        }
    }

    DFS(1, 0);

    if(ans == 987654321)
        cout << -1;
    else
        cout << ans;
    return 0;
}