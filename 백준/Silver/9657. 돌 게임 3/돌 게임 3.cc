#include <iostream>
#include <vector>
#include<string>
#include <queue>
#include<cmath>
#include <algorithm>

using namespace std;




bool visited[5][5];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
long long int result;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>> N;
    vector<int> dp (N+1,0);
    // 1을 SK, 0을 CY로 하자
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    for(int i = 5; i<= N; i++){
        if(dp[i-1] == 1 && dp[i-3] == 1 && dp [i-4] == 1){
            dp[i] = 0;
        }
        else
            dp[i]= 1;
    }
    if(dp[N] == 1){
        cout<< "SK";
    }
    else
        cout<<"CY";
}
