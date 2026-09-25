class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // 많은것중에 몇등까지 뽑기 이런거임 
        // 많은거 순서를 정하고 그거를 넣는 식으로 해야함 
        unordered_map<int,int> contain;
        for(int i = 0; i< nums.size(); i++){
            contain[nums[i]] ++;
        }
        vector<pair<int,int>> vcontain (contain.begin(),contain.end());

       sort(vcontain.begin(), vcontain.end(), [](auto& a, auto& b){
        if (a.second != b.second) return a.second > b.second; 
        return a.first < b.first;                              
        });
        vector<int> result;
        int i = 0;
        while(k--){
            result.push_back(vcontain[i].first);
            i++;
        }
        return result;
    }
};