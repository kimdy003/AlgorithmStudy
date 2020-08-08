//은기의 송아지 세기
#include <iostream>
#include <cstring>
using namespace std;
typedef struct calf_p{
    int x;
    int y;
    int z;
}calf_pri;
calf_pri calf[100001] = {0, };

int main(){

    int T;
    scanf("%d", &T);
    for(int test = 1; test <= T; test++){
        int n, q;
        scanf("%d %d", &n, &q);
        int x;
        for(int i=1; i<=n; i++){
            scanf("%d", &x);
            if(x == 1){
                calf[i].x = calf[i-1].x+1;
                calf[i].y = calf[i-1].y;
                calf[i].z = calf[i-1].z;
            }
            else if(x == 2){
                calf[i].x = calf[i-1].x;
                calf[i].y = calf[i-1].y+1;
                calf[i].z = calf[i-1].z;
            }
            else{
                calf[i].x = calf[i-1].x;
                calf[i].y = calf[i-1].y;
                calf[i].z = calf[i-1].z+1;
            }
        }
        

        int l, r;
        printf("#%d\n", test);
        for(int ques = 0; ques < q; ques++){
            scanf("%d %d", &l, &r);
            printf("%d %d %d \n", calf[r].x - calf[l-1].x, calf[r].y - calf[l-1].y, calf[r].z - calf[l-1].z);
        }

    }
}