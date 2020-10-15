#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, oper_num;
string str;
bool GwalHo[20];
long long ans = -987654321987654321;

long long Act_Cal(int a, int b, string o){
    if(o == "+")
        return a + b;
    else if(o == "-")
        return a - b;
    
    return a * b;
}

long long Cal(){
    vector<string> v;
    for(int i=0; i<n; ){
        if(GwalHo[i] == false){
            string s = "";
            s = s + str[i];
            v.push_back(s);
            i++;
        }
        else{
            string s = "";
            s += str[i];
            long long temp1 = stoi(s);

            s = "";
            s += str[i+2];
            long long temp2 = stoi(s);

            string oper = "";
            oper += str[i+1];

            long long temp_result = Act_Cal(temp1, temp2, oper); 
            v.push_back(to_string(temp_result));
            i += 3;
        }
    }

    long long result = stoi(v[0]);
    for(int i = 1; i<v.size(); i++){
        if(v[i] == "+"){
            result += stoi(v[i+1]);
        }
        else if(v[i] == "-"){
            result -= stoi(v[i+1]);
        }
        else{
            result *= stoi(v[i+1]);
        }
    }

    return result;
}

void DFS(int idx){
    if(idx >= n){
        ans = max(ans, Cal());
        return;
    }

    for(int i=idx; i<n; i += 2){
        if(i + 2 < n){
            if(GwalHo[i] == false && GwalHo[i+1] == false){
                GwalHo[i] = true;
                GwalHo[i+2] = true;
                //idx+2로 보내기
                DFS(idx+2);

                GwalHo[i] = false;
                GwalHo[i+2] = false;
            }
        }

        else{
            //마지막 숫자, idx == n 으로 맞추기
            DFS(i+1);
        }
    }
}

int main(){
    cin >> n >> str;
    oper_num = n/2;

    DFS(0);
    cout << ans;
}
