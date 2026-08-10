

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
       // 보기의 그런것들을 만족하는 조합들을 뽑아오면 된다 
    sort(nums.begin(),nums.end());
    // 2포인터로 풀껀데 위치가 3곳이니 하나를 지정해두고 두개를 돌리는 식으로 풀어보자 
    int n = nums.size();
    for(int i = 0; i< n-2; i++){
        
int l = i+1;
int r = n-1;        
        while(l<r){

       int temp = nums[i] + nums[l] + nums[r] ;
       if(temp > 0){
        r--;
       }
      else if(temp <0){
        l++;
       }
        else {
            result.push_back({nums[i],nums[l],nums[r]});
        l++;
        r--;
        
        }

        }

    }   

// duplicate이 되면 안됨. 
// 2차원 벡터에서 중복 안하게 만드는 법 
set<vector<int>>uniq(result.begin(),result.end());
vector<vector<int>> answer(uniq.begin(),uniq.end());    
return answer;
    }
};