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


long long int result;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>> n;

    vector<long long int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];


    stack<int> st;

    for (int i = 0; i < n; i++) {
        
        while (!st.empty() && arr[st.top()] <=arr[i]) {
            st.pop();
        }
        //stack에 남아있는 개수 다 더하기 남아있는게 현재의 i보다 큰 것들 남아있으니까
        result+= st.size();
  
        st.push(i);
    }

    cout<<result;
}


