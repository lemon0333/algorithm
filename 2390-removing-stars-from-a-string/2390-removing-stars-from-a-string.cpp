class Solution {
public:
    string removeStars(string s) {
        // star는 앞에 있는거 뺌 일단 큐 혹은 스택 생각해보기 
        stack <char> contain;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] == '*'){
                contain.pop();
            }
            else
            contain.push(s[i]);
        }
        string result;
        int k = contain.size();
        for(int i = 0; i< k; i++){
            result += contain.top();
            contain.pop();
        }
        string resultt;
        for(int i = 0; i< result.size(); i++){
            resultt += result[result.size()-i-1];
        }
        return resultt;
    }
};