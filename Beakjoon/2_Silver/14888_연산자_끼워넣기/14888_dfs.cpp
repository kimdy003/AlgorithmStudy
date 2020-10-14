#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int oper[4] = {0};
vector<int> num;
vector<int> ans;
vector<int> operation;

int calculator(){
    int sum = num[0];
    for(int i=0; i<n-1; i++){
        int x = operation[i];
        if(x == 0){
            sum += num[i+1];
        }
        else if(x == 1){
            sum -= num[i+1];
        }
        else if(x == 2){
            sum *= num[i+1];
        }
        else{
            sum /= num[i+1];
        }
    }

    return sum;
}

void dfs(int cnt){
    if(cnt == n-1){
        int sum = calculator();
        ans.push_back(sum);
        return;
    }

    for(int i=0; i<4; i++){
        if(oper[i]){
            oper[i]--;
            operation.push_back(i);

            dfs(cnt+1);

            oper[i]++;
            operation.pop_back();
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        num.push_back(x);
    }

    for(int i=0; i<4; i++)
        cin >> oper[i];
    
    dfs(0);

    sort(ans.begin(), ans.end());
    cout << ans.back() << "\n" << ans[0];


}