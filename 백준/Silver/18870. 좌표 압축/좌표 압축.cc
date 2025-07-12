#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cmath>
#include<unordered_map>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
  

    
  
    int N;
    cin>>N;
    int num;
    vector<int> contain;
    vector<int> real;
    for(int i = 0; i< N; i++){
        cin>>num;
        contain.push_back(num);
        real.push_back(num);
    }
    
    sort(contain.begin(), contain.end());
    auto it = unique(contain.begin(), contain.end());
    contain.erase(it,contain.end());
    
    unordered_map<int, int> mmap;
    for(int i = 0; i< contain.size() ; i++){
        mmap[contain[i]] = i;
    }
    vector<int> result;
    for(int i = 0; i< N; i++){
        auto it = mmap.find(real[i]);
        result.push_back(it->second);
        
    }
    for(auto elem: result){
        cout<<elem<<" ";
    }
    
    
}
