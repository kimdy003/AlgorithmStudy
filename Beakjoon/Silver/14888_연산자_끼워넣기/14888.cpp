#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int num[11] = {0};
vector<int> v;

long long get_operation(int idx, int x, int y){
    long long sum;

    if(idx == 0){
        sum = x+y;    
    }
    else if(idx == 1){
        sum = x-y;
    }
    else if(idx == 2){
        sum = x*y;
    }
    else{
        sum = x/y;
    }

    return sum;
}

long long get_cal(){
    long long temp = num[0];
    int cnt = 1;
    for(int i=0; i<v.size(); i++){
        temp = get_operation(v[i], temp, num[cnt++]);
    }
    return temp;
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    for(int i=0; i<4; i++){
        int count;
        cin >> count;
        for(int j=0; j<count; j++){
            v.push_back(i);
        }
    }

    long long Max = -1000000000;
    long long Min = 1000000000;
    do{
        long long temp = get_cal();

        Max = max(Max, temp);
        Min = min(Min, temp);

    }while(next_permutation(v.begin(), v.end()));

    cout << Max << "\n" << Min << "\n";

    return 0;
}