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
using ll = long long;

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
bool is_prime(int n){
    for(int i = 2; i< n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int N;
    int M;
    cin>> N>>M;
   
    set<int> unique;
    vector<int> cmp(N,0);
    for(int i = 0; i< N; i++){
        cmp[i] = i+1;
    }
    for(int i = 0; i< M; i++){
        int num;
        cin>> num;
        unique.insert(num);
    }
    vector<int> contain(unique.begin(), unique.end());
    
    sort(contain.begin(),contain.end());
    vector<int> classic;
    for(int i = 0; i< N; i++){
        // 찾는 원소가 없다면
        if( find(contain.begin(),contain.end(),i+1) == contain.end() ){
            classic.push_back(i+1);
        }
    }
    if(classic.empty()){
        cout<<0;
        return 0;
    }
    int total_cost = ((int)classic.size()) * (5 +2);
    // 인접한 빠진 페이지들 사이의 간격 저장
        vector<int> gaps;
        for(int i=0; i < (int)classic.size() - 1; i++) {
            gaps.push_back(classic[i+1] - classic[i] + 1);
        }
        sort(gaps.begin(), gaps.end());
    
    for (auto elem : gaps){
        if(2* elem < 9){
            total_cost -= (9-2*elem);
        }
        
    }
    cout<<total_cost;
    // 1, 2, 6, 8 이 클래식에 담김
}


