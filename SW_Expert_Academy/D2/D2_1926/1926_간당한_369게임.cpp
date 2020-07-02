#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.sync_with_stdio(false);
	int n;
    int cnt;
    cin >> n;

    string s = "";
    for(int i=1; i<=n; i++){
        int x = i;
        int cnt = 0;
        while(x > 0){
            int binary = x % 10;
            if(binary != 0 && binary % 3 == 0){
                cnt++;
            }
            x /= 10;
        }

        if(cnt)
            for(int j=0; j<cnt; j++){
                s += "-";
            }
        else
            s += to_string(i);

        s += " ";
    }
    cout << s ;
	return 0;
}