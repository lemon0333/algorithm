#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    // unique는 연속된 중복 요소를 뒤로 밀고, 중복 시작 지점의 반복자를 반환합니다.
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}