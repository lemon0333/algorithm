
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<utility>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> firstcontest(N,0);
    vector<int> secondcontest(N,0);
    vector<int> thirdcontest(N,0);
    vector<int> sumcontest(N,0);
    vector<int> firstresult(N,0);
    vector<int> secondresult(N,0);
    vector<int> thirdresult(N,0);
    vector<int> sumresult(N,0);
    vector<int> firstindex(N,0);
    for(int i = 0; i < N; i++){ firstindex[i] = i; }
    vector<int> secondindex(N,0);
    for(int i = 0; i < N; i++){ secondindex[i] = i; }
    vector<int> thirdindex(N,0);
    for(int i = 0; i < N; i++){ thirdindex[i] = i; }
    vector<int> sumindex(N,0);
    for(int i = 0; i < N; i++){ sumindex[i] = i; }
    int num;

    // 입력값 모두 받기
    for(int j = 0; j < N; j++){
        cin >> num;
        firstcontest[j] = num;
        sumcontest[j] += num;
    }
    for(int j = 0; j < N; j++){
        cin >> num;
        secondcontest[j] = num;
        sumcontest[j] += num;
    }
    for(int j = 0; j < N; j++){
        cin >> num;
        thirdcontest[j] = num;
        sumcontest[j] += num;
    }

    // rank 찾기
    // 이중 for문으로 rank를 찾는데에 시간 초과가 나왔다.
    // C++은 초당 10^8 번의 계산을 하는데, 10^5 * 10^5 가 이중 for문이 되고, 10^10 * 4 이기 때문에
    // 이 문제 같은 경우에선 이중 for문 박으면 무조건 터진다
    // 이중 for문 안쓰려면 nlogn 써야함 -> sort를 사용할 수 있음.
    // sort 람다함수 조합 꼭 잘 사용하자
    //  캡처는 "점수 배열"! 인덱스 a, b를 받아서 점수끼리 비교해야 함
    sort(firstindex.begin(), firstindex.end(), [&firstcontest](int a, int b) {
        return firstcontest[a] > firstcontest[b];
    });
    sort(secondindex.begin(), secondindex.end(), [&secondcontest](int a, int b) {
        return secondcontest[a] > secondcontest[b];
    });
    sort(thirdindex.begin(), thirdindex.end(), [&thirdcontest](int a, int b) {
        return thirdcontest[a] > thirdcontest[b];
    });
    sort(sumindex.begin(), sumindex.end(), [&sumcontest](int a, int b) {
        return sumcontest[a] > sumcontest[b];
    });

    // 순위 부여: 뒤(i-1)를 보고 동점이면 앞사람 순위 복사
    // - i > 0 조건 덕분에 배열 범위 초과 없음
    // - 동점자가 몇 명이든 연쇄 복사로 처리됨 (10 10 10 → 1 1 1)
    // - result 인덱스는 항상 index[i] (그 등수인 사람의 "원래 위치")
    for(int i = 0; i < N; i++){
        if(i > 0 && firstcontest[firstindex[i]] == firstcontest[firstindex[i-1]])
            firstresult[firstindex[i]] = firstresult[firstindex[i-1]];
        else
            firstresult[firstindex[i]] = i + 1;
    }
    for(int i = 0; i < N; i++){
        if(i > 0 && secondcontest[secondindex[i]] == secondcontest[secondindex[i-1]])
            secondresult[secondindex[i]] = secondresult[secondindex[i-1]];
        else
            secondresult[secondindex[i]] = i + 1;
    }
    for(int i = 0; i < N; i++){
        if(i > 0 && thirdcontest[thirdindex[i]] == thirdcontest[thirdindex[i-1]])
            thirdresult[thirdindex[i]] = thirdresult[thirdindex[i-1]];
        else
            thirdresult[thirdindex[i]] = i + 1;
    }
    for(int i = 0; i < N; i++){
        if(i > 0 && sumcontest[sumindex[i]] == sumcontest[sumindex[i-1]])
            sumresult[sumindex[i]] = sumresult[sumindex[i-1]];
        else
            sumresult[sumindex[i]] = i + 1;
    }

    for(auto elem : firstresult){
        cout << elem << " ";
    }
    cout << '\n';
    for(auto elem : secondresult){
        cout << elem << " ";
    }
    cout << '\n';
    for(auto elem : thirdresult){
        cout << elem << " ";
    }
    cout << '\n';
    for(auto elem : sumresult){
        cout << elem << " ";
    }
    cout << '\n';
    return 0;
}
