#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // k가 n이면 1 때문에 절대 불가능
    if (k == n) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = i;

    // gcd(i, A[i]) = 1이어야 하는 개수는 (n - k)개
    // 이 (n - k)개를 서로 엇갈리게 배치하여 gcd를 1로 만듦
    int shift_count = n - k;
    
    // 1부터 shift_count까지 숫자를 한 칸씩 밀어서 배치 (예: 2, 3, 1)
    for (int i = 1; i < shift_count; i++) {
        a[i] = i + 1;
    }
    a[shift_count] = 1;

    // 결과 출력
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}