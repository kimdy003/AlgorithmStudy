#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        string s;
        cin >> s;

        bool flag = true;
        int cnt;
        for(int i=0; i<s.size() && flag; i++){
            for(int j=i+1; j<s.size() && flag; j++){
                if(s[i] == s[j]){
                    int i_cnt = i+1;
                    int j_cnt = j+1;
                    cnt = 1;
                    while(1){
                        if(s[i_cnt++] != s[j_cnt++]) break;
                        cnt++;

                        if(i_cnt == j){
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }

        cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}