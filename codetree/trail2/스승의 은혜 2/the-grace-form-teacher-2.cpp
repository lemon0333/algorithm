#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main() {
    // Please write your code here.
    
    int N;
    int B;
    int a;

    cin>>N>>B;
        vector<int> contain(N,0);
    for(int i = 0; i< N; i++){
cin>>a;
contain[i] =  a;

    }

sort(contain.begin(), contain.end());
int i = 0;
int present = 0;
int maxperson = 0;
while(1){
present += contain[i];

if(present <= B){
    maxperson++;
}

else if(present > B){
    break;
}
else if(maxperson == N){
    break;
}
i++;


}
if(( present - contain[i]/2  )<= B){
maxperson++;
}

cout<<maxperson;
    return 0;
}