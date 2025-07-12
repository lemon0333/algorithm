#include <iostream>
#include <stack>
#include <string>

using namespace std;
int N;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> N;

    int cnt = 0;
    int result = 666;
    while (1) {
        if (to_string(result).find("666") != string::npos) {
            cnt++;
        }
        if (cnt == N) {
            cout << result;
            break;
        }
        result++;
    }
}
