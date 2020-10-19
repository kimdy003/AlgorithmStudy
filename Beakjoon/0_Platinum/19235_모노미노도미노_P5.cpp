#include <iostream>

const int BLUE = 0;
const int GREEN = 1;
using namespace std;

int n, score, Count;
int board[2][10][4];

void Move_Point(int y, int x, int color){
    int label = board[color][y][x];
    board[color][y][x] = 0;
    while(y < 10){
        if(board[color][y][x] != 0){
            break;
        }

        ++y;
    }
    --y;
    board[color][y][x] = label;
}

void Move_H_Block(int y, int x, int color){
    int label = board[color][y][x];
    board[color][y-1][x] = 0;
    board[color][y][x] = 0;
    while(y < 10){
        if(board[color][y][x] != 0){
            break;
        }

        ++y;
    }
    --y;
    board[color][y-1][x] = label;
    board[color][y][x] = label;
}

void Move_W_Block(int y, int x, int color){
    int label = board[color][y][x];
    board[color][y][x] = 0;
    board[color][y][x+1] = 0;
    while(y < 10){
        if((board[color][y][x] != 0) || (board[color][y][x+1] != 0)){
            break;
        }

        ++y;
    }
    --y;
    board[color][y][x] = label;
    board[color][y][x+1] = label;
}

void Remove(int y, int color){
    for(int x = 0; x<4; x++){
        board[color][y][x] = 0;
    }
}

void Move(int start_y, int color){
    const int dy[2] = {-1, 0};
    const int dx[2] = {0, +1};

    for(int y = start_y; y >= 4; --y){
        for(int x = 0; x < 4; ++x){
            if(board[color][y][x] == 0)
                continue;

            //type 1 one block
            //type 2 h block
            //type 3 w block
            int type = 1;
            for(int d = 0; d<2; ++d){
                int ny = y + dy[d];
                int nx = x + dx[d];
                if(ny < 4 || nx >= 4)
                    continue;

                if(board[color][y][x] == board[color][ny][nx]){
                    if(d == 0){
                        type = 2;
                    }
                    else{
                        type = 3;
                    }
                }
            }

            if(type == 1){
                Move_Point(y, x, color);
            }
            else if(type == 2){
                Move_H_Block(y, x, color);
            }
            else if(type == 3){
                Move_W_Block(y, x, color);
            }
        }
    }
}


void Delete_Filled_Block(int color){
    bool is_remove = false;
    for(int y=6; y<10; ++y){
        int count = 0;
        for(int x = 0; x < 4; ++x){
            if(board[color][y][x] != 0)
                ++count;
        }

        if(count == 4){
            is_remove = true;
            ++score;
            Remove(y, color);
            Move(y-1, color);
        }
    }

    if(is_remove){
        Delete_Filled_Block(color);
    }
}

void Delete_Overflow_Block(int color){
    int remove_count = 0;
    for(int y = 4; y<= 5; ++y){
        bool has_block = false;
        for(int x = 0; x < 4; ++x){
            if(board[color][y][x] != 0){
                has_block = true;
                break;
            }
        }
        if(has_block){
            ++remove_count;
        }
    }

    if(remove_count > 0){
        for(int y = 9; y>= 6; --y){
            for(int x = 0; x<4; x++){
                board[color][y][x] = board[color][y-remove_count][x];
            }
        }

        for(int y=4; y<= 5; y++){
            for(int x = 0; x<4; x++){
                board[color][y][x] = 0;
            }
        }
    }
}


void Put(int type, int target, int color, int label){
    if(type == 1){
        board[color][0][target] = label;
        Move_Point(0, target, color);
    }
    else if((type == 2 && color == GREEN) || (type == 3 && color == BLUE)){
        board[color][0][target] = label;
        board[color][0][target+1] = label;
        Move_W_Block(0, target, color);
    }
    else if((type == 3 && color == GREEN) || (type == 2 && color == BLUE)){
        board[color][0][target] = label;
        board[color][1][target] = label;
        Move_H_Block(1, target, color);
    }

    Delete_Filled_Block(color);
    Delete_Overflow_Block(color);
}

int main(){

    score = 0; Count = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        int t, x, y;
        cin >> t >> y >> x;
        Put(t, y, BLUE, i+1);
        Put(t, x, GREEN, i+1);
    }

    for(int color = 0; color < 2; color++){
        for(int y = 4; y <10; y ++){
            for(int x = 0; x<4; x++){
                if(board[color][y][x] != 0){
                    ++Count;
                }
            }
        }
    }

    cout << score << "\n" << Count;
}