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

bool is012(const std::string& s) {
    return !s.empty() &&
           std::all_of(s.begin(), s.end(), [](char c){
               return c=='0' || c=='1' || c=='2';
           });
}
long long modPow(long long a, long long e, long long mod) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}
tuple<long long,long long,long long> extGCD(long long a, long long b) {
    if (b==0) return {a, 1, 0};
    auto [g, x1, y1] = extGCD(b, a % b);
    // b*x1 + (a%b)*y1 = g
    // => b*x1 + (a - (a/b)*b)*y1 = g
    // => a*y1 + b*(x1 - (a/b)*y1) = g
    long long x = y1;
    long long y = x1 - (a/b) * y1;
    return {g, x, y};
}

// 일반 모듈러 m(합성수 포함)에서 a의 역원 구하기
// gcd(a,m) != 1 이면 -1 반환
long long modInv(long long a, long long m) {
    auto [g, x, y] = extGCD(a, m);
    if (g != 1) return -1;       // 역원이 존재하지 않음
    x %= m;
    if (x < 0) x += m;
    return x;
}
int makeresult(vector<string> contain, int N ){
    if (N == 0) return 0;
    // unordered map을 이용해 head가 몇개인지 pants가 몇개인지 이런식
    std::unordered_map<std::string,int> freq;
     for (auto &s : contain) {
         freq[s]++;  // 키가 없으면 0에서 시작해 ++
     }
    if(freq[contain[0]] == N){
        return N;
    }
    else{
        int r= 0;
        
        int mul =1;
        for (auto &p : freq) {
            mul *= (p.second+1);
        }
        r+= mul;
        return r-1;
        
    }
    
  
}
int divi_con(vector<int> contain){
    
    return 1;
}
int zerocount ;
int onecount;
int fibonacci(int n){
    if(n== 0){
        zerocount++;
        return 0;
    }
    else if (n == 1){
        onecount++;
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>> T;
    int num;
    vector<pair<int,int>> contain;
    for(int i = 0; i< T; i++){
        cin>>num;
        // 항상 초기화해주기
        zerocount =0;
        onecount=0;
  
        vector<int> dp(num+1,0);
        vector<pair<int,int>> dpc(num+1);
        if(num == 0){
            contain.push_back(make_pair(0,1));
        }
        else if (num == 1){
            contain.push_back(make_pair(1,0));
        }
        else{
            dp[0]=0;
            dp[1]=1;
            dpc[0] = {0,1};
            dpc[1] = {1,0};
            for(int i = 2; i<= num; i++){
                dp[i] = dp[i-1] + dp[i-2];
                dpc[i] = pair(dpc[i-1].first + dpc[i-2].first , dpc[i-1].second + dpc[i-2].second);
                
            }
            contain.push_back(dpc[num]);
        }
    }
    for( auto &p : contain){
        cout<< p.second<<" " << p.first<<"\n";
    }
    
}
