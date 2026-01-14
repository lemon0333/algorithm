#include <bits/stdc++.h>
using namespace std;

int sgn(long long x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long long dx = x2 - x1;
    long long dy = y2 - y1;
    long long D = llabs(dx) + llabs(dy);

    if (D % 2 != 0) {
        cout << -1;
        return 0;
    }

    long long half = D / 2;

    long long moveX = min(llabs(dx), half);
    long long moveY = half - moveX;

    long long px = x1 + sgn(dx) * moveX;
    long long py = y1 + sgn(dy) * moveY;

    cout << px << " " << py;
}
