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
    
    int num;
    vector<int> contain;
    vector<int> contain2;
    int sum=0;
    for(int i = 0; i< 8; i++){
        cin>>num;

        contain.push_back(num);
        contain2.push_back(num);
        
    }
    vector<int> result;
    sort(contain.begin(),contain.end());
    for(int i =0; i< 8; i++){
        if(contain2[i] == contain[7] ||contain2[i] == contain[6] ||contain2[i] == contain[5] ||contain2[i] == contain[4] ||contain2[i] == contain[3] ){
            result.push_back(i+1);
        }
    }
    sum = contain[7] + contain[6] + contain[5] + contain[4] + contain[3];
    sort(result.begin(),result.end());
    cout<<sum<<endl;
    for(auto elem: result){
        cout<<elem<<" ";
    }
    
}

