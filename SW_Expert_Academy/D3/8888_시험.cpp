#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, t, p;
int info[2001][2001];
pair<pair<int, int>, int> score[2001];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	if(a.first.first == b.first.first){
		if(a.first.second == b.first.second){
			return a.second < b.second;
		}
		return a.first.second > b.first.second;
	}
	return a.first.first > b.first.first;
}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);

	int T;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case){
		memset(info, 0, sizeof(info));
		memset(score, 0, sizeof(score));
		int ans = 0;
		cin >> n >> t >> p;


		for(int i=1; i<=n; i++){
			for(int j=1; j<=t; j++){
				cin >> info[i][j];
				if(info[i][j] == 1){
					info[i][0]++;
				}
				else{
					info[0][j]++;
				}
			}
		}
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=t; j++){
				if(info[i][j] == 1){
					score[i].first.first += info[0][j];
				}
			}
			score[i].first.second = info[i][0];
			score[i].second = i;
		}
        
		sort(score+1, score+n+1, cmp);

		for(int i=1; i<=n; i++){
			if(score[i].second == p){
				cout << "#" << test_case << " " << score[i].first.first << " " << i << "\n";
				break;
			}
		}

		
	}
	return 0;
}