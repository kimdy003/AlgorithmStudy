#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string flip, color = "wyrogb";
char Cube[6][3][3];
char Copy2d[3][3];

void Clockwise(int num){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            Copy2d[i][j] = Cube[num][i][j];
        }
    }

    //윗 열
    for(int i=0; i<3; i++){
        Cube[num][0][i] = Copy2d[2-i][0];
    }

    //가운데열
    Cube[num][1][0] = Copy2d[2][1];
    Cube[num][1][2] = Copy2d[0][1];

    //마지막
    for(int i=0; i<3; i++){
        Cube[num][2][i] = Copy2d[2- i][2];
    }
}

void CounterClockwise(int num){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            Copy2d[i][j] = Cube[num][i][j];
        }
    }

    //윗열
    for(int i=0; i<3; i++){
        Cube[num][0][i] = Copy2d[i][2];
    }

    //가운데
    Cube[num][1][0] = Copy2d[0][1];
    Cube[num][1][2] = Copy2d[2][1];

    //마지막
    for(int i=0; i<3; i++){
        Cube[num][2][i] = Copy2d[i][0];
    }
}

void U(int num){
    char temp[3];

    for(int i=0; i<3; i++)
        temp[i] = Cube[4][num][i];
    for(int i=0; i<3; i++)
        Cube[4][num][i] = Cube[2][num][i];
    for(int i=0; i<3; i++)
        Cube[2][num][i] = Cube[5][num][i];
    for(int i=0; i<3; i++)
        Cube[5][num][i] = Cube[3][num][i];
    for(int i=0; i<3; i++)
        Cube[3][num][i] = temp[i];
}

void D(int num){
    char temp[3];

    for(int i=0; i<3; i++)
        temp[i] = Cube[4][num][i];
    for(int i=0; i<3; i++)
        Cube[4][num][i] = Cube[3][num][i];
    for(int i=0; i<3; i++)
        Cube[3][num][i] = Cube[5][num][i];
    for(int i=0; i<3; i++)
        Cube[5][num][i] = Cube[2][num][i];
    for(int i=0; i<3; i++)
        Cube[2][num][i] = temp[i];
}

void F(int num){
    char temp[3];
    int idx = (num == 0 ? 2 : 0);

    for(int i=0; i<3; i++)
        temp[i] = Cube[0][num][i];
    for(int i=0; i<3; i++)
        Cube[0][num][i] = Cube[4][2-i][num];
    for(int i=0; i<3; i++)
        Cube[4][i][num] = Cube[1][idx][i];
    for(int i=0; i<3; i++)
        Cube[1][idx][i] = Cube[5][2-i][idx];
    for(int i=0; i<3; i++)
        Cube[5][i][idx] = temp[i];
}

void B(int num){
    char temp[3];
    int idx = (num == 0) ? 2 : 0;

    for (int i = 0; i < 3; i++)
        temp[i] = Cube[0][num][i];
    for (int i = 0; i < 3; i++)
        Cube[0][num][i] = Cube[5][i][idx];
    for (int i = 0; i < 3; i++)
        Cube[5][i][idx] = Cube[1][idx][2 - i];
    for (int i = 0; i < 3; i++)
        Cube[1][idx][i] = Cube[4][i][num];
    for (int i = 0; i < 3; i++)
        Cube[4][i][num] = temp[2 - i];
}

void L(int num){
    char temp[3];
    int idx = (num == 0 ? 2 : 0);

    for (int i = 0; i < 3; i++)
        temp[i] = Cube[0][i][num];
    for (int i = 0; i < 3; i++)
        Cube[0][i][num] = Cube[3][2 - i][idx];
    for (int i = 0; i < 3; i++)
        Cube[3][i][idx] = Cube[1][2 - i][num];
    for (int i = 0; i < 3; i++)
        Cube[1][i][num] = Cube[2][i][num];
    for (int i = 0; i < 3; i++)
        Cube[2][i][num] = temp[i];
}

void R(int num){
    char temp[3];
    int idx = (num == 0 ? 2 : 0);

    for (int i = 0; i < 3; i++)
        temp[i] = Cube[0][i][num];
    for (int i = 0; i < 3; i++)
        Cube[0][i][num] = Cube[2][i][num];
    for (int i = 0; i < 3; i++)
        Cube[2][i][num] = Cube[1][i][num];
    for (int i = 0; i < 3; i++)
        Cube[1][i][num] = Cube[3][2 - i][idx];
    for (int i = 0; i < 3; i++)
        Cube[3][i][idx] = temp[2 - i];
}

int main(){
    int t; cin >> t;
    for(int test=0; test<t; test++){

        for(int i=0; i<6; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    Cube[i][j][k] = color[i];
                }
            }
        }
    
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> flip;

            switch (flip[0])
            {
            case 'U':
                if(flip[1] == '+'){
                    Clockwise(0);
                    U(0);
                }
                else{
                    CounterClockwise(0);
                    D(0);
                }
                break;

            case 'D':
                if(flip[1] == '+'){
                    Clockwise(1);
                    D(2);
                }
                else{
                    CounterClockwise(1);
                    U(2);
                }
                break;

            case 'F':
                if(flip[1] == '+'){
                    Clockwise(2);
                    F(2);
                }
                else{
                    CounterClockwise(2);
                    B(2);
                }
                break;

            case 'B':
                if(flip[1] == '+'){
                    Clockwise(3);
                    B(0);
                }
                else{
                    CounterClockwise(3);
                    F(0);
                }
                break;

            case 'L':
                if(flip[1] == '+'){
                    Clockwise(4);
                    L(0);
                }
                else{
                    CounterClockwise(4);
                    R(0);
                }
                break;

            case 'R':
                if(flip[1] == '+'){
                    Clockwise(5);
                    R(2);
                }
                else{
                    CounterClockwise(5);
                    L(2);
                }
                break;
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout << Cube[0][i][j];
            }
            cout << "\n";
        }
    }
}