#include <iostream>
#include <vector>
using namespace std;

// 소수 체크를 위한 배열
vector<bool> isPrime(10000001, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 10000000; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 10000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// 소수 판별은 이 배열을 이용
bool primenumber(int num) {
    return isPrime[num];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    sieve(); // 소수 미리 계산

    if (N == 1) return 0;

    if (primenumber(N)) {
        cout << N;
        return 0;
    }

    vector<int> primelist;
    for (int i = 2; i <= 10000000; i++) {
        if (primenumber(i)) {
            primelist.push_back(i);
        }
    }

    vector<int> result;
    int idx = 0;

    while (N > 1 && idx < primelist.size()) {
        if (N % primelist[idx] == 0) {
            result.push_back(primelist[idx]);
            N /= primelist[idx];
        } else {
            idx++;
        }
    }

    if (N > 1) result.push_back(N); // 마지막 남은 소수 (10^7보다 클 경우)

    for (auto elem : result) {
        cout << elem << "\n";
    }

    return 0;
}
