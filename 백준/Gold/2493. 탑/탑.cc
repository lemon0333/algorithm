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



int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> result(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        
        if (!st.empty()) result[i] = st.top() + 1;
        else result[i] = 0;

        st.push(i);
    }

    for (auto elem : result)
        cout << elem << " ";
}


