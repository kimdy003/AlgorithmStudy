#include <iostream>
#include <queue>

using namespace std;

int n, ans = 0;
int Games[51][10] = {0};
int player[10] = {0};
bool check[10];

void Play_Ball(){
    int score = 0;
    int start = 1;

    for(int i=1; i<=n; i++){
        queue<int> q;
        int out = 0;

        for(int i=0; i<3; i++){
            q.push(0);
        }

        while(1){
            int play = Games[i][player[start]];

            if(play == 0){
                out++;
            }

            else if(play == 1){
                score += q.front();
                q.pop();

                q.push(1);
            }

            else if(play == 2){
                for(int i=0; i<2; i++){
                    score += q.front();
                    q.pop();
                }

                q.push(1);
                q.push(0);
            }

            else if(play == 3){
                for(int i=0; i<3; i++){
                    score += q.front();
                    q.pop();
                }

                q.push(1);
                q.push(0);
                q.push(0);
            }

            else if(play == 4){
                q.push(1);
                for(int i=0; i<4; i++){
                    score += q.front();
                    q.pop();
                }

                for(int i=0; i<3; i++){
                    q.push(0);
                }
            }

            start += 1;
            if(start == 10){
                start = 1;
            }

            if(out == 3){
                break;
            }
        }

        ans = max(ans, score);
    }
}

void DFS(int Idx){
    if(Idx == 10){
        Play_Ball();
        return;
    }

    for(int i=1; i<10; i++){
        if(check[i] == true)
            continue;
        
        player[i] = Idx;
        check[i] = true;
        DFS(Idx+1);
        check[i] = false;
    }
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<10; j++){
            cin >> Games[i][j];
        }
    }

    player[4] = 1;
    check[4] = true;
    DFS(2);

    cout << ans << "\n";
}