#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cmath>
#include<unordered_map>
using namespace std;


int dp(vector<int> &contain,int N) {
    //find 벡터 처음에 초기화
    int currentlength=1;
    int maxLength=1;
    vector<int> sth (N+1,0);
    for(int i =1;i<N;i++){
        for(int j = 0; j< N; j++){
            if(contain[i] > contain[j]){
                sth[i] = max(sth[i], sth[j] + 1);
                
            }
            
        }
    }
    

    return *max_element(sth.begin(), sth.end());
}


char word(string s){
    int length = s.size();
    unordered_map<char, int> mainmap;
    // mainmap 초기화
    for(char c = 'A'; c <= 'Z'; c++){
        mainmap[c] = 0;
    }
    // 시작부터 끝까지 upper 클래스로 대문자로 만들어주기
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    
    for(int i = 0; i< s.size();i++){
        for(char c = 'A' ; c <= 'Z'; c++){
            if(s[i] == c){
                mainmap[c]++;
            }
        }
    }
    int max = 0;
    char result ;
    for(char c = 'A'; c<= 'Z'; c++){
        if(mainmap[c] > max){
            
            max = mainmap[c];
            result = c;
        }
    }
    int duplication = 0;
    for(char c = 'A'; c<= 'Z'; c++){
        if(mainmap[c] == max){
            duplication++;
            
        }
    }
    
    if(duplication >1){
        return '?';
    }
    
    return result;
        }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
  
    string s;
    cin>>s;
    
    
   cout<< word(s);
}
