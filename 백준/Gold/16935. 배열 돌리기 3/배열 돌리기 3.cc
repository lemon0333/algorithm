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
    
    
}int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, r, num;
    cin >> n >> m >> r;

    vector<vector<int>> board(n, vector<int>(m));

    // 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    // 회전 연산
    for (int i = 0; i < r; i++) {
        cin >> num;
        rotate(num, board, n, m);  // rotate 함수에서 n, m 바뀔 수 있음
    }

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
