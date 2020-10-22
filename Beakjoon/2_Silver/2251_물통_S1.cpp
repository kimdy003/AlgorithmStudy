#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int A, B, C;
bool visit[201][201][201];
queue<pair<pair<int, int>, int>> q;
vector<int> v;

void BFS(){
    q.push({{0, 0}, C});
    
    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();

        if(visit[a][b][c] == true) continue;
        visit[a][b][c] = true;

        if(a == 0) v.push_back(c);

        // A물통에서 B물통
        if(a+b > B) q.push({{a+b - B, B}, c});
        else q.push({{0, a+b}, c});

        // A -> C
        if(a+c > C) q.push({{a+c -C, b}, C});
        else q.push({{0, b}, a+c});

        // B -> A
        if(b+a > A) q.push({{A, b + a -A}, c});
        else q.push({{b+a, 0}, c});
        
        // B -> C
        if(b+c > C) q.push({{a, b+c-C}, C});
        else q.push({{a, 0}, b+c});
        
        // C -> A
        if(c+a > A) q.push({{A, b}, c+a-A});
        else q.push({{a+c, b}, 0});
        
        // C -> B
        if(c+b > B) q.push({{a, B}, c+b-B});
        else q.push({{a, b+c}, 0});
        
    }

    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}


int main(){
    cin >> A >> B >> C;

    BFS();

    return 0;
}