
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
#define X first
#define Y second

int N, K, L;
int board[55][55];
bool occupied[55][55];

int dx[4] = {-1, 1, 0, 0};   // 상 하 좌 우
int dy[4] = { 0, 0,-1, 1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> L;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) cin >> board[i][j];

    vector<pair<int,int>> robot(K+1);
    for(int k=1;k<=K;k++) cin >> robot[k].X >> robot[k].Y;

    auto inb = [&](int x,int y){ return x>=1&&x<=N&&y>=1&&y<=N; };
// 테스트 반복 
    while(L--){
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) occupied[i][j]=false;
        for(int k=1;k<=K;k++) occupied[robot[k].X][robot[k].Y]=true;

        // ── 1. 이동: BFS로 가장 가까운 먼지 칸 (거리→행→열) ──
        for(int k=1;k<=K;k++){
            int sr=robot[k].X, sc=robot[k].Y;
            occupied[sr][sc]=false;                 // 자기 출발점은 통과 가능

            static int dist[55][55];
            for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) dist[i][j]=-1;
            queue<pair<int,int>> q; dist[sr][sc]=0; q.push({sr,sc});
            while(!q.empty()){
                auto [cx,cy]=q.front(); q.pop();
                for(int d=0;d<4;d++){
                    int nx=cx+dx[d], ny=cy+dy[d];
                    if(!inb(nx,ny)||dist[nx][ny]!=-1) continue;
                    if(board[nx][ny]==-1||occupied[nx][ny]) continue;  // 물건/청소기 막힘
                    dist[nx][ny]=dist[cx][cy]+1; q.push({nx,ny});
                }
            }
            int br=-1,bc=-1,bd=INT_MAX;
            for(int i=1;i<=N;i++) for(int j=1;j<=N;j++)
                if(board[i][j]>0 && dist[i][j]!=-1 && dist[i][j]<bd){
                    bd=dist[i][j]; br=i; bc=j;                          // 행→열 오름차순 순회 = 타이브레이크
                }
            if(br!=-1){ sr=br; sc=bc; }
            robot[k]={sr,sc};
            occupied[sr][sc]=true;
        }

        // ── 2. 청소: 4방향 중 청소량(min20) 최대, 동점 오른쪽>아래>왼쪽>위 ──
        for(int k=1;k<=K;k++){
            int r=robot[k].X, c=robot[k].Y;
            vector<pair<int,int>> cells[4];
            cells[0]={{r,c},{r-1,c},{r+1,c},{r,c+1}};  // 오른쪽 (왼쪽 이웃 제외)
            cells[1]={{r,c},{r+1,c},{r,c-1},{r,c+1}};  // 아래   (위 제외)
            cells[2]={{r,c},{r-1,c},{r+1,c},{r,c-1}};  // 왼쪽   (오른쪽 제외)
            cells[3]={{r,c},{r-1,c},{r,c-1},{r,c+1}};  // 위     (아래 제외)

            int sum[4]={0,0,0,0};
            for(int d=0;d<4;d++)
                for(auto [x,y]:cells[d])
                    if(inb(x,y)&&board[x][y]>0) sum[d]+=min(board[x][y],20);

            int best=0;
            for(int d=1;d<4;d++) if(sum[d]>sum[best]) best=d;  // 엄격한 > → 우선순위 유지

            for(auto [x,y]:cells[best])
                if(inb(x,y)&&board[x][y]>0) board[x][y]-=min(board[x][y],20);
        }

        // ── 3. 축적: 먼지>0 칸에 +5 ──
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++)
            if(board[i][j]>0) board[i][j]+=5;

        // ── 4. 확산: 깨끗한(0) 칸 = 이웃 먼지합/10 (동시, 스냅샷) ──
        static int snap[55][55];
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) snap[i][j]=board[i][j];
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
            if(snap[i][j]!=0) continue;
            int s=0;
            for(int d=0;d<4;d++){
                int nx=i+dx[d], ny=j+dy[d];
                if(inb(nx,ny)&&snap[nx][ny]>0) s+=snap[nx][ny];
            }
            board[i][j]=s/10;
        }

        // ── 5. 매 테스트마다 총 먼지량 출력 ──
        long long total=0;
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++)
            if(board[i][j]>0) total+=board[i][j];
        cout<<total<<'\n';
    }
    return 0;
}
