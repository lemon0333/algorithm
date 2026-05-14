#include <string>
#include <vector>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first(5,0);
    for(int i = 0; i< 5; i++){
        int j = i+1;
        first[i] = (j);
    }
    vector<int> second(8,0);
    second[0 ] = (2);
    second[1] = (1);
    second[2] = (2);
    second[3] = (3);
    second[4] = (2);
    second[5] = (4);
    second[6] = (2);
    second[7] = (5);
    vector<int> third(10);
    third[0] = 3;
    third[1] = 3;
    third[2] = 1;
    third[3] = 1;
    third[4] = 2;
    third[5] = 2;
    third[6] = 4;
    third[7] = 4;
    third[8] = 5;
    third[9] = 5;

    
  int fr = 0;
    int sr = 0;
    int tr = 0;
    for(int i = 0; i< answers.size(); i++){
        int right = answers[i];
        if (right == first[i%5])
            fr++;
         if (right == second[i%8])
            sr++;
         if (right == third[i%10])
            tr++;
        
    }
    cout<<tr;
    int max_val = std::max({fr, sr, tr});
    if(max_val == fr) answer.push_back(1);
     if(max_val == sr) answer.push_back(2);
     if(max_val == tr) answer.push_back(3);
    return answer;
}