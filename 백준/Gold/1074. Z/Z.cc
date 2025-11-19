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
#include<list>
using namespace std;
#define X first
#define Y second

bool vis[502][502];
int n ;
int m ;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int func(int n, int r, int c){
    if(n==0) return 0;
    int half = (1<<n) /2;
   if(r< half && c < half) return func(n-1,r,c);
    if(r< half && c >= half) return half*half+ func(n-1,r, c-half);
    if(r>= half && c < half) return  2* half*half + func(n-1, r-half,c);
    return 3*half*half + func(n-1,r-half,c-half);
    
}
long long int result;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    int r, c;
    cin>>r>>c;
    cout<<func(n,r,c);
}



