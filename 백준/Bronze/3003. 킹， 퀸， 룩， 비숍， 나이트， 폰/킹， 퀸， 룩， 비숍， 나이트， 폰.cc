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
int white;
int black;
void divi(int N, vector<vector<int>> contain){
 
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
  
    int num;
    vector<int> chess;
    for(int i = 0; i< 6; i++){
        cin>>num;
        chess.push_back(num);
    }
    // 1 1 2 2 2 2 8
    vector<int> cmp;
    cmp.push_back(1);
    
    cmp.push_back(1);
    cmp.push_back(2);
    cmp.push_back(2);
    cmp.push_back(2);
    
    cmp.push_back(8);
    
    vector<int> result;
    
    for(int i = 0; i< 6; i++){
       num= cmp[i]-chess[i];
        result.push_back(num);
    }
    for(auto elem: result){
        cout<<elem<<" ";
    }
    
    
    
}
