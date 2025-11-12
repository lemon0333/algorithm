#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cmath>
#include<unordered_map>
#include<stack>
#include<set>
using namespace std;



int main() {
   ios::sync_with_stdio(0);cin.tie(0);
  

    string s;
    cin>>s;
    for(char count = 'a' ; count <='z'; count++){
        int cnt =0;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == count) cnt++;
            
        }
        cout<<cnt<<" ";
    }
}
