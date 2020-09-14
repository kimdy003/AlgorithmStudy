#include <iostream>
using namespace std;
int map[21][21] = {0};
int n;
int ans = 987654321;


int gray(int x, int y, int d1, int d2){
    int temp[21][21] = {0};
    int array[5] = {0};

    temp[x][y] = 5;
    int i = 0;
    int j = 0;
    while(1){
        if(x+i <= n && 0 < y -i)
            temp[x+i][y-i] = 5;
        if(x+j <= n && y+j <= n)
            temp[x+j][y+j] = 5;
        if(x+d1+j <= n && 0 < y-d1+j && y-d1+j <=n)
            temp[x+d1+j][y-d1+j] = 5;
        if(x+d2+i <= n && 0 < y+d2-i && y+d2-i <= n)
            temp[x+d2+i][y+d2-i] = 5;

        if(i == d1 && j == d2) break;
        
        if(i != d1)
            i++;
        if(j != d2)
            j++;
    }

    bool flag;
    for(int i = x+1; i<x+d1+d2 && i <=n; i++){
        flag = true;
        for(int j=1; j<=n && flag; j++){
            if(temp[i][j] == 5){
                int cnt = j+1;
                while(1){
                    if(temp[i][cnt] == 5){
                        flag = false;
                        break;
                    }
                    temp[i][cnt++] = 5;
                }
            }
        }
    }


    for(int r = 1; r<=n; r++){
        for(int c = 1; c<=n; c++){
            if(temp[r][c] == 5){
                array[4] += map[r][c];
                continue;
            }
            if(temp[r][c] == 0){
                if(1 <= r && r <x+d1 && 1 <= c && c <=y){
                    temp[r][c] = 1;
                    array[0] += map[r][c];
                }
                else if(1<= r && r <= x+d2 && y < c && c<=n){
                    temp[r][c] = 2;
                    array[1] += map[r][c];
                }
                else if(x+d1<=r && r<=n && 1<=c && c < y-d1+d2){
                    temp[r][c] = 3;
                    array[2] += map[r][c];
                }
                else if(x+d2<r && r<=n && y-d1+d2 <= c && c <= n){
                    temp[r][c] = 4;
                    array[3] += map[r][c];
                }
            }
        }
    }

    int Min = 999999, Max = 0;
    for(int i=0; i<5; i++){
        Max = max(Max, array[i]);
        Min = min(Min, array[i]);
    }
    return Max - Min;

}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    for(int x =1; x<=n-2; x++){
        for(int y = 2; y<=n-1; y++){
            for(int d1 = 1; d1 <= n-x-1 && d1 <= y-1; d1++){
                for(int d2 = 1; d2 <= n-y && d2 <= n-x-1; d2++){
                    ans = min(ans, gray(x,y,d1,d2));
                }
            }
        }
    }

    cout << ans;
}