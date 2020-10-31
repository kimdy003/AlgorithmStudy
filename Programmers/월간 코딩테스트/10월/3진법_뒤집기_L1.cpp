#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if(n == 1){
        return 1;
    }
    
    string s = "";
    while(n){
        int temp  = n%3;
        s = s + to_string(temp);
        n /= 3;
    }

    int mul = 1;
    for(int i=s.size()-1; i>=0; i--){
        int temp = (s[i]-'0') * mul;
        mul *= 3;
        answer += temp;
    }
    
    return answer;
}

int main(){
    solution(45);
}