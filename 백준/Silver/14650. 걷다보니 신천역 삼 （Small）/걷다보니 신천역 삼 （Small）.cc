#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    if (N == 1) {
        cout << 0;
        return 0;
    }
    long long ans = 2;            // =2×3^0  (N=2일 때)
    for (int i = 0; i < N-2; i++)
        ans *= 3;                // 점점 3을 곱해서 3^(N-2) 만듦
    cout << ans;
    return 0;
}
