#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cmath>

using namespace std;

int re(int a,int b,vector<int>&sum,vector<int> &vec){
    a--;
    b--;
    int result = sum[b] - sum[a] + vec[a];
    return result;
}
int main(){
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>> N;
    int M;
    cin>>M;
    vector<int> vec;
    int num;
    int a,b;
    vector<int> sum(N,0);
    for(int i = 0; i< N;i++){
        cin>>num;
        vec.push_back(num);
    }
    sum[0] = vec[0];
    for(int i = 1; i< N;i ++)
    {
        sum[i] = sum[i-1] + vec[i];
    }
    vector<int> result;
    for(int i = 0; i< M; i++){
        cin>>a>>b;
        result.push_back(re(a,b,sum,vec));
    }
    for(auto elem: result){
        cout<<elem<<"\n";
    }
    
}
