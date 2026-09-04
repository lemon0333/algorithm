class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
       vector<int> subsum;
       int temp = 0;
       int cur = nums[0];
       int best = nums[0];
      
        // 각 구간 끼리의 누적합을 구함 b에서 a까지의 구간합은 b의 누적합 - a의 누적합이니까 
        // 위의 방법으로 하면 ) n ^2라 터지게 됨 . nlogn으로 가야함 

        int result = INT_MIN;
        for(int i = 1; i< nums.size(); i++){

            cur = max(nums[i], cur+ nums[i]);
            best = max(best,cur);
        }
return best;
    }
};