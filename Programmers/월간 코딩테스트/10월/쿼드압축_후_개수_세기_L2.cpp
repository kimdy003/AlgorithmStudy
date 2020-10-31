#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> board;
vector<int> answer{0, 0};


void Search(int y, int x, int size){
    int half = size/2;
    bool flag = true;
    int pivot = board[y][x];

    if(size < 2){
        if(pivot == 1)
            answer[1]++;
        else
            answer[0]++;
        return;
    }

    for (int i = y; i < y+size && flag; i++){
        for (int j = x; j < x+size; j++){ 
            if (pivot != board[i][j]){
                flag = false;
                break;
            }
        }
    }

    if(flag){
        if(pivot == 1){
            answer[1]++;
        }
        else
            answer[0]++;
        return;
    }

    Search(y, x, half);
    Search(y, x+half, half);
    Search(y+half, x, half);
    Search(y+half, x+half, half);
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    
    int size = arr.size();
    board = arr;
    Search(0, 0, size);

    return answer;
}


int main(){
    int a[8][8] = {{1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1}};
    vector<vector<int>> b;

    for(int i=0; i<8; i++){
        b.push_back({a[i][0], a[i][1], a[i][2], a[i][3], a[i][4], a[i][5], a[i][6], a[i][7]});
    }

    solution(b);
}