#include <iostream>
#include<climits>
#include<cmath>
using namespace std;

int n;
int a[1003];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Please write your code here.
// 1번방부터 N번방까지 들어가는거에 대해서 어떻게 시작할지 보기 
int minR = INT_MAX;
for(int i = 0; i< n; i++){
int c = i;
int d = 0;
int k = 0;
for(int j = 0; j< n; j++){
k += d * a[c];
c++;
d++;
c = c % n;

}
minR = min(k, minR);

}
cout<<minR;
    return 0;
}