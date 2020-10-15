//뉴스 클러스터링
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;
vector<string> s1;
vector<string> s2;

int solution(string str1, string str2) {
    int answer = 0;
    
     for(int i=0; i<str1.size(); i++){
        if('a' <= str1[i] && str1[i] <= 'z'){
            str1[i] = toupper(str1[i]);
        }
     }
    
    for(int i=0; i<str2.size(); i++){
        if('a' <= str2[i] && str2[i] <= 'z'){
            str2[i] = toupper(str2[i]);
        }
     }
    
    string temp = "";
    for(int i=0; i<str1.size()-1; i++){
        if('A' <= str1[i] && str1[i] <= 'Z'){
            if('A' <= str1[i+1] && str1[i+1] <= 'Z'){
                temp += str1[i];
                temp += str1[i+1];
                s1.push_back(temp);
                temp = "";
            }
        }
        else{
            temp = "";
        }
    }
    
    temp = "";
    for(int i=0; i<str2.size()-1; i++){
        if('A' <= str2[i] && str2[i] <= 'Z'){
            if('A' <= str2[i+1] && str2[i+1] <= 'Z'){
                temp += str2[i];
                temp += str2[i+1];
                s2.push_back(temp);
                temp = "";
            }
        }
        else{
            temp = "";
        }
    }
    
    int same = 0;
    int total = s1.size() + s2.size();
    int m = s2.size();
    vector<int> visit(m, 1);
    
    bool flag;
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(visit[j] == 0) continue;
            if(s1[i] == s2[j]){
                visit[j] = 0;
                same++;
                break;
            }
        }
    }
    
    if(total != 0){
        double sub = ((double)same/(double)(total-same)) * 65536;
        answer = (int)sub;
    }
    else{
        answer = 65536;
    }
    
    return answer;
}