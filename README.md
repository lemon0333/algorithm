# algorithm
This is an auto push repository for Baekjoon Online Judge created with [BaekjoonHub](https://github.com/BaekjoonHub/BaekjoonHub).

### 에러
-시간초과 : 1) 루프문때문에 나왔을 경우 2) 시간복잡도 계산 잘못해서 알고리즘 자체가 잘못되었을 경우

### C++
- 투포인터 : left = 0; right = max.size() 해놓고서 조건에 따라 left, right 옮겨가면 불필요한 인덱스 삽입, 삭제를 안해도되고 보고싶은거를 다 볼 수 있다.
- transform : std::transform(s.begin(), s.end(), s.begin(), ::toupper); 모든 문자열 어퍼 클래스 적용,
- find 함수 : auto it = find(cache.begin(), cache.end(), city); cache 문자열의 시작부터 끝까지 city 문자열이 있는지 없는지 확인해주는 함수
- unordered_map : O(N)으로 접근할 수 있음 주로 쓰는 방식이 unordered_map<string, int> count 해서 count[elem] ++ 하면 뒤의 숫자가 int값이 커져서 해당 문자열이 몇개 있는지 확인할때 잘 쓰임
- 애매하다 싶으면 인덱스 정렬해보자 : 인덱스를 정렬하는 것 만으로 복잡도 줄일 알고리즘을 찾을 수 있다.
-  sort(vcontain.begin(), vcontain.end(), [](auto& a, auto& b){
        if (a.second != b.second) return a.second > b.second; 
        return a.first < b.first;                              
        });

### SQL
- ROUND (123,3) 몇자리까지 반올림
- CASE WHEN : CASE length < 10 then 10 else length then length 이런식으로 if else와 같은 분기문
- CONCAT(FORMATsth,2), "sth" : CONCAT을 통해 쿼리 결과값을 바꿔줄 수 있고, FORMAT을 통해 쿼리 자릿값과 같은 형식을 바꿀 수 있다.
- format 말고 round 이거가 반올림할때 써야하고, 얼라이언싱 이미 한 걸 order by 하려하면 문자열 기준 순서 비교하기 때문에 얼라이언싱 하기 전의 값인 머 sum(sth) 이런걸 넣어야한다. sum(sth) as sss 에서의 sss 를 넣는게 아니라
- limit 1 : 오더 한거에서 상위 하나 상위 5개 이런식으로 나누는 문법

