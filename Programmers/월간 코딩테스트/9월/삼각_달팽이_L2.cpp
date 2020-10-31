#include <string>
#include <iostream>
#include <vector>

using namespace std;

int map[1001][1001];

vector<int> solution(int n) {
    vector<int> answer;
    
    int row = 1, col = 1;
    int cnt = 1;
    
    int type = 0;
    for(int i=n; i>0; i--){
        
        if(type == 0){
            for(int j=0; j<i; j++){
                map[row][col] = cnt++; 
                row += 1;
            }
            row -= 1;
            col += 1;
            type = 1;
        }
        else if(type == 1){
            for(int j=0; j<i; j++){
                map[row][col] = cnt++;
                col += 1;
            }
            col -= 2;
            row -= 1;
            type = 2;
        }
        else if(type == 2){
            for(int j=0; j<i; j++){
                map[row][col] = cnt++;
                row -= 1; col -= 1;
            }
            row += 2;
            col += 1;
            type = 0;
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            answer.push_back(map[i][j]);
        }
        
    }
    return answer;
}

int main(){
    solution(4);
}