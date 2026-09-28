class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        // 일단 정렬하고 
        int r = 0;
        sort(nums.begin(), nums.end());
        while(left< right){
            int temp = nums[left] + nums[right];
            if(temp == k) {
                r++;
                left++;
                right--;
                }
                if(temp > k){
                    right--;
                }
                if(temp < k){
                    left++;
                }

        }
    return r;
    }
};