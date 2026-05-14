#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int square = brown + yellow;
    vector<int> divide;
    int w;
    int h;
   for(int i = 3; i< square; i++){
       if(square%i == 0){
        w = (square/i);
     h = i;
           }
       if( (w-2) * (h-2) == yellow){
           answer.push_back(w);
           
           answer.push_back(h);
           break;
       }
       
   }
    
    return answer;
}