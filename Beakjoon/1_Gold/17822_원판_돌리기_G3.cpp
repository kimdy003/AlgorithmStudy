//20.09.14
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int n, m, t;
deque<int> dq[51];

bool del(){
    bool check[51][51];
    memset(check, false, sizeof(check));

    //������ ���� ���ֱ�
    bool del_flag = false;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(dq[i][j] == 0) continue;

            bool flag = false;
            //�� �Ʒ�
            if(i+1 <= n){
                if(dq[i][j] == dq[i+1][j]){
                    check[i+1][j] = true;
                    flag = true;
                }
            }
            if(i-1 > 0){
                if(dq[i][j] == dq[i-1][j]){
                    check[i-1][j] = true;
                    flag = true;
                }
            }

            //�� ��
            int cur_l = j-1 < 0 ? m-1 : j-1;
            int cur_r = j+1 >= m ? 0 : j+1;
            if(dq[i][j] == dq[i][cur_l]){
                check[i][cur_l] = true;
                flag = true;
            }
            if(dq[i][j] == dq[i][cur_r]){
                check[i][cur_r] = true;
                flag = true;
            }

            //�ϳ��� ����� �ִٸ�
            //���� ��ġ�� check�� true
            if(flag){
                check[i][j] = true;
                del_flag = true;
            }
        }
    }

    if(del_flag == true){
        for(int i=1; i<=n; i++){
            for(int j=0; j<m; j++){
                if(check[i][j] == false) continue;
                dq[i][j] = 0;
            }
        }
    }

    return del_flag;
}

void avg(){
    double total = 0.0;
    double cnt = 0.0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(dq[i][j] != 0){
                total += (double)dq[i][j];
                cnt++;
            }
        }
    }

    double avage = total/cnt;

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(dq[i][j] == 0) continue;

            // ��պ��� ������
            if(avage - (double)dq[i][j] > 0 ){
                dq[i][j] += 1;
            }

            //��պ��� ������
            else if(avage - (double)dq[i][j] < 0){
                dq[i][j] -= 1;
            }
        }
    }
}

void cycle(int x, int d, int k){
    //���� ������
    for(int i=1; i<=n; i++){
        if(i%x == 0){
            for(int j=0; j<k; j++){
                //�ð����
                if(d == 0){
                    dq[i].push_front(dq[i].back());
                    dq[i].pop_back();
                }
                else{
                    dq[i].push_back(dq[i].front());
                    dq[i].pop_front();
                }
            }
        }
    }

    if(del() == false){
        avg();
    }
}

int main(){
    cin >> n >> m >> t;

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            dq[i].push_back(x);
        }
    }

    int x, d, k;
    for(int i=0; i<t; i++){
       cin >> x >> d >> k;

       cycle(x, d, k); 
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            ans += dq[i].front();
            dq[i].pop_front();
        }
    }

    cout << ans;
}