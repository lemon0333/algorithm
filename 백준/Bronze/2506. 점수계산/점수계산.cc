#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    long long r = 0;   // 총 점수 (streak 누적)
    int more = 0;      // 현재 연속된 1의 길이

    for (int i = 0; i < n; ++i) {
        int elem; 
        cin >> elem;
        if (elem == 1) {
            ++more;        // 연속 증가
            r += more;     // 그 길이만큼 점수 추가
        } else {
            more = 0;      // 끊기면 0으로 리셋
        }
    }
    cout << r << '\n';
    return 0;
}
