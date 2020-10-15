#include <iostream>
#include <queue>

#define size 20
using namespace std;
int map[size][size];
int n, ans = 0;

int get_max(){
    int Max = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(Max < map[i][j])
                Max = map[i][j];
        }
    }
    return Max;
}

void calculation(int type){
   queue<int> q;

    //좌
    if(type == 0){
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                if(map[i][j])
                    q.push(map[i][j]);
                map[i][j] = 0;
            }

            int idx = n-1;

            while(!q.empty()){
                int data = q.front();
                q.pop();

                if(map[i][idx] == 0){
                    map[i][idx] = data;
                }
                else if(map[i][idx] == data){
                    map[i][idx] *= 2;
                    idx--;
                }
                else{
                    idx--;
                    map[i][idx] = data;
                }
            }
        }

    }

    //우
    if(type == 1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j])
                    q.push(map[i][j]);
                map[i][j] = 0;
            }

            int idx = 0;

            while(!q.empty()){
                int data = q.front();
                q.pop();

                if(map[i][idx] == 0){
                    map[i][idx] = data;
                }
                else if(map[i][idx] == data){
                    map[i][idx] *= 2;
                    idx++;
                }
                else{
                    idx++;
                    map[i][idx] = data;
                }
            }
        }
    }

    //상
    if(type == 2){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[j][i])
                    q.push(map[j][i]);
                map[j][i] = 0;
            }

            int idx = 0;

            while(!q.empty()){
                int data = q.front();
                q.pop();

                if(map[idx][i] == 0){
                    map[idx][i] = data;
                }
                else if(map[idx][i] == data){
                    map[idx][i] *= 2;
                    idx++;
                }
                else{
                    idx++;
                    map[idx][i] = data;
                }
            }
        }
    }

   //하
    if(type == 3){
        for(int i = 0; i<n; i++){
            for(int j = n-1; j>=0; j--){
                if(map[j][i])
                    q.push(map[j][i]);
                map[j][i] = 0;
            }

            int idx = n-1;

            while(!q.empty()){
                int data = q.front();
                q.pop();

                if(map[idx][i] == 0){
                    map[idx][i] = data;
                }
                else if(map[idx][i] == data){
                    map[idx][i] *= 2;
                    idx--;
                }
                else{
                    idx--;
                    map[idx][i] = data;
                }
            }

        }
    }
}

void dfs(int cnt){
    if(cnt == 5){
        ans = max(ans, get_max());
        return;
    }

    int temp[size][size] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = map[i][j];
        }
    }

    for(int i=0; i<4; i++){
        calculation(i);
        dfs(cnt+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                map[i][j] = temp[i][j];
            }
        }
        
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    dfs(0);

    cout << ans << "\n";
    return 0;
}