#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 64-bit로 선언
    vector<unsigned long long> pN(N+1);
    if (N >= 1) pN[1] = 1;
    if (N >= 2) pN[2] = 1;
    for (int i = 3; i <= N; ++i) {
        pN[i] = pN[i-1] + pN[i-2];
    }

    cout << pN[N] << "\n";
    return 0;
}
