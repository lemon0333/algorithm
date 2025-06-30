#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    // 윗부분
    for(int i = 0; i < N - 1; i++) {
        // 공백 출력
        for(int j = 0; j < N - i - 1; j++) cout << " ";
        // 별 출력
        for(int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << endl;
    }

    // 중간줄
    for(int i = 0; i < 2 * N - 1; i++) cout << "*";
    cout << endl;

    // 아래부분
    for(int i = N - 2; i >= 0; i--) {
        // 공백 출력
        for(int j = 0; j < N - i - 1; j++) cout << " ";
        // 별 출력
        for(int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << endl;
    }

    return 0;
}
