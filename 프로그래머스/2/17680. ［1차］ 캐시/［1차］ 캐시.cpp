#include <string>
#include <vector>
#include<algorithm>
#include<cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
      vector<string> cache;
    for(int i = 0; i< cities.size(); i++){
    string s = cities[i];
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        cities[i] = s;
    }
    
    if(cacheSize ==0){
        answer = 5 * cities.size();
    }
    // Step 1 : 단순 이중 for문
    // Step 2 : 시간복잡도를 위해 set, unordered_set 고려
  
    else {
    for (string city : cities ){
   
    auto it = find(cache.begin(), cache.end(), city);
    if (it != cache.end()) {
            // [Hit]
            answer += 1;
            // 찾은 데이터를 지우고 다시 뒤에 넣어 "최신" 상태로 만듦
            cache.erase(it);
            cache.push_back(city);
        } else {
            // [Miss]
            answer += 5;
            if (cache.size() >= cacheSize) {
                // 가장 오래된 데이터(앞부분) 삭제
                cache.erase(cache.begin());
            }
            cache.push_back(city);
        }
    
    }
    }
    return answer;
}