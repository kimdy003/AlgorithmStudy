#include <iostream>
#include <vector>
using namespace std;
int n, ans = 0;
int map[101][101] = {0};
pair<int, int> dir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void all_print(){
    cout << "\n";
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int calculation(int d){
    return d+1 > 3 ? 0 : d+1;
}

void dragon(int x, int y, int d, int g){
    vector<int> direction;

    direction.push_back(d);
    for(int i=0; i<g; i++){
        int size = direction.size();
        for(int j=size-1; j>=0; j--){
            int d = calculation(direction[j]);
            direction.push_back(d);
        }
    }

    map[y][x] = 1;
    int nexty, nextx;
    for(int i=0; i<direction.size(); i++){
        nexty = y + dir[direction[i]].first;
        nextx = x + dir[direction[i]].second;

        if(nexty < 0 || 100 < nexty || nextx < 0 || 100 < nextx) continue;

        map[nexty][nextx] = 1;
        y = nexty;
        x = nextx;
    }

}

int main(){
    cin >> n;

    int x, y, d, g;
    for(int i=0; i<n; i++){
        cin >> x >> y >> d >> g;
        dragon(x, y, d, g);
    }

    all_print();

    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(map[i][j] == 1 && map[i+1][j] == 1 && map[i][j+1] == 1 && map[i+1][j+1] == 1){
                ans++;
            }
        }
    }

    cout << ans;
}