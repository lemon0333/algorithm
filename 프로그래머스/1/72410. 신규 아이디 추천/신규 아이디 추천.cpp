
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

string solution(string new_id) {
    string s = new_id;

    // 1단계: 소문자화 — (원래 맨 뒤에 있던 루프를 맨 앞으로)
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i]))
            s[i] = tolower(s[i]);
    }

    // 2단계: 허용 문자만 남기기 — (원래의 필터 if 그대로, 새 문자열에 담기)
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]) || isalpha(s[i]) || s[i] == '-' || s[i] == '_' || s[i] == '.')
            t += s[i];
    }

    // 3단계: 연속된 .. 을 하나로 — (prev/next 로직 그대로, 2단계 결과물 t에 적용)
    string u = "";
    char prev = ' ';
    char next = ' ';
    for (int i = 0; i < t.size(); i++) {
        prev = next;
        next = t[i];
        if (prev == '.' && next == '.')
            continue;
        u += t[i];
    }

    // 4단계: 맨 앞/맨 뒤의 . 제거 — (3단계까지 끝난 u를 보고 판단해야 정확함)
    if (!u.empty() && u[0] == '.')
        u = u.substr(1);                 // 첫 글자 떼기
    if (!u.empty() && u[u.size()-1] == '.')
        u.pop_back();                    // 마지막 글자 떼기

    // 5단계: 빈 문자열이면 "a" — (원래 맨 앞에 있던 검사를 여기로: 다 깎인 "뒤에" 검사)
    if (u.size() == 0)
        u = "a";

    // 6단계: 16자 이상이면 15자로 자르고, 끝이 . 이면 또 제거
    if (u.size() >= 16) {
        u = u.substr(0, 15);             // 처음 15글자만
        if (u[u.size()-1] == '.')
            u.pop_back();
    }

    // 7단계: 2자 이하면 마지막 글자를 3자 될 때까지 반복
    while (u.size() <= 2)
        u += u[u.size()-1];              // 마지막 글자 붙이기 (u.back()과 동일)

    return u;
}