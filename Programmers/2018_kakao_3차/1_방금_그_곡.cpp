#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

vector<string> strtok(string s, char delim = ' '){
    vector<string> ret;
    
    int prev = 0;
    for(int i=0; i< s.size(); i++){
        if(s[i] == delim){
            ret.push_back(s.substr(prev, i-prev));
            prev = i+1;
        }
    }
    
    if(prev != s.size())
        ret.push_back(s.substr(prev, s.size()-prev));
    
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    string a = "";
    for(int i=0; i<m.size(); i++){
        if(m[i+1] == '#'){
            a += (m[i]+32);
            i++;
            continue;
        }
        a += m[i];
    }
    m = a;

    vector<vector<string>> info;
    for(int i=0; i<musicinfos.size(); i++){
        vector<string> temp = strtok(musicinfos[i], ',');
        
        int time = (stoi(strtok(temp[1], ':')[0]) - stoi(strtok(temp[0], ':')[0]))*60 + 
            (stoi(strtok(temp[1], ':')[1]) - stoi(strtok(temp[0], ':')[1]));
        string s = "";
        for(int i=0; i<temp[3].size(); i++){
            if(temp[3][i+1] == '#'){
                s += (temp[3][i] + 32);
                i++;
                continue;
            }
            s += temp[3][i];
        }
        temp[3] = s;
        int size = temp[3].size();
        s = "";
        for(int i=0; i<time; i++){
            s += temp[3][i%size];
        }
        info.push_back({temp[2], s, to_string(time)});
    }

    bool flag;
    vector<pair<int, string>> ans;
    for(int i=0; i<info.size(); i++){
        flag = false;
        for(int j=0; j<info[i][1].size(); j++){
            int cnt = 0, idx = j;
            while(1){
                if(info[i][1][idx++] != m[cnt++]){
                    break;
                }
                if(cnt == m.size()){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans.push_back({stoi(info[i][2]), info[i][0]});
                break;
            }
        }
    }

    if(!ans.empty()){
        sort(ans.begin(), ans.end(), cmp);
        answer = ans[0].second;
        return answer;
    }
    else{
        answer = "(None)";
        return answer;
    }
}

int main(){
    string arr[5] = {"12:00,12:06,HELLO,ACCACC", "13:00,13:06,AAA,ACCACC","13:00,13:06,BBB,ACCACC","13:00,13:06,AAA,ACCACC","13:00,13:05,AAA,ACCACC"};
    vector<string> v;
    string m = "CC";

    for(int i=0; i<5; i++){
        v.push_back(arr[i]);
    }
    cout << solution(m, v);
}