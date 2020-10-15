#include <iostream>

using namespace std;

int Date[10] = {4,9,5,7,1,6,8,3,2,10};

void quick(int *Date, int start, int end){
    //원소가 1인 부분을 생각 못했음 -> 블로그 참고
    if(start >= end){
        return;
    }

    int key = start;
    int left = start +1;
    int right = end;
    int temp;

    while(left < right){
        while(Date[left] <= Date[key]){
            left++;
        }
        while(Date[right] >= Date[key] && right > start){
            right--;
        }

        if(left < right){
            temp = Date[right];
            Date[right] = Date[left];
            Date[left] = temp;
        }
        else{
            temp = Date[key];
            Date[key] = Date[right];
            Date[right] = temp;
        }
    }

    quick(Date, start, right-1);
    quick(Date, right+1, end);


}


int main(){
    quick(Date, 0, 9);
    for(int i=0; i< 10; i++){
        printf(" %d", Date[i]);
    }
}