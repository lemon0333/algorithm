#include <iostream>
#include <vector>

using namespace std;

// 최대값 설정
const int MAX = 1000000;
const int MOD = 1000000009;

// 큰 배열은 전역 변수로 선언하여 스택 오버플로우 방지
long long dp[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 미리 100만까지의 모든 경우의 수를 계산 (Preprocessing)
    dp[1] = 1; // (1)
    dp[2] = 2; // (1+1, 2)
    dp[3] = 4; // (1+1+1, 1+2, 2+1, 3)

    for (int i = 4; i <= MAX; i++) {
        // 점화식: f(n) = f(n-1) + f(n-2) + f(n-3)
        // 자료형은 합칠 때 MOD를 넘을 수 있으므로 long long 권장
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }

    int T;
    cin >> T;

    while (T--) {
        int num;
        cin >> num;
        // 2. 이미 구해놓은 결과값만 바로 출력 (O(1))
        cout << dp[num] << "\n";
    }

    return 0;
}