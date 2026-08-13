#include <string>
#include <vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

bool isPrime(int n){
    if(n<2) return false;
    for(int i =2; (long long) i * i <=n; i++)
        if(n % i == 0) return false;
    return true;
    
}

int solution(string numbers) {
    int answer = 0;
   set<int> made;
    queue<pair<string, string>> cq;
   
    for(int i = 0; i< (int) numbers.size(); i++){
        string s = numbers;
        s.erase(i,1); // i번째 글자 하나빼기 
        cq.push({string(1,numbers[i]), s});
    }
    while(!cq.empty()){
        auto [cur, rest] = cq.front(); cq.pop();
        made.insert(stoi(cur));
        for(int i = 0; i< (int)rest.size(); i++){
            string n = rest;
            n.erase(i,1);// 방금쓴글자 제거 
            cq.push({cur + rest[i], n});
            
        }
        
        
    }
    for(auto x : made)
        if(isPrime(x)) answer++;
    
    
    return answer;
}