class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    // 문제 생각 방안 : 전체곱을 우선 구해놓고서 나눠가면서 보여주려고 했다 
    // 하지만 원소에 0이 있을 수 있다는 문제가 있었음 
    // 투포인터같이 자기자신을 제외해야하니까 거기로부터 왼쪽과 오른쪽 곱을 나누고 그걸 곱해주는 방식으로 해보자 

 

    vector<int> result(nums.size());
    result[0] =1 ;
    for(int i = 0; i< nums.size()-1;i++){
result[i+1] = result[i] * nums[i];
    }
int right = 1;
    for(int j = nums.size()-1 ; j>=0; j--){
        result[j] *= right;
        right *= nums[j];
    }
return result;
    }
};