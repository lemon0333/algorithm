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
#include<vector>
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    
    long long int N;
    cin>> N;
   long long int result =0;
    int num;
    vector<long long int> contain(N+1,0);
    for(long long int i =0; i< N;i++){
        cin>>num;
        contain[i] = (num);
        
    }
    int B,C;
    cin>> B>>C;
    result += N;
    for(long long int i =0; i< N;i++){
        // 모든 시험장에서 B만큼빼기
        contain[i] -= B;
     
        // 응시자수가 0혹은 이하이면 컨티뉴해버리기
        if (contain[i] <=0)
            continue;
       
        if(contain[i]%C !=0){
            result += (contain[i]/C)+1;
        }
        else{
            result += (contain[i]/C);
        }
        
    }
    
    cout<<result;
}



