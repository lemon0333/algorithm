#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cmath>
#include<unordered_map>
#include<stack>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n;
    int m;
    int num;
    vector<int> cA;
    cin>>n>>m;
    for(int i = 0; i< n; i++){
        cin>>num;
        cA.push_back(num);
    }
    vector<int> cB;
    for(int i = 0; i< m; i++){
        cin>>num;
        cA.push_back(num);
    }
    sort(cA.begin(),cA.end());
    for(auto elem: cA){
        cout<<elem<<" ";
    }
}

