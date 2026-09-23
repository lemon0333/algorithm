class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       int n = grid.size();
        vector<vector<int>> contain;
        for(int i = 0; i< n; i++){
            contain.push_back(grid[i]);
            
        
        }
        vector<vector<int>> vertical;
        // 가로 넣기 
        for(int i = 0; i< n; i++){
            vector<int> temp;
            for(int j = 0; j< n; j++){
                temp.push_back(grid[j][i]);
            }
            
            vertical.push_back(temp);
        }
int result = 0;
     for(int i = 0; i< n; i++){
        for(int j = 0; j<n;j++){
            if(vertical[j] == contain[i]) result++;
        }
     }
     return result;}

    
};