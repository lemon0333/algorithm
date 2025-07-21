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

long long int mul(int A,int B, int C){
    if(B == 0) return 1;
    
    long long half = mul(A,B/2,C);
    long long result = (half*half) %C;
    if(B%2 != 0 ){
        result = (result * A) %C;
    }
    return result;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> result;
    deque<int> contain;
    int N;
    cin>> N;
    string cmd;
    for(int i = 0; i< N; i++){
        cin>>cmd;
        if(cmd == "push_back"){
            int a;
            cin>>a;
            contain.push_back(a);
        }
        else if(cmd == "push_front"){
           
                int a;
                cin>>a;
                contain.push_front(a);
          
        }
        else if(cmd == "pop_front"){
            if(!contain.empty()){
               
                int b= contain.front();
                result.push_back(b);
                contain.pop_front();
                                }
            else{
                result.push_back(-1);
            }
        }
        else if(cmd == "pop_back"){
            if(!contain.empty()){
               
                int b= contain.back();
                result.push_back(b);
                contain.pop_back();
                                }
            else{
                result.push_back(-1);
            }
        }
        else if(cmd == "size"){
            result.push_back(contain.size());
        }
        else if(cmd == "empty"){
            if(contain.empty()){
                result.push_back(1);
            }
            else{
                result.push_back(0);
            }
        }
        else if(cmd == "front"){
            if(!contain.empty()){
                result.push_back(contain.front());
            }
            else {
                    result.push_back(-1);  // ← 비어 있으면 -1 출력
                }
        }
        else if(cmd == "back"){
            if(!contain.empty()){
                result.push_back(contain.back());
            }
            else {
                    result.push_back(-1);  // ← 비어 있으면 -1 출력
                }
        }
    }
    
    for(auto elem: result){
        cout<<elem<<endl;
    }
    
}
