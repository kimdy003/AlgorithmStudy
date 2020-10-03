#include <iostream>
#include <vector>
#define NUMBER 12
using namespace std;

int a[] = {1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5};
int tree[4*NUMBER]; //4를 곱하면 모든 범위를 커버할 수 있음. 
                    //갯수에 대해서 2의 제곱 형태의 길이를 가지기 때문

int init(int start, int end, int node){
    if(start == end) 
        return tree[node] = a[start];
    
    int mid = (start+end) / 2;
    //재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기자신으로 한다.
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

//start : 시작 인덱스, end : 끝 인덱스
//left, right : 구간 합을 구하고자 하는 범위
int sum(int start, int end, int node, int left, int right){
    //범위 밖에 있는 경우
    if(right < start || end < left)
        return 0;
    
    //범위 안에 있는 경우
    if(left <= start && end <= right)
        return tree[node];

    //그렇지 않다면 두 부분으로 나누어 합을 구하기
    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, int dif){
    //범위 밖에 있는 경우
    if(index < start || end < index)
        return;

    //범위 안에 있으면 내려가며 다른 원소도 갱신
    tree[index] += dif;
    if(start == end) return;

    int mid = (start + end) / 2;
    update(start, mid, node *2, index, dif);
    update(mid+1, end, node * 2+1, index, dif);
}

int main(){
    //구간 합 트리의 인덱스를 제외하고는 모두 인덱스 0부터 시작
    //구간 합 트리 생성
    init(0, NUMBER - 1, 1); 

    //구간 합 구하기
    cout << "0부터 12까지의 구간 합" << sum(0, NUMBER-1, 1, 0, 12) << "\n";
    cout << "3부터 8까지의 구간 합" << sum(0, NUMBER-1, 1, 3, 8) << "\n";

    //구간 합 갱신하기
    cout << "인덱스 5의 원소를 -5만큼 수정" << "\n";
    update(0, NUMBER-1, 1, 5, -5);

    //구간 합 다시 구하기
    cout << "3부터 8까지 구간 합" << sum(0, NUMBER-1, 1, 3, 8);

}