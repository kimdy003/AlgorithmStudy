#include <iostream>
#include <stdlib.h>

using namespace std;

pair<int, int> movdir[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(){
    int t; cin >> t;
    for(int test = 0; test < t; test++){
        string s; cin >> s;
        int y = 0, x = 0;
        int height_s = 0, height_e = 0;
        int width_s = 0, width_e = 0;

        int dir = 0; //북
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'F'){
                y = y + movdir[dir].first;
                x = x + movdir[dir].second;
            }
            else if(s[i] == 'B'){
                y = y - movdir[dir].first;
                x = x - movdir[dir].second;
            }
            else if(s[i] == 'L'){
                dir = dir-1 < 0 ? 3 : dir -1;
            }
            else if(s[i] == 'R'){
                dir = dir+1 > 3 ? 0 : dir +1;
            }

            height_s = min(height_s, y);
            height_e = max(height_e, y);

            width_s = min(width_s, x);
            width_e = max(width_e, x);

        }
        cout << (height_e - height_s)*(width_e - width_s) << "\n";
    }
}