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
    
    int N;
    int num;
    cin>> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i< N* N ; i++){
        cin>> num;
        pq.push(num);
        if ((int)pq.size() > N) pq.pop();
    }
    cout<<pq.top();
}
