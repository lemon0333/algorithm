#include<string>
#include <iostream>
#include<stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
   
    stack<int> contain;
    for(int i = 0; i< s.size(); i++){
        char c ;
        c = s[i];
        if(c == '(')
            contain.push(1);
        else if (c == ')'){
         if(contain.empty()) {
                return false; 
            }
            contain.pop();
        }
    }
    if(!contain.empty())
        answer = false; 
    return answer;
}