#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, m, king;
map<string, vector<string>> family;
map<string, double> blood;

double DFS(string name){
    if(family[name].empty())
        return blood[name];

    string parent1 = family[name][0];
    string parent2 = family[name][0];
    double ret = (DFS(parent1) + DFS(parent2)) /2; 
    blood[name] = ret;
    return ret;
}

void init(){
    for(auto element : blood){
        element.second = 0;
    }
    blood[king] = 1;
}

int main(){
    cin >> n >> m;
    cin >> king;

    for(int i=0; i<n-1; i++){
        string parent1, parent2, child;
        cin >> child >> parent1 >> parent2;

        family[child].push_back(parent1);
        family[child].push_back(parent2);
        blood[child] = blood[parent1] = blood[parent2] = 0;
    }

    double ans = 0;
    string next_king = "";
    for(int i=0; i<m; i++){
        string candidate;
        cin >> candidate;

        init();
        double temp = DFS(candidate);
        if(ans < temp){
            ans = temp;
            next_king = candidate;
        }
    }

    cout << next_king;
}