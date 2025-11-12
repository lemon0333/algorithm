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
    
    
    int a,b,c;
    cin>>a>>b>>c;
    int mul = a*b*c;
    int rows=10;
    int* arr = new int[rows];
    for(int i = 0; i< 10;i++){
        arr[i]=0;
    }
    string str = to_string(mul);
    
    for(auto s : str){
        
        int num = s - '0';
        arr[num]++;
    }
    
    for(int i = 0; i< 10; i++){
        cout<<arr[i]<<endl;
    }
    
}
