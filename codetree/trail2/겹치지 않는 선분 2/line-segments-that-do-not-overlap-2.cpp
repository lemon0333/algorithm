#include <iostream>
using namespace std;
#include<vector>

int main() {
    // Please write your code here.
    int result = 0;
    int N;
    cin>> N;
    int a, b;

   vector<int> containa(N,0);
   vector<int> containb(N,0);
    for(int i = 0; i< N; i++){
cin>>a>>b;

containa[i] = a;
containb[i] = b;

    }
vector<bool> checked (N,true);
for(int i = 0; i< N-1; i++){
    for(int j = i+1; j< N; j++){
if(containa[i] < containa[j] && containb[i] > containb[j]){
    checked [i] = false;
    checked [j] = false; 
}
if(containa[i] > containa[j] && containb[i] < containb[j]){
    checked[i] = false;
    checked[j] = false;
}

    }
}


  for(int i = 0; i< N; i++){
    if (checked[i] == true){
        result++;
    }
  }
  cout<<result;
    return 0;
}