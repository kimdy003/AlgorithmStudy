#include <iostream>
#include <vector>
using namespace std;

int n, target;
vector<int> v;

#if 1
//��͸� �̿��� ���� Ž��
int Binary_Search(vector<int> v, int target, int start, int end){
    if(start > end)
        return -1;

    int mid = (start + end) / 2;

    //ã�� ��� �߰��� �ε��� ��ȯ
    if(v[mid] == target)
        return mid;

    else if(target < v[mid])
        return Binary_Search(v, target, start, mid-1);

    else
        return Binary_Search(v, target, mid+1, end);
}

#else
//�ݺ����� �̿��� ���� Ž��
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
        cout << "���Ұ� �������� �ʽ��ϴ�." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}