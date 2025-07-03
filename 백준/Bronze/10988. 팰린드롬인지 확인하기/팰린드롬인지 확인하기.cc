#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>


using namespace std;

int main(){
    
    string s;
    cin >> s;
    vector<char> v;
    int k;
    int n = s.size();
    if(s.size()%2 == 1){
         k = s.size()/2;
    }
    else{
         k = s.size()/2;
    }
    for (int i =0;i<k;i++){
        v.push_back(s[i]);
    }
    vector<char>vv;
  
    for(int i = s.size()- 1; i>=n-k;i--){
        vv.push_back(s[i]);
    }
    for(int i = 0; i<k;i++){
        if(v[i]!=vv[i]){
            cout<<0;
            exit(EXIT_SUCCESS);
            break;
        }
    }
    cout<<1;
    
    
}
