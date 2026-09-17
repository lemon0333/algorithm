class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 이건 이런식으로 102 와 210을 비교하고 210이 크니까 210을 채택하는 방식 
        vector<string> contain;
        for(int i = 0;i< nums.size() ; i++) contain.push_back(to_string(nums[i]));
        bool bo=true;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != 0) bo = false;
        }
        if (bo) return "0";
        sort(contain.begin(), contain.end(), [](const string &a, const string & b)
        {
return a+ b> b+a;

        }
        
        );
    


    string result = "";
    for (auto & elem : contain){
    result += elem;
    }
    return result;
    }
};