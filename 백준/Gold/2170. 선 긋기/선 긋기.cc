#include <iostream>
#include <vector>
#include<string>
#include <queue>
#include<cmath>
#include <algorithm>

using namespace std;




bool visited[5][5];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
long long int result;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>> N;
    
    pair<int,int> cur;
    int a, b;
    vector<pair<int,int>> contain;
    for(int i = 0; i< N ; i++){
        cin>>a>>b;
        cur.first = a;
        cur.second = b;
        contain.push_back(cur);
    }
  long long int result = 0;
    sort(contain.begin(),contain.end());
   long long int start = contain[0].first;
       long long int end = contain[0].second;
    for(int i = 0; i< N; i++){
        // 새선분일 때 새거라면 현재까지의 결과 더해주고 앞부분만 당겨주기
        if(end < contain[i].first){
      
            result += end-start;
            start = contain[i].first;      // 기준점 새로 시작
                        end = contain[i].second;
        
        }
        // 기존의 선분이라면 끝 부분만 업데이트
        if(end<contain[i].second){
            end=contain[i].second;
        }
        
    }
        result += end - start;
    cout<<result;
}
