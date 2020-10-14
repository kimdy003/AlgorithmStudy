#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
vector<int> v[MAX];

int main(){
    cin.tie(0):
    cout.sync_with_stdio(false);
    
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int query;
    cin >> query;

    while(query--){
        int a, b;
        cin >> a >> b;

        if(a == 1){
            if(v[b].size() >= 2)
                cout << "yes" << "\n";
            else
                cout << "no" << "\n";
        }
        else{
            cout << "yes" << "\n";
        }
    }
}