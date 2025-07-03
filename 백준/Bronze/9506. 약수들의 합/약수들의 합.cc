#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>


using namespace std;
vector<int> divider(int n){
    vector<int> v;
    for(int i = 1; i<=n; i++){
        if(n%i == 0){
            if (std::find(v.begin(), v.end(), i) == v.end()) {
                v.push_back(i);
             
            }
        }
    }
    
    return v;
}
void perfect(int n){
    vector<int> v = divider(n);
    int k=0;
    for(auto elem :v ){
        k+= elem;
    }
    int size = v.size();
    k -= n;
    if(k == n ){
        cout<<n << " = ";
       
        for(int i = 0; i<size-2; i++){
            cout<< v[i] << " + ";
        }
        cout<<v[size-2]<<endl;
    }
    else{
        cout<< n<< " is NOT perfect."<<endl;
    }
}
int main(){
    int n;
    while(1){
        cin>>n;
        if(n== -1){
            return 0;
        }
        
        else{
            perfect(n);
        }
    }
    
}
