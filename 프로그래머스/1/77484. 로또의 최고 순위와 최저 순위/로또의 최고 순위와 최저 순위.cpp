#include <string>
#include <vector>
#include<algorithm>
#include<utility>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int result = 7;
    for(int i = 0; i< 6; i++){
   // 만약에 찾았다면
        auto it = find(win_nums.begin(),win_nums.end(), lottos[i]);
        if( it != win_nums.end()){
       result--;
           
   }
        }
    
    int resultf = result;
    for(int i = 0; i< 6; i++){
   if(lottos[i] == 0)
   {
       resultf--;
   }
    }
    if(resultf == 7){
        answer.push_back(6);
    }
    else
    answer.push_back(resultf);
    if(result == 7){
        answer.push_back(6);
    }
    else{
    answer.push_back(result);
    }
        return answer;
}