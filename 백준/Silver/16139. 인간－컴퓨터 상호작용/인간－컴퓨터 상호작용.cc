#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cmath>

using namespace std;



int result(char c,int a, int b, vector<vector<int> > &cal){
    int ca = c - 'a';
    int answer = cal[ca][b+1] - cal[ca][a];
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    string s;
    cin >>s;
    
    int N;
    cin >> N;
    
    char c;
    int a,b;
    
    vector<vector<int>> cal(26,vector<int>(s.size()+1,0));
    for(int i = 0; i< 26; i++){
        cal[i][0]=0;
    }
    for(int i = 1; i<= s.size(); i++){
        for(int j = 0; j< 26; j++){
            cal[j][i] = cal[j][i-1];
        }
        int index = s[i-1]-'a';
        cal[index][i]++;
    }
    vector<int> contain;
    for(int i = 0; i< N ;i++){
        cin>>c>> a>>b;
        contain.push_back( result(c,a,b,cal) );
    }
    
    for(auto elem: contain){
        cout<<elem<<"\n";
    }
}
