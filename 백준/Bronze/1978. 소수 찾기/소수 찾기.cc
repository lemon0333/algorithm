#include <iostream>
#include <stack>
#include <string>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

bool primenumber(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2;i * i <= num;i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
long long int gcd(int m,int n) {
    if (n == 0) {
        return m;
   }
    else {
        return gcd(n, m % n);
    }


}

int bertrang(int n) {
    int result = 0;
    for (int i = n + 1; i <= 2 * n;i++) {
        if (primenumber(i))
            result++;
    }
        return result;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    long long int M, N;
    vector<int> contain;
    cin >> N;
    int num;
    int num2;
    int r = 0;
    for (int i = 0;i < N;i++) {
        cin >> num;
        if (primenumber(num)) {
            r++;
    }
    }
    cout << r;
}
