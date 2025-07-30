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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
  
    int h,w;
    cin>>h>>w;
    vector<int> height(w);
    for (int i = 0; i < w; ++i) {
          cin >> height[i];
      }
    vector<int> left_max(w), right_max(w);

    left_max[0] = height[0];
    for(int i = 1; i<w; i++){
        left_max[i] = max(left_max[i-1], height[i]);
    }
    right_max[w-1] = height[w-1];
    for(int i = w-2; i>=0; i--){
        right_max[i] = max(right_max[i+1], height[i]);
        
    }
    int result = 0;
    for(int i = 1; i< w-1; i++){
        int h = min(left_max[i], right_max[i]);
        if(h > height[i]){
            result += h - height[i];
        }
    }
    cout<<result;
    
}

