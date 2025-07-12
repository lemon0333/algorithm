#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cmath>
#include<unordered_map>
using namespace std;


int dp(vector<int> &contain, int N){
    contain[0]=0;
    contain[1]=1;
    contain[2]=2;
    if(N==1){
        return 1;
    }
    else if(N==2){
        
    return 2;
    }
    else{
        for(int i = 3; i<=N;i++){
            contain[i]= (contain[i-1] + contain[i-2]) % 15746;
        }
        return contain[N];
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int N;
    cin>>N;
    vector<int> contain(N+1,-1);
    
  cout<<  dp(contain, N) % 15746;
 
}
