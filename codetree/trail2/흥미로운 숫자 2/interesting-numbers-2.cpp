#include <iostream>
#include<string>
using namespace std;
#include<vector>
int X, Y;
bool interesting(int a){
    // 일단 string으로 바꾸고 
string s = to_string(a);
vector<int> contain(10,0);
for(int i = 0; i< s.size(); i++){
if(s[i] == '1'){
contain[1] +=1;
}
if(s[i] == '2'){
    contain[2] +=1;
}
if(s[i] == '3'){
    contain[3] +=1;
}
if(s[i] == '4'){
    contain[4] +=1;
}
if(s[i] == '5'){
    contain[5] +=1;
}
if(s[i] == '6'){
    contain[6] +=1;
}
if(s[i] == '7'){
    contain[7] +=1;
}
if(s[i] == '8'){
    contain[8] +=1;
}
if(s[i] == '9'){
    contain[9] +=1;
}
if(s[i] == '0'){
    contain[0] +=1;
}

}
// 어떤칸은 1이 아니고 어떤칸만 1이면 딱 끝남 
int zeroc = 0;
int onec = 0;
int otherc = 0;
for(int i = 0; i< 10; i++){
if(contain[i] == 1) onec ++;
else if (contain[i] == 0) zeroc++;
else otherc++;
}
if(onec == 1 && zeroc ==8){
    return true;
}
return false;
}
int main() {
    cin >> X >> Y;

    // Please write your code here.
// 정확히 한자리마 ㄴ달라야 흥미로운 숫자다 
int result = 0;
for(int i = X ; i<=Y; i++){
if(interesting(i)){
    result++;
}

}
cout<<result;
    return 0;
}