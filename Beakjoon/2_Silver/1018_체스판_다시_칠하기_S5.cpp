#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char board[50][50];

//(0, 0)이 W인 체스보드
string white[8] = {
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" }
};

//(0, 0)이 B인 체스보드
string black[8] = {
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" }
};

int min(int a, int b){
    return a>b? b:a;
}

int chess(int x, int y){
    int cntW = 0, cntB = 0;
    for(int i = x; i<x+8; i++)
        for(int j = y; j<y+8; j++){
            if(board[i][j] != black[i-x][j-y])
                cntB++;
            if(board[i][j] != white[i-x][j-y])
                cntW++;
        }

    return min(cntW, cntB);
}


int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> board[i][j];
        }
    }

    int Answer = 99999;

    for(int i = 0; i<n-7; i++){
        for(int j = 0; j< m-7; j++){
            Answer = min(Answer, chess(i, j));
        }
    }

    cout << Answer;
}