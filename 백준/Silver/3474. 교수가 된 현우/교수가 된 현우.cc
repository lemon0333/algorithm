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
    ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      
    int T;
   long long int num;
    cin>> T;
    
    
    for(int i = 0; i< T ; i++){
        cin>> num;
       long long int all = 0;
       all = num/5 + num / 25 + num/ 625 + num/125+ num/3125 + num/15625 + num/78125 + num/390625 + num/1953125 + num/9765625 + num / 48828125 + num/244140625;
        cout<<all<<"\n";
    }
 
    }



