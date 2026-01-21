#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

   
    vector<bool> L(N, false);
    L[0] = true;
    for (int i = 1; i < N; i++) {
        if (a[i] >= a[i - 1]) L[i] = L[i - 1];
        else break; // 한번 깨지면 그 뒤는 볼 필요 없음
    }

   
    vector<bool> R(N, false);
    R[N - 1] = true;
    for (int i = N - 2; i >= 0; i--) {
        if (a[i] <= a[i + 1]) R[i] = R[i + 1];
        else break;
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
       
        if (i == 0) {
            if (R[1]) count++;
        }
        else if (i == N - 1) {
         
            if (L[N - 2]) count++;
        }
        else {
            
            if (L[i - 1] && R[i + 1] && a[i - 1] <= a[i + 1]) {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}