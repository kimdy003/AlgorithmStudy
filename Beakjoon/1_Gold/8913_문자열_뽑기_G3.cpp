#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool flag;

void DFS(string str){
    if(flag) return;

    if(str.empty()){
        flag = true;
        return;
    }

    for(int i=0; i<str.size() && !flag; i++){
        int idx = i;
        while(idx != str.size()){
            if(str[i] != str[idx]) break;
            idx += 1;
        }

        if(idx-i >= 2){
            DFS(str.substr(0,i) + str.substr(idx));
        }
        i = idx-1;
    }
}

int main(){
    int t;
    cin >> t;
    for(int test = 0; test <t; test++){
        string s;
        cin >> s;
        
        flag = false;
        DFS(s);

        cout << flag << "\n";
    }
}