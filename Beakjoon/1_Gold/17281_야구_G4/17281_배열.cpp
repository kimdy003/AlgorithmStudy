#include <iostream>
#include <cstring>

using namespace std;

int n, ans = 0;
int Games[51][10];
int Order[10];
bool Check[10];

void Play_Ball(){
    int score = 0;
    int start = 1;
    int Base_State[4];

    for(int i=1; i<=n; i++){
        int out = 0;
        bool flag = false;
        memset(Base_State, 0, sizeof(Base_State));

        while (1){
            for(int j=start; j<10; j++){
                int play = Games[i][Order[j]];

                if(play == 0){
                    out++;
                }

                else if(play == 1){
                    for(int go = 3; go > 0 ; go--){
                        if(Base_State[go] == 1){
                            if(go == 3){
                                score++;
                                Base_State[go] = 0;
                            }
                            else{
                                Base_State[go+1] = 1;
                                Base_State[go] = 0;
                            }
                        }
                    }
                    Base_State[1] = 1;
                }

                else if(play == 2){
                    for(int go = 3; go > 0 ; go--){
                        if(Base_State[go] == 1){
                            if(go == 3 || go == 2){
                                score++;
                                Base_State[go] = 0;
                            }
                            else{
                                Base_State[go+2] = 1;
                                Base_State[go] = 0;
                            }
                        }
                    }
                    Base_State[2] = 1;
                }

                else if(play == 3){
                    for(int go = 3; go > 0 ; go--){
                        if(Base_State[go] == 1){
                            score++;
                            Base_State[go] = 0;
                        }
                    }
                    Base_State[3] = 1;
                }

                else if(play == 4){
                    for(int go = 3; go > 0 ; go--){
                        if(Base_State[go] == 1){
                            score++;
                            Base_State[go] = 0;
                        }
                    }
                    score++;
                }

                if(out == 3){
                    start = j+1;
                    if(start == 10)
                        start = 1;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
            start = 1;
        }
    }

    ans = max(ans, score);
}

void DFS(int Idx){
    if(Idx == 10){
        Play_Ball();
        return;
    }

    for(int i=1; i<10; i++){
        if(Check[i] == true) continue;

        Check[i] = true;
        Order[i] = Idx;
        DFS(Idx + 1);
        Check[i] = false;
    }
}

int main(){
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<10; j++){
            cin >> Games[i][j];
        }
    }

    Order[4] = 1;
    Check[4] = true;
    DFS(2);

    cout << ans << "\n";
}