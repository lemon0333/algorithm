class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binarySearch 했을 때 몇번 해서 나오는지 나오는 문제 
        int left = 0;
        int right = nums.size()-1;
        int mid = (left+right)/2;
    
        int k = 0;
        int l = nums.size();
      
        
        while(left<=right){
            if(nums[mid] < target){
                left = mid+1;
                mid = (left+right)/2;
                
                k++;
            }
           else if(nums[mid]> target){
                right = mid-1;
                mid = (left+right)/2;
                 cout<<mid<<endl;
                k++;
            }
           else if(nums[mid] == target){
                k++;
                return mid;
            }
        }
        return -1;
    }
};