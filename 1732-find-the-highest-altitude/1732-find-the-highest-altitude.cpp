class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0;
        vector<int> loc (gain.size()+1,0);
        loc[0] = 0;
        for(int i = 0; i< gain.size(); i++){
            cur  += gain[i];
            loc[i+1] = cur;
        }
        sort(loc.begin(),loc.end());
        return loc[gain.size()];
    }
};