#include <string>
#include <vector>
#include<cmath>
#include<climits>
#include<queue>
using namespace std;
 int answer = -1;
int dunsize;
// 이게 범위가 0으로 나오느넥 문제

void backtracking(int K, int count, vector<vector<int>> dungeons, vector<bool> used){
    // dunsize까지 가면서 
    answer = max(answer,count);
    for(int i = 0; i< dunsize; i++){
        if(used[i] == false && K >=dungeons[i][0]){
            // 그 던전에 들어갈 수 있다면 
            used[i] = true;
            // used[i]를 true로 넣고 그 안으로 더 들어가기
            backtracking(K- dungeons[i][1] , count+1, dungeons, used);
            // backtracking 끝나고 나서는 나가기 
            used[i] = false;
        }
    }
    
}
int solution(int k, vector<vector<int>> dungeons) {
   
     dunsize = dungeons.size();

    vector<bool> used(dunsize,false);
    backtracking(k,0, dungeons, used);
   
        
        
        
    
    return answer;
}