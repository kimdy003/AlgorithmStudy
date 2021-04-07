#include<iostream>
#include <queue>
#include <set>

const int n = 4;
using namespace std;

int map[n][n];
set<string> s;
pair<int, int> movdir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void BFS(int i, int j, int m){
    queue<pair<pair<int, int>, string>> q;
    q.push({{i,j}, to_string(m)});

    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        string str = q.front().second;
        q.pop();

        if(str.length() == 7){
            s.insert(str);
            continue;
        }

        for(int i=0; i<4; i++){
            int ny = y + movdir[i].first;
            int nx = x + movdir[i].second;

            if(ny < 0 || n <= ny || nx < 0 || n <= nx) continue;

            string nstr = str + to_string(map[ny][nx]);
            q.push({{ny, nx}, nstr});
        }
    }
}

int main(int argc, char** argv){
    cin.tie(0);
    cout.sync_with_stdio(false);

	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        s.clear();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                BFS(i, j, map[i][j]);
            }
        }

        cout << "#" << test_case << " " << s.size() << "\n";
	}
	return 0;
}