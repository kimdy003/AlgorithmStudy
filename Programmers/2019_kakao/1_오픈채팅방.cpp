#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

typedef struct _INFO{
    string behavior;
    string uid;
} INFO;


vector<string> strtok(string str, char delim=' '){
    vector<string> ret;
    
    int prev = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == delim){
            ret.push_back(str.substr(prev, i-prev));
            prev = i+1;
        }
    }
    
    if(prev != str.size())
        ret.push_back(str.substr(prev, str.size()-prev));
    
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<INFO> info;
    map<string, string> m;
    for(int i=0; i<record.size(); i++){
        vector<string> temp = strtok(record[i]);

        if(temp[0] == "Enter"){
            info.push_back({temp[0], temp[1]});
            m[temp[1]] = temp[2];
        }
        else if(temp[0] == "Leave"){
            info.push_back({temp[0], temp[1]});
        }
        else{
            m[temp[1]] = temp[2];
        }
    }
    
    for(int i=0; i<info.size(); i++){
        string s;

        if(info[i].behavior == "Enter"){
            s = m[info[i].uid] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else{
            s = m[info[i].uid] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }

        answer.emplace_back(s);
    }

    return answer;
}

int main(){
    string s[5] = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> v;
    for(int i=0; i<5; i++){
        v.push_back(s[i]);
    }

    solution(v);
}