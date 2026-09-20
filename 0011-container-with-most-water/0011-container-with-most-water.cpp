class Solution {
public:
    int maxArea(vector<int>& height) {
       // 만들어지는 직사각형의 최대 넓이 구하기 
     // 그리디 투포인터
     // 우선 그리디한 상황은 만들어지는 것이 자명함 왼쪽 오른쪽에서 넓이가 가장 클때부터 보면서 줄여가면 됨
     // 높이가 짧은쪽이 결정함 그거에 맞춰서 높이가 짧으면 그거의 높이를 키워버리면 됨. 
     // 높이를 줄여가며 계속 max때려서 확인하기
     int left = 0;
     int right = height.size()-1;
     int r = 0;
     r = (right-left) * min(height[left], height[right]);
     while(left<right){
        if(height[left]< height[right]){
            left++;
            r = max(r, (right-left)* min(height[left], height[right]));
            continue;
        }
        if(height[left]>= height[right]){
            right--;
          r = max(r, (right-left)* min(height[left], height[right]));
            continue;
        }


     }
     return r;
    }
};