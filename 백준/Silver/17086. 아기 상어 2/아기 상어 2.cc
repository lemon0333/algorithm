#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 8방향 설정 (상, 하, 좌, 우, 대각선 4방향)
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
int board[51][51];
int dist[51][51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            dist[i][j] = -1; // 미방문 상태 초기화
            
            if (board[i][j] == 1) {
                q.push({i, j}); // 상어 위치를 모두 큐에 삽입
                dist[i][j] = 0; // 상어가 있는 곳의 거리는 0
            }
        }
    }

    int max_safe_dist = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나거나 이미 방문한 경우 제외
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            max_safe_dist = max(max_safe_dist, dist[nx][ny]);
            q.push({nx, ny});
        }
    }

    cout << max_safe_dist;

    return 0;
}