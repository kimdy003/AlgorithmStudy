#include <iostream>
#include <vector>

const int MAX = 40001;
using namespace std;

int n, ans = 0;
int arr[MAX];
vector<int> v;

int main(){
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> arr[i];

    for(int i=1; i<=n; i++){
        if(v.size() == 0 || v[v.size() -1] < arr[i])
            v.push_back(arr[i]);
        else{
            int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[pos] = arr[i];
        }

    }
    
    cout << v.size();
}
