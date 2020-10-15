//다트 게임
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
int num[3];

int solution(string dartResult) {
    int answer = 0;
    
    int cnt = 0;
    for(int i=0; i<dartResult.size(); i++){
        if('0' <= dartResult[i] && dartResult[i] <= '9'){
            if(dartResult[i] == '0'){
                if(i > 0 && dartResult[i-1] == '1')
                    num[cnt-1] = (num[cnt-1] * 10) + (dartResult[i]-'0');
                else{
                    num[cnt++] = 0;
                }
            }
            else if(dartResult[i] == '1'){
                num[cnt++] = dartResult[i] - '0';
                continue;
            }
            else{
                num[cnt++] = dartResult[i]-'0';
            }
        }
        else if('9' < dartResult[i] && dartResult[i] < 'Z' ){
            if(dartResult[i] == 'D'){
                num[cnt-1] = pow(num[cnt-1], 2);
            }
            else if(dartResult[i] == 'T'){
                num[cnt-1] = pow(num[cnt-1], 3);
            }
        }
        else{
            if(dartResult[i] == '*'){
                num[cnt-1] *= 2;
                if(cnt-2 >=0)
                    num[cnt-2] *= 2;
            }
            else{
                num[cnt-1] *= -1;
            }
        }
    }
    
    for(int i=0; i<3; i++){
        answer += num[i]; 
    }
    
    return answer;
}