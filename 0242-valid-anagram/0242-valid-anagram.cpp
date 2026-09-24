class Solution {
public:
    bool isAnagram(string s, string t) {
        // anagram이라는것은 결국 문자열의 원소 개수가 똑같다는것 
        // 문자열의 원소개수라면 unordered_map을 써야한다는 것 
        unordered_map<char,int>  contain;
         unordered_map<char,int>  containn;
        for(char c : s){
            contain[c]++;
        }
        for(char c : t){
            containn[c]++;
        }
        if(contain == containn){
            return true;
        }
        return false;
    }
};