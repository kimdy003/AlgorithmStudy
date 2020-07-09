#include <iostream>
using namespace std;
int arr[10][10] = {0};

int main(){

    arr[0][0] = 1;
    arr[1][0] = 1; arr[1][1] = 1;

    for(int i=2; i<10; i++){
        arr[i][0] = 1;
        for(int j=1; j<i; j++){
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
        arr[i][i] = 1;
    }

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        int n; 
        cin >> n;
        cout << "#" << test << "\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                if(arr[i][j] == 0)
                    break;
                cout << arr[i][j] << " ";
            }    
            cout << "\n";
        }
    }
    return 0;
}