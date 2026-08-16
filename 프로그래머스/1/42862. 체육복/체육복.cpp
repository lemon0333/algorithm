#include <string>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());          // ③ 정렬
    sort(reserve.begin(), reserve.end());

    for(int i = 0; i< lost.size(); i++){
        for(int j = 0; j< reserve.size() ; j++){
            // 만약 lost가 reserve랑 일치하면 reserve를 죽여야함 
            if(lost[i] == reserve[j]){
                answer++;
                reserve[j] = -1;
                lost[i] = -1;
                break;
            }
            
        }
    }
      answer += n - lost.size();
    // 체육복 빌려주기 
    for(int i = 0; i< lost.size(); i++){
      int temp = lost[i];
     
        for(int j = 0; j< reserve.size(); j++){
            if(temp-1 == reserve[j] || temp+1 == reserve[j]){
                answer++;
                reserve[j] = -1;
                break;
                
            }
        }
        
    }
    return answer;
}