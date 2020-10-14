#include <iostream>
#include <cmath>

using namespace std;

int N, L, ans = 0;
int map[100][100];

bool Can_Make(int y, int x, bool flag){
    if(flag){
        int pivot = map[y][x+1];
        for(int i=x+2; i<=x+L; i++){
            if(pivot != map[y][i])
                return false;
        }
    }
    else{
        int pivot = map[y+1][x];
        for(int i=y+2; i<=y+L; i++){
            if(pivot != map[i][x])
                return false;
        }
    }

    return true;
}

int main(){
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    int row = 0;
    int col = 0;

    while(row != N){
        int x = 0;
        int before = 1;
        bool flag = true;

        while(1){
            if(x == N-1)
                break;
            
            if(map[row][x] == map[row][x+1])
                before++;
            else if(map[row][x]+1 == map[row][x+1]){
                if(before >= L){
                    before = 1;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(map[row][x] == map[row][x+1]+1){
                if(Can_Make(row, x, true) == true){
                    x = x+L;
                    before = 0;
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(abs(map[row][x] - map[row][x+1]) >= 2){
                flag = false;
                break;
            }

            x += 1;
        }

        if(flag){
            ans++;
        }
        row += 1;
    }

    while(col != N){
        int y = 0;
        int before = 1;
        bool flag = true;

        while(1){
            if(y == N-1)
                break;
            
            if(map[y][col] == map[y+1][col])
                before++;
            else if(map[y][col]+1 == map[y+1][col]){
                if(before >= L){
                    before = 1;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(map[y][col] == map[y+1][col]+1){
                if(Can_Make(y, col, false) == true){
                    y = y+L;
                    before = 0;
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(abs(map[y][col] - map[y+1][col]) >= 2){
                flag = false;
                break;
            }
            y += 1;
        }

        if(flag){
            ans++;
        }

        col += 1;
    }

    cout << ans;
}