#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> contain;
    
    for(int i = 0; i < progresses.size(); i++){
        
        int k = (99 - progresses[i]) / speeds[i] + 1;
        
        
        if(!contain.empty() && contain.top() >= k){
            contain.push(contain.top());
        }
        else{
            contain.push(k);
        }
    }

    vector<int> seperate;
    while(!contain.empty()){
        int a = contain.top();
        contain.pop();
        seperate.push_back(a);
    }
    reverse(seperate.begin(), seperate.end());


    if (seperate.empty()) return {}; 

    int count = 1;
    for(int i = 1; i < seperate.size(); i++) {
        if (seperate[i] == seperate[i - 1]) {
            count++; 
        } 
        else {
            answer.push_back(count); 
            count = 1;               
        }
    }
    answer.push_back(count); 
    
    return answer;
}