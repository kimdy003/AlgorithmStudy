#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.sync_with_stdio(false);
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        long long answer = 0;
        int n;
        cin >> n;
        vector<int> array;
        int x;
        for(int i=0; i<n; i++){
            cin >> x;
            array.push_back(x);
        }

        int Max = array.back();
        for(int i= array.size()-2; i>=0; i--){
            if(array[i] <= Max)
                answer += Max-array[i];
            else 
                Max = array[i];
        }
        cout << "#" << test_case << " " << answer << "\n";


	}
	return 0;
}