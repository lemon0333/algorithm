#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
stack<char> contain;
    for(int i = 0; i< s.size(); i++){
        
        
        if(  !contain.empty()&& s[i] == contain.top()){
           contain.pop(); 
        }
        else{
        contain.push(s[i]);
        }
    }
    if(contain.empty()){
answer = 1;
    }
    else{
   answer = 0;
    }
    
  
    return answer;
}