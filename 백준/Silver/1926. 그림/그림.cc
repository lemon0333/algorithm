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
    int board[n][m];
    int num;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            cin>>num;
            board[i][j] = num;
        }
    }
  
    int max_sqaure=0;
    int square_count=0;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            square_count++;
            queue<pair<int,int>> Q;
            vis[i][j] =1;
            Q.push({i,j});
            int area=0;
            // while 한템포가 이어져있는 정사각형들임
            while(!Q.empty()){
                area++;
                pair<int,int> cur = Q.front();
                Q.pop();
               
                
                for(int dir = 0; dir< 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny= cur.Y + dy[dir];
                    if(nx< 0 || nx >= n || ny <0 || ny >= m)continue; // 범위 밖에 나가버리거나
                    if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문했거나 봐야할 원소가 ㅏㅇ니라면 나가기
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
                
            }
            max_sqaure = max(max_sqaure, area);
        }
        
    }
    cout<<square_count<<endl;
    cout<<max_sqaure;
}


