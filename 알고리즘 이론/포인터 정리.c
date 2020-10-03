#include <stdio.h>

void malloc(int * gpu){
    printf("----\n");
    printf("%d\n", gpu);
    printf("%d\n", &gpu);
}

void point(int ** point){
    printf("dddddddd\n");
    printf("%d", point);
}

int main(){
    int a = 19;
    int b = 20;
    int * weigh = &a;
    int *indata[2];

    indata[0] = &b;
    printf("%d\n", &a);
    printf("%d\n", a);
    printf("%d \n", weigh);
    printf("%d \n", *weigh);
    printf("%d \n", &weigh);

    printf("0000000\n");
    printf("%d\n", &b);
    printf("%d\n", &indata[0]);

    //malloc(weigh);
    //point(&weigh);

    return 0;
}