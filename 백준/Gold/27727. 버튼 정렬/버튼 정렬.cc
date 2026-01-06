#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// Java의 Node 클래스 역할을 하는 구조체
struct Node {
    int ind;
    ll num;

    // Java의 compareTo와 동일한 정렬 기준
    bool operator<(const Node& o) const {
        if (this->num != o.num) {
            return this->num < o.num;
        }
        return this->ind < o.ind;
    }
};

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Node> A(N);
    for (int i = 0; i < N; i++) {
        A[i].ind = i;
        cin >> A[i].num;
    }

    // Node 정렬
    sort(A.begin(), A.end());

    ll K;
    cin >> K;

    // N이 1인 경우 예외 처리
    if (N == 1) {
        cout << K << "\n";
        return 0;
    }

    ll curK = 0;
    ll asc = 0;
    int startInd = 1;

    // 정렬된 상태에서 인덱스가 어긋난 마지막 지점 찾기
    for (int i = N - 1; i >= 1; i--) {
        if (A[i].ind != i) {
            startInd = i;
            break;
        }
    }

    // startInd까지 모든 값을 A[startInd].num으로 맞추는 비용 계산
    for (int i = 0; i < startInd; i++) {
        curK += (A[startInd].num - A[i].num);
        // 중간에 K를 초과하면 즉시 종료
        if (curK > K) {
            cout << asc << "\n";
            return 0;
        }
    }

    // 평준화가 한 번이라도 일어났다면 정렬 1회 추가
    if (curK > 0) {
        asc += 1;
    }

    int nextInd = startInd + 1;
    while (nextInd < N) {
        if (A[nextInd - 1].num != A[nextInd].num) {
            // 현재까지 쌓인 원소들(nextInd개)을 다음 높이까지 올리는 비용
            ll cnt = (ll)nextInd * (A[nextInd].num - A[nextInd - 1].num);
            if (curK + cnt > K) {
                break;
            }
            curK += cnt;
            asc += (A[nextInd].num - A[nextInd - 1].num);
        }
        nextInd++;
    }

    // 남은 K만큼 전체 층을 올리며 정렬 횟수 추가
    asc += (K - curK) / (ll)nextInd;

    cout << asc << "\n";

    return 0;
}