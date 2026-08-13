#include <vector>
#include<set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size();

    set<int> contain;
    for(int i = 0; i< size; i++){
        int a = nums[i];
        contain.insert(a);
    }
    if(size/2 > contain.size()){
        return contain.size();
    }
    else{
        return size/2;
    }
    
   
}