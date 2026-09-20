class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int r = 0;
        for(int j = 0; j< t.size(); j++){
            if(t[j] == s[i]){
                i++;
                r++;
            }
        }
        if(r == s.size()) return true;
        else return false;
    }
};