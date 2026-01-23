#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string s;
    cin>> s;
    // 얘가 움직인걸 좌쵸로 뽑고 나머지는 다 # 처리하면 될듯
    vector<pair<int,int>> dir ;
    dir.push_back({0,1});
    dir.push_back({-1,0});
    dir.push_back({0,-1});
    dir.push_back({1,0});
   vector< pair<int,int> >path ;
    
    int x = 0, y = 0;

    int minX = 0, maxX = 0;
    int minY = 0, maxY = 0;

    int position_cnt = 0;
    path.push_back({0,0});
    int cur = 0;
    for(int i = 0; i< N; i++){
        if(s[i] == 'L'){
            cur = (cur +3) % 4;
            
        }
        else if (s[i] == 'R'){
            cur = (cur +1) % 4;
            
        }
        else if (s[i] == 'F'){
            x += dir[cur].first;
               y += dir[cur].second;

               path.push_back({x,y});

               minX = min(minX, x);
               maxX = max(maxX, x);
               minY = min(minY, y);
               maxY = max(maxY, y);
        }
        
    }
    int H = maxY - minY + 1;
    int W = maxX - minX + 1;vector<vector<char>> grid(H, vector<char>(W, '#'));
    for (auto &p : path) {
        int gx = p.first - minX;
        int gy = p.second - minY;
        grid[gy][gx] = '.';
    }
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cout << grid[y][x];
        }
        cout << '\n';
    }

}
