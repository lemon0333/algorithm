#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int k, i, j;
    vector<vector<int>> adj (n);
    for( i = 0; i < n; i++ ){
        for( j = 0; j< n ; j++){
            k = computers[i][j];
              if(k != 0 && i != j){
          adj[i].push_back(j);
          adj[j].push_back(i);
      }
        }
    
    }
    
   vector<bool> visited(n+1, false);
    int count = 0;
    
    for(int start = 0; start< n; start++){
        
        if(visited[start]) continue; // 이미 방문한 집합은 건너뛰고 
        count ++;
        queue <int> q;
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int next : adj[cur]){
                 if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    answer = count;
    return answer;
}