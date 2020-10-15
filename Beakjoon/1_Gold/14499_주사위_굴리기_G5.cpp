#include <iostream>
using namespace std;
int n, m;
int map[21][21] = {0};
int dice[7] = {0};

typedef struct 
{
    int x;
    int y;
}DIR;

DIR movedir[5] = {{0,0}, {0,1},{0,-1},{-1,0},{1,0}};

int main(){
    cin >> n >> m;
    int x, y, k;
    cin >> x >> y >> k;
    int dir;

    for(int i= 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
        }
    }
    DIR location = {x,y};
    for(int g = 0; g<k; g++){
        cin >> dir;
        int temp;
        location.x += movedir[dir].x;
        location.y += movedir[dir].y;
        if(0<= location.x && location.x <n && 0<= location.y && location.y<m){
            switch (dir)
            {
            //동쪽
            case 1:
                temp = dice[1];
                dice[1] = dice[4];
                dice[4] = dice[6];
                dice[6] = dice[3];
                dice[3] = temp; 
                break;

            //서쪽
            case 2:
                temp = dice[1];
                dice[1] = dice[3];
                dice[3] = dice[6];
                dice[6] = dice[4];
                dice[4] = temp;
                break;

            //북쪽
            case 3:
                temp = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[6];
                dice[6] = dice[2];
                dice[2] = temp;
                break;

            //남쪽
            case 4:
                temp = dice[1];
                dice[1] = dice[2];
                dice[2] = dice[6];
                dice[6] = dice[5];
                dice[5] = temp;
                break;
            
            default:
                break;
            }

            if(map[location.x][location.y] == 0){
                map[location.x][location.y] = dice[1];
            }
            else if(map[location.x][location.y] > 0){
                temp = map[location.x][location.y];
                map[location.x][location.y] = 0;
                dice[1] = temp;
            }

            cout << dice[6] << endl;
        }
        else{
            location.x -= movedir[dir].x;
            location.y -= movedir[dir].y;
            continue;
        }
    }

}
