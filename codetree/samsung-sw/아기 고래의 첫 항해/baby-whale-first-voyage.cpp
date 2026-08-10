#include <iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
#define X first 
#define Y second 
  int N;
  int board[55][55];
  bool vis[55][55];

  // 방향: 1상 2하 3좌 4우
  int dr[5]  = {0,-1, 1, 0, 0};
  int dc[5]  = {0, 0, 0,-1, 1};
  int ccw[5] = {0, 3, 4, 2, 1};   // 좌회전(반시계): 상→좌 하→우 좌→하 우→상
  int cw [5] = {0, 4, 3, 1, 2};   // 우회전(시계):   상→우 하→좌 좌→상 우→하
  int opp[5] = {0, 2, 1, 4, 3};   // 180도

  bool inb(int r, int c){ return r >= 1 && r <= N && c >= 1 && c <= N; }

int main() {
   
   int r;
   int c;
   int d;

   cin>> N>>r>>c>>d;
int total=0;
 // 보드 초기화
   for(int i = 1; i<= N; i++){
for(int j = 1; j<= N; j++){
    int num;
    cin>> num;
    board[i][j] = num;
    if(num == 0)
        total ++;
}

   } 
    // 정답 넣을 탭
   vector<pair<int,int>> ans ;
   vis[r][c] = 1;
   ans.push_back({r,c});
    int cnt = 1;

while(cnt < total) {

while(1){
        int order[4] = {d,ccw[d], cw[d], opp[d]};
        bool moved = false;
        for(int t = 0; t<4; t++){
            int nd = order[t];
            int nr = r + dr[nd], nc =  c+ dc[nd];
            if(inb(nr,nc) && board[nr][nc] == 0 && !vis[nr][nc]){
                r = nr;
                c = nc;
                d = nd;
                vis[r][c] = 1;
                ans.push_back({r, c});
                cnt++;
                moved = true;
                break;

            }

        }
    if(!moved) break;

}
if(cnt>=total) break;

static int dist[55][55];
for(int i = 1; i<=N; i++){
    for(int j = 1; j<=N; j++){
        dist[i][j] = -1;
    }
}


queue<pair<int,int>> Q;
dist[r][c] = 0;
Q.push({r,c});
while(!Q.empty()){
pair<int,int> cur = Q.front();
Q.pop();
for(int k = 1; k<=4; k++){
    int nx = cur.X + dr[k];
   int ny = cur.Y + dc[k];
    if(!inb(nx,ny) || board[nx][ny] != 0 || dist[nx][ny] != -1) continue;
    dist[nx][ny] = dist[cur.X][cur.Y] +1;
    Q.push({nx,ny});
}

}

int tr = -1, tc= -1, best = INT_MAX;
for(int i = 1; i<=N; i++){
    for(int j = 1; j<= N; j++ ){
if(board[i][j] == 0 && !vis[i][j] && dist[i][j] != -1 && dist[i][j] < best){
    best = dist[i][j]; tr= i; tc = j;
}

    }
}
static int td[55][55];
for(int i = 1; i<= N; i++){
    for(int j = 1; j<=N ; j++)
    td [i][j] = -1;
}

queue <pair<int,int>> Q2;
td[tr][tc] = 0;
Q2.push({tr,tc});
while(!Q2.empty()){
pair<int,int> cur = Q2.front();
Q2.pop();
for(int k = 1; k<=4; k++){

int nx = cur.X + dr[k];
int ny = cur.Y + dc[k];
if(!inb (nx,ny) || board[nx][ny] != 0 || td[nx][ny] != -1) continue;
td[nx][ny] = td[cur.X][cur.Y] +1;
Q2.push({nx,ny});
}

}

int pri[4] = {3,2,4,1};
while(!(r== tr && c == tc)){
    for(int t = 0; t< 4; t++){
int nd = pri[t];
int nr = r+ dr[nd];
int nc = c + dc[nd];
if(inb(nr,nc) && board[nr][nc] == 0 && td[nr][nc] == td[r][c] -1){
r = nr;
c = nc;
d = nd;
break;


}

    }
}

vis[r][c] = 1;
ans.push_back({r,c});
cnt++;
}

for(auto & p : ans){
cout<<p.X<<" " <<p.Y<<endl;
}
}