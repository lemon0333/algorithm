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

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int s;
    int p;
    cin>>s>>p;
    string str;
    cin>>str;
    int a,c,g,t;
    cin>>a>>c>>g>>t;
    int result=0;
    int acount=0;
    int ccount=0;
    int gcount=0;
    int tcount=0;
    for(int i = 0; i<p;i++){
        if(str[i]== 'A'){
            acount++;
        }
        if(str[i]== 'C'){
            ccount++;
        }
        if(str[i]== 'G'){
            gcount++;
        }
        if(str[i]== 'T'){
            tcount++;
        }
    }
    for(int i = 0; i<= s-p; i++){
     
        
        if(acount >= a && ccount >= c && gcount >= g && tcount >= t){
            result++;
        }
        
        if(str[i]== 'A'){
            acount--;
        }
        if(str[i]== 'C'){
            ccount--;
        }
        if(str[i]== 'G'){
            gcount--;
        }
        if(str[i]== 'T'){
            tcount--;
        }
        if(str[i+p]== 'A'){
            acount++;
        }
        if(str[i+p]== 'C'){
            ccount++;
        }
        if(str[i+p]== 'G'){
            gcount++;
        }
        if(str[i+p]== 'T'){
            tcount++;
        }
        
    }
      
    
    cout<<result;
}

