class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      // find three integers at distinct 
    // 아 연속한 정수 세개일 필요가 없구나 
    // 일단 삼중포문 해볼까
    int result = nums[0] + nums[1] + nums[2];
    if(nums.size() == 3) return result;
    int sum = 0;
    for(int i = 0; i< nums.size(); i++){
        for(int j = i+1; j< nums.size(); j++){
            for(int k = j+1; k< nums.size(); k++){
                // i,j,k에 대해서 
            sum = nums[i] + nums[j] + nums[k];
            if(abs(result - target) > abs(sum - target))
                result = sum;


            }
        }


    }
    
return result;
    }    
    
    
};