#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> res(N);
    int left = 0, right = N - 1;

    // 1부터 N까지의 숫자를 배치한다고 가정
    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            // 홀수(1, 3, 5...)는 왼쪽부터 채움
            res[left++] = i;
        } else {
            // 짝수(2, 4, 6...)는 오른쪽부터 채움
            res[right--] = i;
        }
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        cout << res[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}