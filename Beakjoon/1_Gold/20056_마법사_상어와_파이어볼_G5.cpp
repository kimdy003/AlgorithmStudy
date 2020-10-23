#include <iostream>
#include <vector>

using namespace std;

typedef struct _FIRE{
    int y;
    int x;
    int size;
    int speed;
    int dir;
} FIRE;

int n, m, k;
vector<int> map[51][51];
vector<FIRE> fire;
int All[] = {0, 2, 4, 6};
int Not[] = {1, 3, 5, 7};

pair<int, int> movdir[] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void all_print(){
    cout <<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j].empty()){
                cout << "0 ";
            }
            else{
                cout << map[i][j][0] << " ";
            }
        }
        cout << "\n";
    }
}

void Move_Fireball(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j].clear();
        }
    }

    for(int i=0; i<fire.size(); i++){

        int y = fire[i].y;
        int x = fire[i].x;
        int speed = fire[i].speed;
        int dir = fire[i].dir;

        int ny = y + (movdir[dir].first*speed);
        int nx = x + (movdir[dir].second*speed);

        //범위 벗어나는 케이스에 대해 보정처리
		while (ny < 0)
		{
			ny = n + ny;
		}
		while (ny >= n)
		{
			ny = ny - n;
		}

		while (nx < 0)
		{
			nx = n + nx;
		}
		while (nx >= n)
		{
			nx = nx - n;
		}

        fire[i].y = ny;
        fire[i].x = nx;
        map[ny][nx].push_back(i);
    }
}

void SizeToUp(){
    vector<FIRE> temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j].empty()) continue;

            if(map[i][j].size() == 1){
                int num = map[i][j][0];
                FIRE a = fire[num];
                temp.push_back(a);
            }

            else if(map[i][j].size() >= 2){
                int size = map[i][j].size();
                int Total_size = 0;
                int Total_speed = 0;
                int even = 0, odd = 0;
                for(int k=0; k<size; k++){
                    Total_size += fire[map[i][j][k]].size;
                    Total_speed += fire[map[i][j][k]].speed;
                    if(fire[map[i][j][k]].dir % 2 == 0){
                        even += 1;
                    }
                    else{
                        odd += 1;
                    }
                }

                if(Total_size == 0 || Total_size/5 == 0){
                    continue;
                }

                int result_size = Total_size/5;
                int result_speed = Total_speed/size;

                if(even == 0 || odd == 0){
                    for(int d=0; d<4; d++){
                        temp.push_back({i, j, result_size, result_speed, All[d]});
                    }
                }
                else if(even > 0 && odd > 0){
                    for(int d=0; d<4; d++){
                        temp.push_back({i, j, result_size, result_speed, Not[d]});
                    }
                }
            }
        }
    }

    fire.clear();
    fire.swap(temp);
}

int main(){
    cin >> n >> m >> k;
    
    for(int i=0; i<m; i++){
        int a[5];
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
        fire.push_back({a[0]-1, a[1]-1, a[2], a[3], a[4]});
    }

    for(int i=0; i<k; i++){
        Move_Fireball();
        SizeToUp();
    }
    int ans = 0;
    for(int i=0; i<fire.size(); i++){
        ans += fire[i].size;
    }
    cout << ans;
}