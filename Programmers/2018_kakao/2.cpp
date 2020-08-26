//비밀 지도 
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> bit;

void tentotwo(int num){
    for(int i=0; num > 0; i++){
        int b = num %2;
        bit[i] = b;
        num /= 2;
    }

} 

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int map[16][16] = {0};
    
    for(int i=0; i<n; i++){
        bit.assign(n, 0);
        tentotwo(arr1[i]);
        int temp = n-1;
        for(int k=0; k<n; k++){
            if(bit[k] == 1){
                map[i][temp] = 1;
            }
            temp--;
        }
    }

    for(int i=0; i<n; i++){
     bit.assign(n, 0);
        tentotwo(arr2[i]);
        int temp = n-1;
        for(int k=0; k<n; k++){
            if(bit[k] == 1){
                map[i][temp] = 1;
            }
            temp--;
        }
    }
    
    
    for(int i=0; i<n; i++){
        string s;
        for(int j=0; j<n; j++){
            if(map[i][j] == 1){
                s += "#";
            }
            else{
                s += " ";
            }
        }
        answer.push_back(s);
    }
    
    return answer;
}