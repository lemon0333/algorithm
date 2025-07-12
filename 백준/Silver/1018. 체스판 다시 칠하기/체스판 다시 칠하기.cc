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


bool primenumber(int N){
    if(N==1) {
        return false;
    }
    for(int i = 2; i*i<= N; i++){
        if( N % i == 0){
            return false;
        }
    }
    return true;
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
  

    
    int N,M;
    cin>>N>>M;
    string s;
    vector<string> contain;
    for(int i = 0; i< N; i++){
        cin>>s;
        contain.push_back(s);
        
    }
    vector<vector<char>> chess(N,(vector<char>(M,-1)));
    for(int i = 0; i< N;i++){
        string str = contain[i];
        for(int j = 0; j< M; j++){
            chess[i][j] = str[j];
        }
    }
    // 시작이 검은색일 때
    vector<vector<int>> bcc(N, vector<int>(M,0));
    int blackresult= 0;
   
    for(int i = 0; i< N; i++){
        char cmp = (i % 2 == 0) ? 'B' : 'W';
        for(int j = 0; j< M; j++){
            if(chess[i][j] != cmp){
                blackresult++;
                bcc[i][j] = 1;
            }
         
            cmp = (cmp == 'B') ? 'W' : 'B';
            
        }
    }
    int whiteresult=0;
    vector<vector<int>> wcc(N, vector<int>(M,0));
    // 시작이 하얀색 일 때
   
    for(int i = 0; i< N; i++){
        char cmpw = (i % 2 == 0) ? 'W' : 'B';
        for(int j = 0; j< M; j++){
            if(chess[i][j] != cmpw){
                whiteresult++;
                wcc[i][j] = 1;
            }
            cmpw = (cmpw == 'B') ? 'W' : 'B';
            
            
        }
    }
    if(N == 8 && M == 8){
        cout<< min(blackresult,whiteresult);
        return 0;
    }
    int br = 0;
    vector<int> blackresultall;
    for(int k = 0;8<=N-k ; k++){
        for(int l = 0; 8<=M-l; l++ ){
            
            for(int i = k; i< k+8; i++){
                for(int j =l; j< l+8 ; j++){
                    if(bcc[i][j]== 1){
                        br++;
                    }
                }
            }
            blackresultall.push_back(br);
            br=0;
        }
    }
    int wr = 0;
    vector<int> whiteresultall;
    for(int k = 0;8<=N-k ; k++){
        for(int l = 0; 8<=M-l; l++ ){
         
            for(int i = k; i< k+8; i++){
                for(int j =l; j< l+8 ; j++){
                    if(wcc[i][j] == 1){
                        wr++;
                    }
                }
            }
            whiteresultall.push_back(wr);
            wr=0;
        }
    }
    sort(blackresultall.begin(), blackresultall.end());
    sort(whiteresultall.begin(),whiteresultall.end());
 
   cout<< min( whiteresultall[0] ,blackresultall[0]);
    
}
