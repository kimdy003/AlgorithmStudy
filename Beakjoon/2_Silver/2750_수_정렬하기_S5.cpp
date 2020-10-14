#include <iostream>
using namespace std;

int main(){
    int arr[1001] = {0};
    int m_arr[1001] = {0};
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int x; cin >> x;
        if(x < 0){
            m_arr[-x] = 1;
        }
        else {
            arr[x] = 1;
        }
    }

    for(int i=1000; i>0; i--){
        if(m_arr[i] == 1){
            cout << -i << "\n";
        }
    }
    for(int i=0; i<1001; i++){
        if(arr[i] == 1){
            cout << i << "\n";
        }
    }
}