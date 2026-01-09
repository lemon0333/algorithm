#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x;
    cin >> N;
    vector<int> contain(N);
    for (int i = 0; i < N; i++) cin >> contain[i];
    cin >> x;

    // 1. 오름차순 정렬 (O(N log N))
    sort(contain.begin(), contain.end());

    int left = 0;          // 시작점
    int right = N - 1;     // 끝점
    int result = 0;

    // 2. 투 포인터 이동 (O(N))
    while (left < right) {
        int sum = contain[left] + contain[right];

        if (sum == x) {    // 합이 x와 같으면
            result++;
            left++;
            right--;
        } 
        else if (sum < x) { // 합이 작으면 왼쪽을 오른쪽으로 (더 큰 값을 찾아)
            left++;
        } 
        else {              // 합이 크면 오른쪽을 왼쪽으로 (더 작은 값을 찾아)
            right--;
        }
    }

    cout << result; // 중복 계산이 없으므로 /2 할 필요 없음
}