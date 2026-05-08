#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// &를 붙여서 참조자로 전달받아야 복사 비용이 발생하지 않습니다.
string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> counts;

    // 1. 참여자 수를 카운트 (O(N))
    // string& name을 사용해 문자열 복사마저 방지
    for (const string& name : participant) {
        counts[name]++;
    }

    // 2. 완주자 수를 차감 (O(N))
    for (const string& name : completion) {
        counts[name]--;
        // 차감 후 0이 되면 맵에서 아예 지워버리는 것도 방법이지만, 
        // 그냥 마지막에 한 번 더 도는 게 안전합니다.
    }

    // 3. 남은 사람이 범인! (O(N))
    for (const auto& pair : counts) {
        if (pair.second > 0) {
            return pair.first;
        }
    }

    return "";
}