#include <string>
#include <vector>
#include<set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> contain;
    for(int i = 0; i< numbers.size(); i++){
        for(int j = 0; j< numbers.size(); j++){
            if(i != j){
            int temp = numbers[j]+numbers[i];
            contain.insert(temp);
            }
            
        }
    }
   
    for(auto elem: contain){
        answer.push_back(elem);
    }
    return answer;
}