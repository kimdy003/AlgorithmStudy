#include <iostream>
#include <vector>
#include <queue>

const int MAX = 501;
using namespace std;

int n;
int Bulid_time[MAX];
int Indegree[MAX];
int answer[MAX];
vector<int> v[MAX];

void Topoloy(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(Indegree[i] == 0){
            q.push(i);
            answer[i] = Bulid_time[i];
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i=0; i<v[now].size(); i++){
            int next = v[now][i];
            Indegree[next]--;

            answer[next] = max(answer[next], answer[now]+Bulid_time[next]);
            if(Indegree[next] == 0)
                q.push(next);
        }
    }
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> Bulid_time[i];

        while(1){
            int a; cin >> a;
            if(a == -1) break;
            v[a].push_back(i);
            Indegree[i]++;
        }
    }

    Topoloy();
    for(int i=1; i<=n; i++){
        cout << answer[i] << "\n";
    }
}