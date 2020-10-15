//n진수 게임
#include <string>
#include <vector>
using namespace std;

string change(int n, int num){
    string temp = "";
    string code[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

    while(num/n != 0){
        temp = code[num%n] + temp;
        num /= n; 
    }

    temp = code[num%n] + temp;
    return temp;
}

string solution(int n, int t, int m, int p){
    string answer;

    string val = "0";
    for(int i=1; i<t*m; i++){
        val += change(n, i);
    }

    int cnt = 1;
    for(int i = p-1; i<val.size();){
        answer += val[i];
        if(cnt == t) break;

        cnt++;
        i += m;
    }
    return answer;
}

int main(){
    int n= 2;
    int t = 4;
    int m = 2;
    int p = 1;
    solution(n, t, m, p);
}