<!---LeetCode Topics Start-->
# LeetCode Topics
## Array
|  |
| ------- |
| [0011-container-with-most-water](https://github.com/lemon0333/algorithm/tree/master/0011-container-with-most-water) |
| [0015-3sum](https://github.com/lemon0333/algorithm/tree/master/0015-3sum) |
| [0016-3sum-closest](https://github.com/lemon0333/algorithm/tree/master/0016-3sum-closest) |
| [0053-maximum-subarray](https://github.com/lemon0333/algorithm/tree/master/0053-maximum-subarray) |
| [0075-sort-colors](https://github.com/lemon0333/algorithm/tree/master/0075-sort-colors) |
| [0167-two-sum-ii-input-array-is-sorted](https://github.com/lemon0333/algorithm/tree/master/0167-two-sum-ii-input-array-is-sorted) |
| [0179-largest-number](https://github.com/lemon0333/algorithm/tree/master/0179-largest-number) |
| [0198-house-robber](https://github.com/lemon0333/algorithm/tree/master/0198-house-robber) |
| [0209-minimum-size-subarray-sum](https://github.com/lemon0333/algorithm/tree/master/0209-minimum-size-subarray-sum) |
| [0238-product-of-array-except-self](https://github.com/lemon0333/algorithm/tree/master/0238-product-of-array-except-self) |
| [0283-move-zeroes](https://github.com/lemon0333/algorithm/tree/master/0283-move-zeroes) |
| [0347-top-k-frequent-elements](https://github.com/lemon0333/algorithm/tree/master/0347-top-k-frequent-elements) |
| [0643-maximum-average-subarray-i](https://github.com/lemon0333/algorithm/tree/master/0643-maximum-average-subarray-i) |
| [0704-binary-search](https://github.com/lemon0333/algorithm/tree/master/0704-binary-search) |
| [2352-equal-row-and-column-pairs](https://github.com/lemon0333/algorithm/tree/master/2352-equal-row-and-column-pairs) |
## Two Pointers
|  |
| ------- |
| [0011-container-with-most-water](https://github.com/lemon0333/algorithm/tree/master/0011-container-with-most-water) |
| [0015-3sum](https://github.com/lemon0333/algorithm/tree/master/0015-3sum) |
| [0016-3sum-closest](https://github.com/lemon0333/algorithm/tree/master/0016-3sum-closest) |
| [0075-sort-colors](https://github.com/lemon0333/algorithm/tree/master/0075-sort-colors) |
| [0151-reverse-words-in-a-string](https://github.com/lemon0333/algorithm/tree/master/0151-reverse-words-in-a-string) |
| [0167-two-sum-ii-input-array-is-sorted](https://github.com/lemon0333/algorithm/tree/master/0167-two-sum-ii-input-array-is-sorted) |
| [0283-move-zeroes](https://github.com/lemon0333/algorithm/tree/master/0283-move-zeroes) |
| [0392-is-subsequence](https://github.com/lemon0333/algorithm/tree/master/0392-is-subsequence) |
## Binary Search
|  |
| ------- |
| [0167-two-sum-ii-input-array-is-sorted](https://github.com/lemon0333/algorithm/tree/master/0167-two-sum-ii-input-array-is-sorted) |
| [0209-minimum-size-subarray-sum](https://github.com/lemon0333/algorithm/tree/master/0209-minimum-size-subarray-sum) |
| [0704-binary-search](https://github.com/lemon0333/algorithm/tree/master/0704-binary-search) |
## Sliding Window
|  |
| ------- |
| [0209-minimum-size-subarray-sum](https://github.com/lemon0333/algorithm/tree/master/0209-minimum-size-subarray-sum) |
| [0643-maximum-average-subarray-i](https://github.com/lemon0333/algorithm/tree/master/0643-maximum-average-subarray-i) |
## Sorting
|  |
| ------- |
| [0015-3sum](https://github.com/lemon0333/algorithm/tree/master/0015-3sum) |
| [0016-3sum-closest](https://github.com/lemon0333/algorithm/tree/master/0016-3sum-closest) |
| [0075-sort-colors](https://github.com/lemon0333/algorithm/tree/master/0075-sort-colors) |
| [0179-largest-number](https://github.com/lemon0333/algorithm/tree/master/0179-largest-number) |
| [0242-valid-anagram](https://github.com/lemon0333/algorithm/tree/master/0242-valid-anagram) |
| [0347-top-k-frequent-elements](https://github.com/lemon0333/algorithm/tree/master/0347-top-k-frequent-elements) |
## Prefix Sum
|  |
| ------- |
| [0209-minimum-size-subarray-sum](https://github.com/lemon0333/algorithm/tree/master/0209-minimum-size-subarray-sum) |
| [0238-product-of-array-except-self](https://github.com/lemon0333/algorithm/tree/master/0238-product-of-array-except-self) |
## Divide and Conquer
|  |
| ------- |
| [0053-maximum-subarray](https://github.com/lemon0333/algorithm/tree/master/0053-maximum-subarray) |
| [0347-top-k-frequent-elements](https://github.com/lemon0333/algorithm/tree/master/0347-top-k-frequent-elements) |
## Dynamic Programming
|  |
| ------- |
| [0053-maximum-subarray](https://github.com/lemon0333/algorithm/tree/master/0053-maximum-subarray) |
| [0062-unique-paths](https://github.com/lemon0333/algorithm/tree/master/0062-unique-paths) |
| [0198-house-robber](https://github.com/lemon0333/algorithm/tree/master/0198-house-robber) |
| [0392-is-subsequence](https://github.com/lemon0333/algorithm/tree/master/0392-is-subsequence) |
| [0790-domino-and-tromino-tiling](https://github.com/lemon0333/algorithm/tree/master/0790-domino-and-tromino-tiling) |
## Quicksort
|  |
| ------- |
| [0075-sort-colors](https://github.com/lemon0333/algorithm/tree/master/0075-sort-colors) |
## Bubble Sort
|  |
| ------- |
| [0075-sort-colors](https://github.com/lemon0333/algorithm/tree/master/0075-sort-colors) |
## String
|  |
| ------- |
| [0151-reverse-words-in-a-string](https://github.com/lemon0333/algorithm/tree/master/0151-reverse-words-in-a-string) |
| [0179-largest-number](https://github.com/lemon0333/algorithm/tree/master/0179-largest-number) |
| [0242-valid-anagram](https://github.com/lemon0333/algorithm/tree/master/0242-valid-anagram) |
| [0392-is-subsequence](https://github.com/lemon0333/algorithm/tree/master/0392-is-subsequence) |
| [2390-removing-stars-from-a-string](https://github.com/lemon0333/algorithm/tree/master/2390-removing-stars-from-a-string) |
## Greedy
|  |
| ------- |
| [0011-container-with-most-water](https://github.com/lemon0333/algorithm/tree/master/0011-container-with-most-water) |
| [0179-largest-number](https://github.com/lemon0333/algorithm/tree/master/0179-largest-number) |
## Stack
|  |
| ------- |
| [2390-removing-stars-from-a-string](https://github.com/lemon0333/algorithm/tree/master/2390-removing-stars-from-a-string) |
## Simulation
|  |
| ------- |
| [2352-equal-row-and-column-pairs](https://github.com/lemon0333/algorithm/tree/master/2352-equal-row-and-column-pairs) |
| [2390-removing-stars-from-a-string](https://github.com/lemon0333/algorithm/tree/master/2390-removing-stars-from-a-string) |
## Math
|  |
| ------- |
| [0062-unique-paths](https://github.com/lemon0333/algorithm/tree/master/0062-unique-paths) |
## Combinatorics
|  |
| ------- |
| [0062-unique-paths](https://github.com/lemon0333/algorithm/tree/master/0062-unique-paths) |
## Hash Table
|  |
| ------- |
| [0242-valid-anagram](https://github.com/lemon0333/algorithm/tree/master/0242-valid-anagram) |
| [0347-top-k-frequent-elements](https://github.com/lemon0333/algorithm/tree/master/0347-top-k-frequent-elements) |
| [2352-equal-row-and-column-pairs](https://github.com/lemon0333/algorithm/tree/master/2352-equal-row-and-column-pairs) |
## Matrix
|  |
| ------- |
| [2352-equal-row-and-column-pairs](https://github.com/lemon0333/algorithm/tree/master/2352-equal-row-and-column-pairs) |
## Heap (Priority Queue)
|  |
| ------- |
| [0347-top-k-frequent-elements](https://github.com/lemon0333/algorithm/tree/master/0347-top-k-frequent-elements) |
## Bucket Sort
|  |
| ------- |
| [0347-top-k-frequent-elements](https://github.com/lemon0333/algorithm/tree/master/0347-top-k-frequent-elements) |
## Counting
|  |
| ------- |
| [0347-top-k-frequent-elements](https://github.com/lemon0333/algorithm/tree/master/0347-top-k-frequent-elements) |
## Quickselect
|  |
| ------- |
| [0347-top-k-frequent-elements](https://github.com/lemon0333/algorithm/tree/master/0347-top-k-frequent-elements) |
<!---LeetCode Topics End-->
