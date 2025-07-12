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
 

    int N;
    cin>> N;
    int num;
    queue<int> que;
    stack<int> st2;
    stack<int> st1;

    vector<int> result;
    for(int i  = 0 ; i< N ; i ++){
        cin>>num;
        que.push(num);
    }
    
    
    int current = 1;
    
    bool possible = true;
    while(!que.empty() || !st2.empty()){
        
        if(!que.empty()&& que.front() == current){
            current++;
            que.pop();
            
        }
       else if(!st2.empty()  && st2.top() == current){
            current ++;
            st2.pop();
        }
        
       else if (!que.empty() ){
          int pre = que.front();
           que.pop();
           st2.push(pre);
       }
       else{
        possible = false;
           break;
           
       }
        
    }
    
    
    if(possible){
        cout<<"Nice";
        return 0;
    }

    
    cout<<"Sad";
    
    
}
