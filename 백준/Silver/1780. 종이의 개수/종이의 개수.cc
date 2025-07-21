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
int minuscount =0;
int pluscount =0;
int zerocount =0;
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
        // 전부 무언가라면
        if(v == -1){
            minuscount++;
        }
        else if(v == 1){
            pluscount++;
        }
        else{
            zerocount++;
        }
        
    } else {
     
        int h = n / 3;
        compress(x,y,h,A);
        compress(x+h, y, h , A);
        compress(x+2*h, y, h, A);
        compress(x, y+h, h, A);
        compress(x+h, y+h, h, A);
        compress(x+2*h, y+h, h, A);
        compress(x, y+ 2*h, h, A);
        compress(x+h, y+ 2*h, h, A);
        compress(x+2*h, y+2*h, h, A);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    
    int N;
    string s;
    cin>> N;
    int num;
    vector<vector<int>> contain(N,vector<int>(N,0));
    for(int i  = 0; i< N; i++){
        for(int j = 0; j< N; j++){
            cin>>num;
            contain[i][j] = num;
        }
    }
    compress(0,0,N,contain);
    cout<<minuscount<<endl;
    cout<<zerocount<<endl;
    cout<<pluscount<<endl;
    
}
