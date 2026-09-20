class Solution {
public:
    void moveZeroes(vector<int>& nums) {

  vector<int> contain = nums;
      for(int i = 0; i< nums.size();i++){
        // 만약 0이라면 
        if(nums[i] == 0){
            contain.push_back(0);
            contain[i] = INT_MIN;
        }
      }
      nums.clear();
for(int i = 0; i< contain.size(); i++){
    if(contain[i] != INT_MIN){
        nums.push_back(contain[i]);
    }
}
    }
};