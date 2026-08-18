class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int currsum = 0;
        int answer = INT_MAX;

   for(int right = 0; right < nums.size(); right++){
currsum += nums[right];

while(currsum >= target){
// left 올리며 구하기 
answer = min(answer, right - left + 1 );
currsum -= nums[left];
left++;
}

   }

  return answer == INT_MAX ? 0 : answer;
    }
};