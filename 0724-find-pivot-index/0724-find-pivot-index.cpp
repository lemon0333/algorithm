class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int cursum = 0;
        vector<int> cumsum(nums.size(),0);
    
        for(int i = 0; i< nums.size(); i++){
            cursum += nums[i];
            cumsum[i] = cursum;
        }
      int pivot;
      int leftsum =0;
      int rightsum=0;
        for(pivot = 0 ; pivot < nums.size(); pivot++){
          
            if(pivot != 0) leftsum = cumsum[pivot-1];
if(pivot == 0) leftsum = 0;
            if(pivot == nums.size()-1) rightsum = 0;
            if(pivot != nums.size()-1) rightsum = cumsum[nums.size()-1] - cumsum[pivot];
           
            if(leftsum == rightsum){
                 cout<<leftsum<<rightsum<< pivot<<endl;
                return pivot;
            } 
        }
            // cursum으로 변환하면 1 8 11 19 24 30 
            // 0 1 2 의 합은 11 
            // 4 5 의 합은 30 - pivot의 index의 cursum
            return -1;
        
    }
};