#include <iostream>
using namespace std;

int main(){
    long long array[1000001] = {0};
    array[2] = 1;
    array[3] = 2;
    for(int i= 4; i<1000001; i++){
        array[i] = ((i-1)*(array[i-1]+array[i-2])%1000000000);

    }

    int n;
    cin >> n;
    cout << array[n] << endl;
    
}