#include <iostream>
#include<vector>
using namespace std;
long long int check(long long int max_lead, long long int max_follow, long long int customer){
long long int check_result = 0;
customer = customer - max_lead;
if(customer <= 0){
    return 1;
}
else{
    // 팀장이 자기일을 해도 고객이 남는다면,
    check_result++;
    if(customer % max_follow == 0){
        check_result += customer / max_follow;
    }
    else {
        check_result += customer / max_follow;
        check_result++;
    }
}

return check_result;
}
int main() {
    // Please write your code here.
    
    long long int N;
    cin>> N;
    long long int result = 0;
long long int max_lead;
long long int max_follow;
vector<long long int> all_customer(N,0);
    for(int i = 0; i< N; i++){
// n개의 식당에 대해서 
long long int customer ;
cin>>customer;
all_customer[i] = customer;
}

    cin>> max_lead>>max_follow;

    for(int i = 0; i< N; i++){
long long int customer = all_customer[i];
result += check(max_lead,max_follow,customer);
    }

    cout<<result;
    return 0;
}