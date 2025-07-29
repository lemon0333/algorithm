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
    cin>>n;
    int num;
    vector<int> contain;
    int k;
    cin>>k;
    for(int i = 0; i< n; i++){
        cin>>num;
        contain.push_back(num);
    }
    sort(contain.begin(),contain.end());
    cout<<contain[k-1];
}

