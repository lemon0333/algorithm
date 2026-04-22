#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();
    sort(people.begin(),people.end());
    int left = 0;
    int right = size -1;
    while(left <= right){
        if(people[left] + people[right] <= limit){
           left ++;
            right --;
            answer ++;
        }
        else {
            answer ++;
            right --;
        }
        
    }
    
    return answer;
}