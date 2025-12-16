//
//  main.cpp
//  C++
//
//  Created by 손현빈 on 12/16/25.
//

#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

int facto(int sth){
    int r = 1;
    for(int i = 1; i <=sth ; i++){
        r *= i;
    }
    return r;
}

int roma(int A){
    // 4+ A -1 C A
    int upper = facto(4+A-1);
    int down = facto(A);
    int down2 = facto(3);
    int result = upper / (down * down2);
    return result;
}

int main(){
  
    int A,B;
    cin>> A;
    
    vector<set<int>> dp(A+1) ;
    vector<int> contain;
    contain.push_back(1);
    contain.push_back(5);
    contain.push_back(10);
    contain.push_back(50);
    //초기값 설정
    dp[0].insert(0);
    
    for(int i = 1; i<=A; i++){
        for (auto elem: contain){
            for(int x : dp[i-1]){
                dp[i].insert( x+ elem);
            }
            
        }
    }
    cout<<(dp[A]).size();
    }



