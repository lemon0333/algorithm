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
    
    
    int number ;
    cin>>number;
    int rows=10;
    int* arr = new int[rows];
    for(int i = 0; i< 10;i++){
        arr[i]=0;
    }
    string str = to_string(number);
    
    for(auto s : str){
        
        int num = s - '0';
        if(num==9){
            arr[6]++;
        }
        else
        arr[num]++;
    }
    if(arr[6]%2== 0)
    arr[6] = arr[6]/2;
    else
        arr[6]= arr[6]/2 +1;
    int max = 0;
    for(int i = 0; i< 10; i++){
        
       
        if(arr[i] > max)
            max=arr[i];
        
    }
    cout<<max;
}
