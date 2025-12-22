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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int T;
    cin>> T;
    int a;
    for(int i = 0; i< T; i++){
        cin>>a;
        int r1,r2,r3,r4;
        int contain;
        r1 = a / 25;
        a = a%25;
        r2 = a/10;
        a = a% 10;
        r3 = a/5;
        a=a%5;
        r4 = a;
        cout<<r1<< " "<<r2 << " "<<r3 << " "<<r4 <<"\n";
        
    }
    
}


