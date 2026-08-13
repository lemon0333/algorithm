#include <string>
#include <vector>
#include<cmath>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxw = 0;
    int maxh = 0;
    for(int i = 0; i< sizes.size() ; i++){
        int a = sizes[i][0];
        int b= sizes[i][1];
        
        if(a>b) continue;
        
        if (b> a) {
            
            sizes[i][0] = b;
            sizes[i][1] = a;
            
        }
        
    }
    
    for(int i = 0; i< sizes.size() ; i++){
        maxh = max(maxh, sizes[i][0]);
        maxw = max(maxw,sizes[i][1]);
        
    }
    return maxh * maxw;
    
}