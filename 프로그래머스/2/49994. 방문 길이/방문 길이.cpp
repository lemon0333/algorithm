#include <string>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int curX = 0;
     int curY = 0;
    int nX = 0;
    int nY=0;
   set <pair<pair<int,int> , pair<int,int> >> path;
    for(int i = 0; i< dirs.size(); i++){
        
        if(dirs[i] == 'L' && curX-1 >= -5){
            --nX;
            if(curX+curY < nX+nY){
            path.insert({{curX,curY},{nX,nY}});
            }
            else {
                path.insert({{nX,nY},{curX,curY}});  
            }
            curX = nX;
            curY = nY; 
            
        }
         if(dirs[i] == 'R' && curX+1 <= 5){
            ++nX;
          
            if(curX+curY < nX+nY){
            path.insert({{curX,curY},{nX,nY}});
            }
            else {
                path.insert({{nX,nY},{curX,curY}});  
            }
            curX = nX;
            curY = nY; 
        }
         if(dirs[i] == 'D' && curY-1 >= -5){
            --nY;
           
            if(curX+curY < nX+nY){
            path.insert({{curX,curY},{nX,nY}});
            }
            else {
                path.insert({{nX,nY},{curX,curY}});  
            }
            curX = nX;
            curY = nY; 
        }
         if(dirs[i] == 'U' && curY+1 <= 5){
            ++nY;
            if(curX+curY < nX+nY){
            path.insert({{curX,curY},{nX,nY}});
            }
            else {
                path.insert({{nX,nY},{curX,curY}});  
            }
               curX = nX;
            curY = nY; 
        }
        
        
    }
    
    for(auto elem: path){
        answer++;
    }
    return answer;
}