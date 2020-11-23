//기능개발

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    int sum = 0;
    for(int i=0; i<size; i++){
        progresses[i] = 100 - progresses[i];
        sum = progresses[i] / speeds[i];
        if(progresses[i] % speeds[i] != 0 )
            sum += 1;
        progresses[i] = sum;
    }
    
    int cnt = 1;
    int Max = progresses[0];
    for(int i=1; i<size; i++){
        if(Max < progresses[i]){
            answer.push_back(cnt);
            Max = progresses[i];
            cnt = 1;
            continue;
        }
        cnt++;
    }
    answer.push_back(cnt);
    
    return answer;
}