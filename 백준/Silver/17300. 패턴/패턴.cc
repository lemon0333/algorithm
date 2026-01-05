//
//  main.cpp
//  C++
//
//  Created by 손현빈 on 12/16/25.
//

#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
using ll = long long;

int facto(int sth){
    int r = 1;
    for(int i = 1; i <=sth ; i++){
        r *= i;
    }
    return r;
}

int roma(int A){
    // 4+ A -1 C A
    int upper = facto(4+A-1);
    int down = facto(A);
    int down2 = facto(3);
    int result = upper / (down * down2);
    return result;
}
bool is_prime(int n){
    for(int i = 2; i< n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int L;
    cin>> L;
    int num;
    vector<int> contain;
    for(int i =0;i< L;i++){
        cin>>num;
        contain.push_back(num);
        
    }
    // 패턴인지 아닌지 가리면 된다/
    
    // 가능 불가능 핵심 조건 visited를 통해 방문했는지 안했는지 방문 여부의 확인
    // 중간 점 테이블 (두 점을 연결할 때 반드시 거쳐야하는 점)
    // 두 점을 지났는데 중간점이 visit하지 않았다면 결과는 불가능 이런식으로 구현해보자
    
    vector<int> visited(10,0);
    int middle_table[10][10] = {0};
    
    middle_table[1][3] = middle_table[3][1] = 2;
    
    middle_table[4][6] = middle_table[6][4] = 5;
    
    middle_table[7][9] = middle_table[9][7] = 8;
    
    middle_table[1][7] = middle_table[7][1] = 4;
    middle_table[2][8] = middle_table[8][2] = 5;
    middle_table[9][3] = middle_table[3][9] = 6;
    
    middle_table[1][9] = middle_table[9][1] = 5;
    
    middle_table[7][3] = middle_table[3][7] = 5;
    if(L <3){
        cout<<"NO";
        return 0;
    }
        for(int i = 0; i< L-1 ; i++){
        int a = contain[i];
        // 방문한 적이 있다면 바로 나가기
        if(visited[a] == 1){
            cout<< "NO";
            return 0;
        }
        
        // 재방문이 아니라면
        visited[a] = 1;
        
            // 다음것이 무엇인지 비교
            int b = contain[i+1];
            if(visited[b] == 1){
                cout<< "NO";
                return 0;
            }
            int mid = middle_table[a][b];
            if(mid ==0){
                // 아무일도 없음
            }
            if(mid !=0){
                // 중간점을 방문하지 않았다면å
                if(visited[mid] ==0){
                    cout<<"NO";
                    return 0;
                }
            }
        
        
    }
    cout<<"YES";
}


