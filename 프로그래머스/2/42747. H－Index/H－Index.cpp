#include <string>
#include <vector>
#include<iostream>
using namespace std;
#include<algorithm>
int solution(vector<int> citations) {
    int answer = 0;
    // 정렬해주기 
    sort(citations.begin(), citations.end());
    int N = citations.size();
    vector<int> new_contain;
 
    for(int i = 0; i< N ; i++){
        
         int cnt = N - i;                 
        if(citations[i] >= cnt) {      
            answer = cnt;   
            break;
        }
         
    }    

    
    
    return answer;
}