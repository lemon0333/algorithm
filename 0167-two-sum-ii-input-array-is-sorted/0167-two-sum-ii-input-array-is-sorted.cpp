class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;
        while(1)
        {
            int temp = numbers[start] + numbers[end];
            if(temp > target)
                end--;
            else if(temp < target)
                start++;
            else if(temp == target)
                break;    
        }
        vector<int> result;
        result.push_back(++start);
        result.push_back(++end);
        return result;
    }
};