#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = [0,0];
    unordered_map<string, int> m;
    set<string> s(gems.begin(), gems.end());
    int Min, start = 0, end = 0;

    for(int i=0; i<gems.size(); i++){
        m[gems[i]]++;
        if(m.size() == s.size()) break;
        end++;
    }

    Min = end - start;
    answer[0] = start+1;
    answer[1] = end+1;

    while(end < gems.size()){
        string key = gems[start];
        m[key]--;
        start++;

        if(m[key] == 0){
            end++;
            for(; end < gems.size(); end++){
                m[gems[end]]++;
                if(key == gems[end])
                    break;
            }
            if(end == gems.size()) break;
        }
        
        if(Min > end-start){
            answer[0] = start+1;
            answer[1] = end+1;
            Min = end - start;
        }
    }
    
    return answer;
}


int main(){
    string a[] = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<string> b;
    for(int i=0; i<sizeof(a)/sizeof(int); i++){
        b.push_back(a[i]);
    }
    
    cout << solution(b);
}