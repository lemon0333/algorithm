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
    int num;
    cin>>N;
    vector<int> contain(N,0);
    for(int i = 0; i< N; i++){
        cin>>num;
        contain[i] = num;
    }
    sort(contain.begin(),contain.end());
    long long min_sum = 2000000001;
    pair<long long,long long> answer;
    int left = 0;
    int right = N-1;
    int result = 0;
    while(left<right){
        int sum = contain[left] + contain[right];
        int cp = abs(sum);
        if(cp < min_sum){
           
            
            min_sum=cp;
            answer= {contain[left], contain[right]};
        }
        if(cp ==0){
            break;
        }
        if(sum<0){
            left++;
        }
        else{
            right--;
        }
        
    }
    cout<<answer.first<<" "<<answer.second;
}
