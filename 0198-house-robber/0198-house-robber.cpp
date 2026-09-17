class Solution {
public:
    int rob(vector<int>& nums) {
        // 인접한거는 바로 못먹나봄 max를 통한 점화식 세우면 될 것 같음 
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        if(nums.size() == 1) return nums[0];
        dp[1] = max(nums[1], nums[0]);
        if(nums.size() == 2) return dp[1];
        for(int i = 1; i< nums.size()-1; i++)
        {
                dp [i+1] = max(dp[i-1]+ nums[i+1],dp[i] );
        }
        return dp[nums.size()-1];
    }
};