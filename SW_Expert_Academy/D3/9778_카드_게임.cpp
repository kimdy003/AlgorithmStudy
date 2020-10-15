//카드 게임
#include <iostream>
using namespace std;

bool check(int *card, int sum){
    int stop = 0;
    int go = 0;
    int temp = sum;
    for(int i=0; i<12; i++){
        sum = temp;
        if(card[i] > 0){
            sum += i;
            if(sum > 21){
                stop += card[i];
            }
            else{
                go += card[i];
            }
        }
    }

    if(stop < go){
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        int card[12] = {0,0,4,4,4,4,4,4,4,4,16,4};
        int card_sum = 52;
        int sum = 0;
        int n, x;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x;
            card[x]--;
            sum += x;
        }
        card_sum -= n;

        bool flag = false;
        if(sum < 21)
            flag = check(card, sum);

        cout << "#" << test << " " ;
        if(flag){
            cout << "GAZUA" << "\n";
        }
        else{
            cout << "STOP" << "\n";
        }
    }
}

