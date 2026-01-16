#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include<string>
#include <queue> // queue 헤더 추가
#include <cstdlib>  // llabs

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
bool isSubsequence(const string& s, const string& t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == s.size();
}
bool circularSubsequence(const string& s, const string& t) {
    int n = s.size();
    for (int start = 0; start < n; start++) {
        string rotated = s.substr(start) + s.substr(0, start);
        if (isSubsequence(rotated, t)) {
            return true;
        }
    }
    return false;
}

bool felindrome(int s, int e, vector<int> & contain){
    s--;
    e--;
    vector<int> right ;
    for(int i = s; i<= e; i++){
        right.push_back(contain[i]);
    }
    vector<int> left;
    for(int i = e; i>=s; i--){
        left.push_back(contain[i]);
    }
    for(int i = 0; i< e-s+1; i++){
        if(left[i] != right[i]){
            return false;
        }
    }
    return true;
}
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>> N;
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) {
         cin >> a[i];
     }
    static bool dp[2001][2001];

    // 길이 1
    for (int i = 1; i <= N; i++) {
        dp[i][i] = true;
    }

    // 길이 2
    for (int i = 1; i < N; i++) {
        if (a[i] == a[i+1]) dp[i][i+1] = true;
    }
    
    // 길이 3 이상
    for (int len = 3; len <= N; len++) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;
            if (a[i] == a[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
            }
        }
    }
    // 미리 dp로 구해놓고 답 구하기
    int M;
     cin >> M;
     while (M--) {
         int s, e;
         cin >> s >> e;
         cout << dp[s][e] << "\n";
     }
}
