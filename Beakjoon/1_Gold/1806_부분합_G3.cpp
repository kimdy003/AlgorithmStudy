#include <iostream>

const int INF = 987654321;
using namespace std;

int n, s;
int array[100001];

int main(){
    cin >> n >> s;
    for(int i=0; i<n ;i++){
        cin >> array[i];
    }

    int start = 0, end = 0;
    int sum = array[0];
    int result = INF;

    while(start <= end && end <n){
        if(sum < s){
            sum += array[end];
            end += 1;
        }
        else if( sum == s){
            result = min(result, end - start+1);
            sum += array[end];
            end += 1;
        }
        else if (sum > s){
            result = min(result, end-start+1);
            sum -= array[start];
            start += 1;
        }
    }

    if(result == INF){
        cout << 0;
    }
    else
        cout << result;

    return 0;
}