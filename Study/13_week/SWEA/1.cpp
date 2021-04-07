#include <iostream>
#include <vector>

using namespace std;

int n;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    cout.sync_with_stdio(false);

	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        cin >> n;

        int a;
        vector<int> array;
        for(int i=0; i<n; i++){
            cin >> a;
            array.push_back(a);
        }

        long long ans = 0;
        int pivot = array.back();
        for(int i=array.size()-2; i>=0; i--){
            if(array[i] <= pivot){
                ans += pivot - array[i];
            }
            else
                pivot = array[i];
        }

        cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}