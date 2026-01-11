#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> // queue 헤더 추가

using namespace std;

// BFS를 이용한 최소 이동 횟수 구하기
int minsolve(int ladder_snake[]) {
    queue<int> Q;
    vector<int> dist(101, -1); // 방문 여부 및 거리 저장 (-1은 미방문)

    Q.push(1);       // 1번 칸에서 시작
    dist[1] = 0;     // 시작 지점의 이동 횟수는 0

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        // 100번 칸에 도착하면 즉시 반환
        if (cur == 100) return dist[100];

        for (int i = 1; i <= 6; i++) {
            int next = cur + i;

            if (next > 100) continue; // 보드 밖으로 나가는 경우 제외

            // 사다리나 뱀이 있다면 해당 위치로 이동
            if (ladder_snake[next] != 0) {
                next = ladder_snake[next];
            }

            // 아직 방문하지 않은 칸이라면 방문 처리
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                Q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    int h;
    vector<int> height(N,0);
    vector<int> width(N,0);
    for(int i = 0; i< N; i++){
        cin>>h;
        height[i]=h;
    }
    for(int i = 0; i< N; i++){
        cin>>h;
        width[i]=h;
    }
    vector<pair<int,int>>contain;
    for(int i = 0; i< N;i++){
        contain.push_back({height[i], width[i]});
        
    }
    sort(contain.begin(), contain.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first; // 첫 번째 인자 기준 내림차순
    });
   
    long long max_square = 0;
        long long total_width = 0;

        for (int i = 0; i < N; i++) {
            // 현재까지 나온(더 높은) 막대들의 너비를 모두 합침
            total_width += contain[i].second;

            // 현재 높이(지금까지 중 가장 낮은 높이) * 합쳐진 전체 너비
            // -> 앞의 큰 막대들을 현재 높이로 자른다고 가정하는 것
            long long current_area = (long long)contain[i].first * total_width;

            if (current_area > max_square) {
                max_square = current_area;
            }
        }

        cout << max_square << endl;
    
}
