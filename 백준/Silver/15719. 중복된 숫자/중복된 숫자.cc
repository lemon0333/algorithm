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

   
    vector<int> result;
    int num;
    int N;
    cin>> N;
    for(int i = 0; i< N; i++){
        cin>>num;
        result.push_back(num);
    }
    int m = 0;
    sort(result.begin(),result.end());
    for(int i = 0; i< N-1; i++){
        int a = result[i];
        if(a == result[i+1]){
            m = a;
        }
    }
    cout<<m;
    
    
}
