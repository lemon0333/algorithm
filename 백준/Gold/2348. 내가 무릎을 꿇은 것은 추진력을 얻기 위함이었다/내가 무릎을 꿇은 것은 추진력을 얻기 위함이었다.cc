#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll LIMIT = 1000000000LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    int sLen = S.length();
    ll min_fa = -1;

 
    for (int i = 1; i <= 9 && i <= sLen - 2; ++i) {
        string s1 = S.substr(0, i);
        if (s1.length() > 1 && s1[0] == '0') continue;
        ll a1 = stoll(s1);
        if (a1 >= LIMIT) continue;

      
        for (int j = 1; j <= 9 && i + j <= sLen - 1; ++j) {
            string s2 = S.substr(i, j);
            if (s2.length() > 1 && s2[0] == '0') continue;
            ll a2 = stoll(s2);
            
         
            if (a2 >= LIMIT || a2 <= a1) continue;

            ll d = a2 - a1;
            int current_pos = i + j;
            ll prev_a = a2;

           
            while (current_pos < sLen) {
                // 1. 현재 항이 마지막 전 항(a_n-1)이라 가정하고 마지막 항(an) 체크
                string s_last = S.substr(current_pos);
              
                if (s_last.length() <= 10) {
                    if (!(s_last.length() > 1 && s_last[0] == '0')) {
                        ll an = stoll(s_last);
                        if (an < LIMIT && an % prev_a == 0) {
                            ll fa = an / prev_a;
                            if (fa >= 2) {
                                if (min_fa == -1 || fa < min_fa) min_fa = fa;
                            }
                        }
                    }
                }

                // 2. 다음 등차수열 항(ak)이 문자열에 존재하는지 확인
                ll next_a = prev_a + d;
                if (next_a >= LIMIT) break;
                
                string s_next = to_string(next_a);
                int next_len = s_next.length();

              
                if (current_pos + next_len > sLen) break;
                
                if (S.substr(current_pos, next_len) == s_next) {
                    current_pos += next_len;
                    prev_a = next_a;
                } else {
                  
                    break;
                }
            }
        }
    }

    if (min_fa == -1) cout << 0;
    else cout << min_fa;

    return 0;
}