#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cmath>
#include<unordered_map>
#include<stack>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
  
    
  
    vector<int> result;
    int N;
    cin>> N;
    int K;
    cin>> K;
    vector<int> coin;
    int num;
    for(int i = 0; i< N;i++){
        cin>>num;
        coin.push_back(num);
    }
    vector<int> dp(K+1,1e9);
    dp[0]=0;
    for(int i = 1; i<= K;i++){
        for(int j = 0; j< N;j++){
            if(i>= coin[j] && dp[i-coin[j]] != 1e9)
                dp[i] = min(dp[i],dp[i-coin[j]] +1);
        }
        
        
    }
    if(dp[K] == 1e9){
        cout<<-1;
        return 0;
    }
    
    cout<<dp[K];
    
     
      
    

}
