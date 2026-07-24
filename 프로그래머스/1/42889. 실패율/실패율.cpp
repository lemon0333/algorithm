#include <string>
#include <vector>
#include<utility>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 실패율을 저장하는 공간, 전체 분모를 저장하는 공간 이렇게 두개는 무조건 필요 
    vector<pair<int,double>> failure_rate;
    int divider = stages.size();
    for(int i = 1; i<= N; i++){
        int temp = 0;
        for(int j = 0; j< stages.size(); j++){
            
        if(stages[j] == i)
            temp++; 
            }
        // 하나 스테이지에 대해서 몇명이나 있는지 조사 완료
        if(divider !=0){
            double r = double(temp)/divider;
        failure_rate.push_back({i,r});
            cout<<i<<"번쨰"<<endl;
            cout<<divider<<endl;
            cout<< temp<<endl;
        divider -= temp;
        }
        else {
            failure_rate.push_back({i,0});
        }
    }
    
    sort(failure_rate.begin(), failure_rate.end(),
         [](const pair<int,double> &a,const pair<int,double> &b){
   if (a.second != b.second) return a.second > b.second;  
         return a.first < b.first;
    });
    for(int i = 0; i< N; i++){
        answer.push_back(failure_rate[i].first);
    }
    return answer;
}