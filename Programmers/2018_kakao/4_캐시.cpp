//Ä³½Ã
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0){
        answer = 5 * cities.size();
        return answer;
    }
    
    
    for(int i=0; i<cities.size(); i++){
        for(int j=0; j<cities[i].size(); j++){
            if(cities[i][j] < 97)
                cities[i][j] += 32;
        }
    }
    
    vector<string> cache;
    cache.resize(cacheSize);
    for(int i=0; i<cities.size(); i++){
        bool flag = true;
        for(int k=0; k< cacheSize; k++){
            if(cities[i] == cache[k]){
                cache.erase(cache.begin()+k);
                cache.push_back(cities[i]);
                answer += 1;
                flag = false;
                break;
            }
        }
        
        if(flag){
            cache.erase(cache.begin());
            cache.push_back(cities[i]);
            answer += 5;
        }
    }
    
    return answer;
}