class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

         int windowSum = 0;
        for(int i = 0; i < k; i++)
            windowSum += nums[i];

        int maxSum = windowSum;
        for(int i = k; i < (int)nums.size(); i++){
            windowSum += nums[i] - nums[i - k]; 
            if(windowSum > maxSum) maxSum = windowSum;
        }
        return double(maxSum) / k;
    }
    
};