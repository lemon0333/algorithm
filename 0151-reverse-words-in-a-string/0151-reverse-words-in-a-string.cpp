class Solution {
public:
    string reverseWords(string s) {
        vector<string> contain;
        string result;
        string temp;
        for(int i = 0; i<s.size(); i++){
            if(s[i] != ' '){
                temp+=s[i];
            }
            if(s[i] == ' ' ){
               if(!temp.empty()) contain.push_back(temp);
                temp.clear();
            }
            if(i == s.size()-1){
               if(!temp.empty()) contain.push_back(temp);
                   temp.clear();
            }
        }
        for(int i = 0; i< contain.size()-1; i++){
            cout<<contain[i];
        }
// 단어별로 넣기 단어를 역으로 결과 string에 넣기 
for(int i = contain.size()-1; i>=0 ; i--){
result += contain[i];
if(i == 0){
    break;
}
result += " ";
}
return result;
    }
};