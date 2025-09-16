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


void rotate(int cmd, vector<vector<int>> &board, int &n, int &m){
    
    if(cmd == 1){
        reverse(board.begin(), board.end());
        
    }
    else if(cmd == 2){
        for (auto& row : board) {
             reverse(row.begin(), row.end());
         }
    }
    
    else if(cmd == 3){
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                result[j][n - 1 - i] = board [i][j];
        swap(n, m);
        
        board = result;
    }
    else if(cmd == 4){
        vector<vector<int>> result(m, vector<int>(n));
          for (int i = 0; i < n; ++i)
              for (int j = 0; j < m; ++j)
                  result[m - 1 - j][i] = board[i][j];
        swap(n, m);
        board = result;
    }
    else if(cmd == 5){
        int hn = n / 2, hm = m / 2;
        vector<vector<int>> res = board;
        // 1 → 2
           for (int i = 0; i < hn; ++i)
               for (int j = 0; j < hm; ++j)
                   res[i][j + hm] = board[i][j];
           
           // 2 → 3
           for (int i = 0; i < hn; ++i)
               for (int j = hm; j < m; ++j)
                   res[i + hn][j] = board[i][j];
           
           // 3 → 4
           for (int i = hn; i < n; ++i)
               for (int j = hm; j < m; ++j)
                   res[i][j - hm] = board[i][j];
           
           // 4 → 1
           for (int i = hn; i < n; ++i)
               for (int j = 0; j < hm; ++j)
                   res[i - hn][j] = board[i][j];
           
        board = res;
    }
    else if(cmd == 6){
        int hn = n / 2, hm = m / 2;

            vector<vector<int>> res = board;

            // 1 → 4
            for (int i = 0; i < hn; ++i)
                for (int j = 0; j < hm; ++j)
                    res[i + hn][j] = board[i][j];

            // 4 → 3
            for (int i = hn; i < n; ++i)
                for (int j = 0; j < hm; ++j)
                    res[i][j + hm] = board[i][j];
            
            // 3 → 2
            for (int i = hn; i < n; ++i)
                for (int j = hm; j < m; ++j)
                    res[i - hn][j] = board[i][j];
            
            // 2 → 1
            for (int i = 0; i < hn; ++i)
                for (int j = hm; j < m; ++j)
                    res[i][j - hm] = board[i][j];
        board = res;

    }
    
    
}
long long combi(int n, int k) {
    if (k < 0 || k > n) return 0;
    // 대칭성 이용: k > n-k 쪽이 반복이 더 적으므로
    if (k > n - k)
        k = n - k;

    long long ans = 1;
    // i = 1..k 에 대해 ans *= (n-k+i), ans /= i
    for (int i = 1; i <= k; ++i) {
        ans = ans * (n - k + i) / i;
    }
    return ans;
}
long long int HH(int n , int m){
    return  combi(n+m-1,m-1) % 1000000000;
    
}
void dfs(int start, string current, int L, string s ){
    
    if(!current.empty()){
        cout<<current<<"\n";
    }
    for(int i = start; i< L; i++){
        dfs(i+1, current+ s[i],L,s);
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int N;
    cin>>N;
    if(N==0){
        cout<<0;
        return 0;
    }
    vector<int> result;
    int elem;
    for(int i = 0; i< N; i++){
        cin>>elem;
        result.push_back(elem);
    }
    sort(result.begin(),result.end());
    double mi = N * 0.15;
    int di = round(mi);
    int r =0;
    int person=0;
    for(int i = di ; i < N - di; i++){
        person++;
        r+= result[i];
    }
    if(person == 0){
        cout<<0;
        return 0;
    }
    cout<<llround((long double)r / person);
    
    
  }
