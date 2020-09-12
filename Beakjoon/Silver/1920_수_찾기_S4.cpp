#include <iostream>
#include <algorithm>
using namespace std;
int array[100001] = {0};
int n, m;

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    sort(array, array+n);

    cin >> m;
    int x;
    for(int i=0; i<m; i++){
        cin >> x;

        int start = 0;
        int end = n-1;
        int mid;

        while(end - start >= 0){
            mid = (start+end)/2;

            if(arr[mid] == x){
                cout << "1\n";
                return 0;
            }

            else if(arr[mid] > x){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        cout << "0\n";
    }

    return 0;
}