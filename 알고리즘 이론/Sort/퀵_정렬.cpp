#include <iostream>
using namespace std;

int data[10] = {4,9,5,7,1,6,8,3,2,10};

void quick(int *data, int start, int end){
    //원소가 1인 부분을 생각 못했음 -> 블로그 참고
    if(start >= end){
        return;
    }

    int key = start;
    int left = start +1;
    int right = end;
    int temp;

    while(left < right){
        while(data[left] <= data[key]){
            left++;
        }
        while(data[right] >= data[key] && right > start){
            right--;
        }

        if(left < right){
            temp = data[right];
            data[right] = data[left];
            data[left] = temp;
        }
        else{
            temp = data[key];
            data[key] = data[right];
            data[right] = temp;
        }
    }

    quick(data, start, right-1);
    quick(data, right+1, end);


}


int main(){
    quick(data, 0, 9);
    for(int i=0; i< 10; i++){
        printf(" %d", data[i]);
    }
}