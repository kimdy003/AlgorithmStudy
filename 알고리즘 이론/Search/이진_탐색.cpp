#include <iostream>
#include <vector>
using namespace std;

int n, target;
vector<int> v;

#if 1
//재귀를 이용한 이진 탐색
int Binary_Search(vector<int> v, int target, int start, int end){
    if(start > end)
        return -1;

    int mid = (start + end) / 2;

    //찾은 경우 중간점 인덱스 반환
    if(v[mid] == target)
        return mid;

    else if(target < v[mid])
        return Binary_Search(v, target, start, mid-1);

    else
        return Binary_Search(v, target, mid+1, end);
}

#else
//반복문을 이용한 이진 탐색
int Binary_Search(vector<int> v, target, int start, int end){
    while(start <= end){
        int mid = (start + end) / 2;
        if(v[mid] == target)
            return mid;

        else if(target < v[mid])
            end = mid -1;
        
        else
            start = mid + 1;
    }

    return -1;
}

#endif


int main(){
    cin >> n >> target;

    for(int i=0; i<n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int result = Binary_Search(v, target, 0, n);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}