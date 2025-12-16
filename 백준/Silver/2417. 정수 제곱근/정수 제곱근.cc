//
//  main.cpp
//  C++
//
//  Created by 손현빈 on 12/16/25.
//

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
size_t idx=0;
int main(){
    
    long long int A;
    cin>> A;
    long long int B;
    B = sqrt(A);
    if(B*B >= A)
    cout<<B;
    else
        cout<<++B;
        
        
    }



