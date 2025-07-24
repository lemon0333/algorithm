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
    
    int N;
  
    cin >> N;
    
    
    vector<int> dp(N+1,1e9);
    if(N == 1){
        cout<< -1;
        return 0;
    }
    if(N == 2){
        cout<< 1;
        return 0;
    }
    if(N == 3){
        cout<< -1;
        return 0;
    }
    if(N == 4){
        cout<< 2;
        return 0;
    }
    if(N == 5){
        cout<< 1;
        return 0;
    }
    dp[0] = 0;
   
    for(int i = 1; i <= N; ++i){
         if (i >= 2 && dp[i-2] != 1e9)
             dp[i] = min(dp[i], dp[i-2] + 1);
         if (i >= 5 && dp[i-5] != 1e9)
             dp[i] = min(dp[i], dp[i-5] + 1);
     }
    
    cout<<dp[N];
}
