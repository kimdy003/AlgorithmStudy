#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int n, ans;
string str;
int Save_Max_Value, Total_Cnt;
int Number[6];
int Save_Max_Num[6];
bool Have_Same = false;

int calculation(int a[]){
    int sum = 0;
    for(int i=0; i<str.size(); i++){
        sum += a[i];
        sum *= 10;
    }
    sum /= 10;
    return sum;
}

void DFS(int Cur, int Cnt){
    int temp = calculation(Number);

    if(Save_Max_Value < temp){
        Save_Max_Value = temp;
        Total_Cnt = Cnt;
        for(int i=0; i<str.size(); i++){
            Save_Max_Num[i] = Number[i];
        }
    }

    if(Cnt == n){
        ans = max(ans, calculation(Number));
        return;
    }

    int Max = -1;
    for(int i=Cur; i<str.size(); i++){
        Max = max(Max, Number[i]);
    }

    for(int i=Cur; i<str.size(); i++){
        if(Number[i] == Max){
            if(i == Cur) 
                DFS(Cur+1, Cnt);
            else{
                swap(Number[i], Number[Cur]);
                DFS(Cur+1, Cnt+1);
                swap(Number[i], Number[Cur]);
            }
        }
    }
}

void Setting(){
    ans = 0;
    Save_Max_Value = 0;
    Total_Cnt = 0;
    Have_Same = false;
    int Num_Cnt[10] = {0};

    int num = stoi(str);
    int size = str.size()-1;
    while(num > 0){
        int value = num % 10;
        Number[size--] = value;
        Num_Cnt[value]++;

        if(Num_Cnt[value] >= 2) 
            Have_Same = true;
        num /= 10; 
    }
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T ;
    cin >> T;
    for(int test=1; test<= T; test++){
        cin >> str >> n;
        Setting();

        DFS(0, 0);

        if(Total_Cnt < n){
            if(Have_Same){
                cout << "#"<< test << " " << Save_Max_Value << "\n";
                continue;
            }

            int Change = n - Total_Cnt;
            if(Change % 2 == 0){
                ans = Save_Max_Value;
            }
            else{
                swap(Save_Max_Num[str.size()-1], Save_Max_Num[str.size()-2]);
                ans = calculation(Save_Max_Num);
            }
        }

        cout << "#"<< test << " " << ans << "\n";
    }
    

    return 0;
}