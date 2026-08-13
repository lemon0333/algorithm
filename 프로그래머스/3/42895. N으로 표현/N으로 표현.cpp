#include <string>
#include <vector>

using namespace std;
void dp(vector<int> first , vector<int> second, vector<int> & target){
    
     for(int i = 0; i< first.size(); i++){
        for(int j = 0; j< second.size() ; j++){
     
            int temp ;
            temp = first[i] * second[j];
            target.push_back(temp);
            
            temp = first[i] + second[j];
            target.push_back(temp);
            
            temp = first[i] - second[j];
            target.push_back(temp);
            
            temp = second[j] - first[i]  ;
            target.push_back(temp);
            
            if(second[j] != 0){
            temp = first[i] / second[j];
            target.push_back(temp);
            }
            if(first[i] != 0){
            temp =  second[j] / first[i] ;
            target.push_back(temp);
            }
           
            
            
        }
     
     }
    
}

int solution(int N, int number) {
    int answer = 0;
    vector<int> one;
    
    vector<int> two;
    
    vector<int> three;
    
    vector<int> four;
    
    vector<int> five;
    
    vector<int> six;
    
    vector<int> seven;
    
    vector<int> eight;
    
    one.push_back(N);
    // 결과가 2인거 초기화
    for(int i = 0; i< one.size(); i++){
        int temp;
       temp = one[i] * one[i];
        two.push_back(temp);
        temp = one[i] / one[i];
        two.push_back(temp);
        temp = one[i] - one[i];
        two.push_back(temp);
        temp = one[i] + one[i];
        two.push_back(temp);
        temp = one[i] * 10 + one[i];
        two.push_back(temp);
    }
    
    // 결과가 3인거 초기화
    two.push_back(N*10 + N);
    three.push_back(N* 100 + N * 10 + N);
    four.push_back(N* 1000 + N * 100 + N * 10 + N);
    
    five.push_back(N* 10000 +N *1000 + N * 100 + N * 10 + N);
    
    six.push_back(N* 10000 +N *1000 + N * 100 + N * 10 + N + N * 100000);
    
    seven.push_back(N* 10000 +N *1000 + N * 100 + N * 10 + N + N * 100000 +N * 1000000 );

    eight.push_back(N* 10000 +N *1000 + N * 100 + N * 10 + N + N * 100000 +N * 1000000 + N * 10000000);
    
  dp(one,two,three);
    // 결과가 4인거 초기화 
    dp(two,two,four);
    dp(one,three,four);
    // 결과가 5인거 초기화
    dp(two,three, five);
    dp(one,four,five);
    // 결과가 6인거 초기화 
    dp(three,three,six);
    dp(one,five,six);
    dp(two,four,six);
    // 결과가 7인거 초기화
    dp(three,four,seven);
    dp(two,five,seven);
    dp(one,six,seven);
    // 결과가 8ㅇ인거 초기화
    dp(one,seven, eight);
    dp(two,six,eight);
    dp(three,five,eight);
    dp(four,four,eight);
    
    
    for(auto elem : one){
        if(elem == number)
            return 1;
    }
    
    for(auto elem : two){
        if(elem == number)
            return 2;
    }
    
    for(auto elem : three){
        if(elem == number)
            return 3;
    }
    
    for(auto elem : four){
        if(elem == number)
            return 4;
    }
    
    for(auto elem : five){
        if(elem == number)
            return 5;
    }
    
    for(auto elem : six){
        if(elem == number)
            return 6;
    }
    
    for(auto elem : seven){
        if(elem == number)
            return 7;
    }
    
    
    for(auto elem : eight){
        if(elem == number)
            return 8;
    }
    return -1;
    
    
    }