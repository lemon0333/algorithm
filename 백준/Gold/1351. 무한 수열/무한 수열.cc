#include <iostream>
#include <map>

using namespace std;

// N이 1조까지이므로 long long 필수
typedef long long ll;

map<ll, ll> memo;
ll N, P, Q;

ll solve(ll n) {
    // 기저 사례: A0 = 1
    if (n == 0) return 1;
    
    // 이미 계산한 적이 있다면 그 값을 반환 (Memoization)
    if (memo.count(n)) return memo[n];
    
    // 점화식: An = A[n/P] + A[n/Q]
    // 재귀적으로 호출하며 결과 저장
    return memo[n] = solve(n / P) + solve(n / Q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> P >> Q)) return 0;

    // 점화식 계산 시작
    cout << solve(N) << "\n";

    return 0;
}