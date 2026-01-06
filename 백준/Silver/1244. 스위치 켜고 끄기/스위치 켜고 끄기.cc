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

void male(int a, vector<int> &contain, int N){
    for(int i = a; i< N; i+=(a+1)){
        contain[i] = 1-contain[i];
    }
}
void female(int a, vector<int> &contain, int N){
    int temp = 1;
  
        contain[a] = 1-contain[a];
   
   
    while(1){
        if(a + temp >= N || a - temp < 0){
            break;
        }
        
        if(contain[a+temp] == contain[a-temp]){
            contain[a+temp] = 1-contain[a+temp];
            contain[a-temp] = 1-contain[a-temp];
            temp++;
            continue;
        }
        else{
            break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    
    int N;
    cin>> N;
    
    vector<int> contain(N,0);
    int num;
    for(int i = 0; i< N; i++){
        cin>>num;
        contain[i] = num;
    }
    
    int people_number;
    cin>>people_number;
    vector<pair<int,int>> people;
    int a,b;
    for(int i = 0; i< people_number; i++){
        cin>>a>>b;
        people.push_back({a,b-1});
        
    }
    
    for(int i = 0; i< people_number;i++){
        int gender= people[i].first;
        // 성별이 남성일 경우
        if(gender == 1){
            male(people[i].second, contain, N);
        }
        else {
                female(people[i].second, contain, N);
        }
    }
    
    for(int i = 0; i<N; i++ ){
        cout<<contain[i] << " ";
        if((i+1)%20==0)
            cout<<endl;
    }
    
}


