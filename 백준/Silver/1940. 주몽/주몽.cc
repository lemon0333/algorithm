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
    
    
    int N,M;
    int num;
    cin>> N>>M;
    vector<int> contain(N,0);
    for(int i = 0; i< N; i++){
        cin>> num;
        contain[i] = num;
    }
    int result=0;
    sort(contain.begin(),contain.end());
    for(int i = 0; i< N; i++){
        
        int temp = contain[i];
        int target = M - temp;
        if(find(contain.begin(),contain.end(), target) != contain.end()){
            result++;
        }
    }
    cout<<result/2;
}


