#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    // command만큼 돌면서
   
    for(int i = 0; i< commands.size(); i++){
   vector<int> contain;
        // contain안에 부분 벡터를 넣음
        for(int j = commands[i][0]-1; j<=commands[i][1]-1 ; j++){
            contain.push_back(array[j]);
            
        }
        sort(contain.begin(),contain.end());
        answer.push_back(contain[commands[i][2]-1]);
        
    }
    return answer;
}