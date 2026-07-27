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
int dist[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int solution(vector<vector<int> > maps)
{
    
     ios::sync_with_stdio(0);cin.tie(0);
     int answer = 1000000;
     n = maps.size();
    m = maps[0].size();
    bool endpoint = false;
   
         
           
            queue<pair<int,int>> Q;
            // 방문했다고 하고 넣어버림
            dist[0][0] = 1;
             Q.push({0,0});
            while(!Q.empty()){
                pair<int,int> cur = Q.front();
                   Q.pop();
                 for(int dir = 0; dir< 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny= cur.Y + dy[dir];
                    if(nx< 0 || nx >= n || ny <0 || ny >= m)continue; // 범위밖 
                    if(dist[nx][ny] !=0 || maps[nx][ny] != 1) continue; // 이미 방문
                    dist[nx][ny] = dist[cur.X][cur.Y] +1;
                 
               
                    Q.push({nx,ny});
                 
                }
            }
       
            
      
            
        
        
        
    
  if(dist[n-1][m-1] != 0){
      return dist[n-1][m-1];
  }
else {
    return -1;
}



}

    
      

