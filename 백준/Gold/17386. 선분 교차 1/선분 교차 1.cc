#include <iostream>
using namespace std;

typedef long long ll;

// 좌표를 ll로 받아야 계산 시 자동 형변환이 일어납니다.
int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    // (x1y2 + x2y3 + x3y1) - (y1x2 + y2x3 + y3x1)
    ll val = (a.first * b.second + b.first * c.second + c.first * a.second) -
             (a.second * b.first + b.second * c.first + c.second * a.first);

    if (val > 0) return 1;   // 반시계
    if (val < 0) return -1;  // 시계
    return 0;                // 일직선
}

int main() {
    pair<ll, ll> p1, p2, p3, p4;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;

    // 두 선분이 교차하려면 각 선분을 기준으로 다른 선분의 두 점 CCW 곱이 음수여야 함
    int res1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int res2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (res1 < 0 && res2 < 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}