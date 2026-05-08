# algorithm
This is an auto push repository for Baekjoon Online Judge created with [BaekjoonHub](https://github.com/BaekjoonHub/BaekjoonHub).


### C++
- 투포인터 : left = 0; right = max.size() 해놓고서 조건에 따라 left, right 옮겨가면 불필요한 인덱스 삽입, 삭제를 안해도되고 보고싶은거를 다 볼 수 있다.
- transform : std::transform(s.begin(), s.end(), s.begin(), ::toupper); 모든 문자열 어퍼 클래스 적용,
- find 함수 : auto it = find(cache.begin(), cache.end(), city); cache 문자열의 시작부터 끝까지 city 문자열이 있는지 없는지 확인해주는 함수
- unordered_map : O(N)으로 접근할 수 있음 주로 쓰는 방식이 unordered_map<string, int> count 해서 count[elem] ++ 하면 뒤의 숫자가 int값이 커져서 해당 문자열이 몇개 있는지 확인할때 잘 쓰임

### SQL
- ROUND (123,3) 몇자리까지 반올림
- CASE WHEN : CASE length < 10 then 10 else length then length 이런식으로 if else와 같은 분기문
- CONCAT(FORMATsth,2), "sth" : CONCAT을 통해 쿼리 결과값을 바꿔줄 수 있고, FORMAT을 통해 쿼리 자릿값과 같은 형식을 바꿀 수 있다.
- format 말고 round 이거가 반올림할때 써야하고, 얼라이언싱 이미 한 걸 order by 하려하면 문자열 기준 순서 비교하기 때문에 얼라이언싱 하기 전의 값인 머 sum(sth) 이런걸 넣어야한다. sum(sth) as sss 에서의 sss 를 넣는게 아니라
