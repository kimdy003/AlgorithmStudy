#include <iostream>
#include <cstring>

using namespace std;

int n;
int map[1000];

int main(int argc, char** argv){
    cin.tie(NULL);
    cout.sync_with_stdio(false);

	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> map[i];
        }

        int ans = 0;
        for(int i=2; i<n-2; i++){
            int left = max(map[i-1], map[i-2]);
            int right = max(map[i+1], map[i+2]);

            int Max = max(left, right);
            if(Max < map[i]){
                ans += (map[i] - Max);
            }
        }

        cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}