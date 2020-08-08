#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct homework{
    int x;
    int y;
};
vector<homework> work;

bool cmp(homework a, homework b){
    if(a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;

}

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            work.push_back({x,y});
        }

        sort(work.begin(), work.end(), cmp);

        int start_day = work.back().y - work.back().x;
        work.pop_back();

        while(!work.empty()){
            int ed = work.back().y;
            int sd = work.back().y - work.back().x;
            work.pop_back();

            if(ed >= start_day)
                start_day = sd - (ed - start_day);
            else
                start_day = sd;

        }
        cout << "#" << test << " " << start_day << "\n";
    }
    return 0;
}