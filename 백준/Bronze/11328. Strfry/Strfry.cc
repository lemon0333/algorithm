#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() != s2.size()) {
            cout << "Impossible\n";
            continue;
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if (s1 == s2) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}
