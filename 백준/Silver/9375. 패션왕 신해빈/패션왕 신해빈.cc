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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

 
    int T;
    cin>> T;
    string clo;
    vector<int> result;
    string type;
    vector<string> contain;
    for(int i = 0; i< T; i++){
        contain.clear();
        int N;
        cin>> N;
        for(int i = 0; i< N; i++){
            cin>>clo>>type;
            contain.push_back(type);
          
            
        }
        result.push_back( makeresult(contain,N));
    }
    for(auto elem : result){
        cout<<elem<<"\n";
    }
    
}
