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
int white;
string result;
int black;
void compress(int x, int y, int n, const vector<vector<int>>& A) {
    int v = A[x][y];
    bool same = true;
    // 이 영역이 전부 같은 값(v)인지 검사
    for (int i = x; i < x + n && same; i++) {
        for (int j = y; j < y + n; j++) {
            if (A[i][j] != v) {
                same = false;
                break;
            }
        }
    }

    if (same) {
        // 전부 0 이면 '0', 전부 1 이면 '1'
        cout << v;
    } else {
        cout << '(';
        int h = n / 2;
        compress(x,     y,     h, A);  // 1) 왼쪽 위
        compress(x,     y + h, h, A);  // 2) 오른쪽 위
        compress(x + h, y,     h, A);  // 3) 왼쪽 아래
        compress(x + h, y + h, h, A);  // 4) 오른쪽 아래
        cout << ')';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    
    int N;
    string s;
    cin>> N;
    vector<vector<int>> contain(N, vector<int>(N,0));
    for(int i = 0; i< N; i++){
        cin>>s;
        for(int j = 0; j< N; j++){
            char c = s[j];
            int cc = int(c);
            contain[i][j] = cc - '0';
        }
    }
    compress(0,0,N,contain);
    
}
