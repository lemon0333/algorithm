#include <iostream>
#include<utility>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string a;

int main() {
    cin >> a;
int k = 0;
for(int i = 0; i< a.size(); i++){
if(a[i] != '1'){
    a[i] = '1';
    k++;
    break;

}


}
if(k == 0){
    a[a.size()-1] = '0';
}
long long int r = 0;
long long int mul = 1;
for(int i = a.size()-1; i >=0; i--){
r += mul* (a[i] - '0');
mul *=2;
}

cout<<r;

    // Please write your code here.

    return 0;
}