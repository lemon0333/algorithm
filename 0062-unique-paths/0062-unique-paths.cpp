class Solution {
public:
    int uniquePaths(int m, int n) {
        // 다차원 dp
        // 어렸을 떄 풀었던 가는 경우의수 구하는거 이전의 경우의 수를 더하면 됨 
        if(m==1 || n==1) return 1;
        vector<vector<int> >dp (m+1,vector<int> (n+1,0));
        for(int i = 1; i< m; i++){
            for(int j = 1; j< n; j++){
                if(i-1 == 0) dp[i-1][j] = 1;
                if(j-1 == 0) dp[i][j-1] = 1;
               
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};