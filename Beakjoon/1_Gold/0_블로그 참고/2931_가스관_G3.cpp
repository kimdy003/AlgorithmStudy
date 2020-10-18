#include <iostream>
#include <queue>
#include <cstring>

const int MAX = 26;
using namespace std;

int N, M;
int Total = 1;
char Map[MAX][MAX];
char Result = 0;

bool Visit[MAX][MAX];
bool ClearFlag = false;

char Pipe[4][6] =
{
   { '-', '+', '3', '4', 'Z' }, // Right
   { '-', '+', '1', '2', 'Z' }, // Left
   { '|', '+', '2', '3', 'Z' }, // Down
   { '|', '+', '1', '4', 'Z' }, // Up
};

pair<int, int> Start, EmptyPos;
pair<int, int> MoveDir[4] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

int Set_Direct(int dir, char c){
    int ndir = -1;
    if(c == 'M'){
        ndir = dir;
    }
    if(c == '|'){
        if(dir == 2 || dir == 3) ndir = dir;
    }
    else if(c == '-'){
        if(dir == 0 || dir == 1) ndir = dir;
    }
    else if(c == '+'){
        ndir = dir;
    }
    else if (c == '1')
    {
        if (dir == 3) ndir = 0;
        else if (dir == 1) ndir = 2;
    }
    else if (c == '2')
    {
        if (dir == 2) ndir = 0;
        else if (dir == 1) ndir = 3;
    }
    else if (c == '3')
    {
        if (dir == 0) ndir = 3;
        else if (dir == 2) ndir = 1;
    }
    else if (c == '4')
    {
        if (dir == 0) ndir = 2;
        else if (dir == 3) ndir = 1;
    }

    return ndir;
}

void DFS(int y, int x, int dir, bool flag, int cnt){
    if(Visit[y][x] == false){
        Visit[y][x] = true;
        cnt++;
    }

    if(Map[y][x] == 'Z' && Total == cnt){
        ClearFlag = true;
        return;
    }

    dir = Set_Direct(dir, Map[y][x]);
    if(dir == -1)
        return;

    int ny = y + MoveDir[dir].first;
    int nx = x + MoveDir[dir].second;

    if(ny <= 0 || N < ny || nx <= 0 || M < nx)
        return;
    
    if(Map[ny][nx] != '.'){
        bool temp = false;

        for(int i=0; i<5; i++){
            if(Pipe[dir][i] == Map[ny][nx]){
                temp = true;
                break;
            }
        }

        if(!temp) return;
    }

    //빈칸
    if(Map[ny][nx] == '.' && !flag){
        for(int i=0; i<4; i++){
            //대입
            Map[ny][nx] = Pipe[dir][i];

            DFS(ny, nx, dir, true, cnt);

            if(ClearFlag == true){
                EmptyPos.first = ny;
                EmptyPos.second = nx;
                Result = Pipe[dir][i];
                return;
            }
            Visit[ny][nx] = false;
            Map[ny][nx] = '.';
        }
    }
    else if(Map[ny][nx] != '.'){
        DFS(ny, nx, dir, flag, cnt);
        Visit[ny][nx] = false;
    }
}

int main(){
    cin >> N >> M;

    for(int i= 1; i<= N; i++){
        for(int j=1; j<=M; j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'M'){
                Start.first = i;
                Start.second = j;
            }

            if(Map[i][j] != '.') Total++;
        }
    }

    for(int i=0; i<4; i++){
        DFS(Start.first, Start.second, i, false, 0);
        if(ClearFlag)
            break;
        memset(Visit, false, sizeof(Visit));
    }

    cout << EmptyPos.first << " " << EmptyPos.second << " " << Result;
}