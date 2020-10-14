#include <iostream>
#include <vector>
using namespace std;
int map[101][101] = {0};
vector<pair<int, char>> info;
vector<pair<int, int>> snake;
int n, k, l;
pair<int, int> movdir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int d = 3;

void direction(char c){
    if(c == 'D'){
        d = d - 1 < 0 ? 3 : d - 1;
    }
    else{
        d = d + 1 > 3 ? 0 : d + 1;
    }
}

int main(){
    cin >> n >> k;

    map[1][1] = 2;
    for(int i=0; i<k; i++){
        int y, x;
        cin >> y >> x;
        map[y][x] = 1;
    }

    cin >> l;
    for(int i=0; i<l; i++){
        int t;
        char c;
        cin >> t >> c;
        info.push_back({t, c});
    }

    snake.push_back({1, 1});
    int time = 0;

    while(1){
        if(!info.empty()){
            if(info.front().first == time){
                direction(info.front().second);
                info.erase(info.begin());
            }
        }
        time++;

        int nexty = snake[snake.size()-1].first + movdir[d].first;
        int nextx = snake[snake.size()-1].second + movdir[d].second;

        if(nexty <= 0 || n < nexty || nextx <= 0 || n < nextx) break;
        if(map[nexty][nextx] == 2) break;

        if(map[nexty][nextx] == 1){
            snake.push_back({nexty, nextx});
        }
        else{
            map[snake[0].first][snake[0].second] = 0;
            snake.push_back({nexty, nextx});
            snake.erase(snake.begin());
        }
        
        map[nexty][nextx] = 2;
    }

    cout << time;
}