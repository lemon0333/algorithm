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
#define X first
#define Y second

bool vis[502][502];
int n ;
int m ;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


long long int result;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin>> n>>m;
    char board[n][m];
    char c;
    string s;
    for(int i = 0; i< n; i++){
        cin>>s;
        for(int j = 0; j< m; j++){
            board[i][j] = s[j];
        }
    }
    
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;
    int fire_board[n][m];
    int per_board[n][m];
  
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            fire_board[i][j] = -1;
            per_board[i][j] =-1;
        }
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            
            if(board[i][j] == 'F'){
                Q1.push({i,j});
                fire_board[i][j] =0;}
            
            if(board[i][j] == 'J'){
                Q2.push({i,j});
                per_board[i][j] =0;} // 시작점 잡아주기
        }
    }
    
    // while 한템포가 이어져있는 정사각형들임
    while(!Q1.empty()){
        
        pair<int,int> cur = Q1.front();
        Q1.pop();
       
        
        for(int dir = 0; dir< 4; dir++){
            int nx = cur.X + dx[dir];
            int ny= cur.Y + dy[dir];
            if(nx< 0 || nx >= n || ny <0 || ny >= m)continue; // 범위 밖에 나가버리거나
            if(fire_board[nx][ny]>=0 || board[nx][ny] == '#') continue; // 이미 방문했거나 봐야할 원소가 ㅏㅇ니라면 나가기
            fire_board[nx][ny] = fire_board[cur.X][cur.Y]+1; // 불이 한칸 이동
            Q1.push({nx,ny});
        }
        
    }
    
// 지훈이에 대한 bfs 하기
// while 한템포가 이어져있는 정사각형들임
while(!Q2.empty()){
    
    pair<int,int> cur = Q2.front();
    Q2.pop();
   
    
    for(int dir = 0; dir< 4; dir++){
        int nx = cur.X + dx[dir];
        int ny= cur.Y + dy[dir];
        if(nx< 0 || nx >= n || ny <0 || ny >= m){
            cout<<per_board[cur.X][cur.Y] +1;
            return 0;
         
        } // 범위 밖에 나가버리거나 여기서 지훈이가 범위 밖으로 나가버리면 탈출했다는 의미
        // 불보다 먼저 도착했는지 아닌지를 확인하기
        if(fire_board[nx][ny] != -1 && fire_board[nx][ny] <= per_board[cur.X][cur.Y] +1 ) continue;
        if(per_board[nx][ny]>=0 || board[nx][ny] == '#') continue; // 이미 방문했거나 봐야할 원소가 ㅏㅇ니라면 나가기
        per_board[nx][ny] = per_board[cur.X][cur.Y]+1; // 사람도 한칸 이동
        Q2.push({nx,ny});
    }
    
}
    
    cout<<"IMPOSSIBLE";
  
}



