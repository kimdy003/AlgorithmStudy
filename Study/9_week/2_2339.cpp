#include <iostream>
#include <vector>

using namespace std;

int n;
int map[20][20];

int Slice(int sy, int sx, int ey, int ex, int dir){
    vector<pair<int, int>> Impurities;
    int Jewely = 0;
    for(int i=sy; i<ey; i++){
        for(int j=sx; j<ex; j++){
            if(map[i][j] == 1)
                Impurities.push_back({i, j});
            if(map[i][j] == 2)
                Jewely++;
        }
    }

    if(Jewely == 0) return 0;
    if(Jewely == 1){
        if(Impurities.empty()){
            return 1;
        }
        return 0;
    }

    int cnt = 0;
    //가로로 자르기
    if(dir == 0){
        for(int i=0; i<Impurities.size(); i++){
            int y = Impurities[i].first;
            int x = Impurities[i].second;

            bool flag = true;
            //자르는 위치에 보석이 있는지 확인
            for(int j=sx; j<ex; j++){
                if(map[y][j] == 2) 
                    flag = false;
            }

            if(flag){
                cnt += Slice(sy, sx, y, ex, 1) * Slice(y+1, sx, ey, ex, 1);
            }
        }
    }

    //세로로 자르기
    else{
        for(int i=0; i<Impurities.size(); i++){
            int y = Impurities[i].first;
            int x = Impurities[i].second;
            
            bool flag = true;
            //자르는 위치에 보석이 있는지 확인
            for(int j=sy; j<ey; j++){
                if(map[j][x] == 2)
                    flag = false;
            }

            if(flag){
                cnt += Slice(sy, sx, ey, x, 0) * Slice(sy, x+1, ey, ex, 0);
            }
        }
    }

    return cnt;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    int ans = (Slice(0, 0, n, n, 0) + Slice(0, 0, n, n, 1));
    cout << (ans == 0 ? -1 : ans);
}