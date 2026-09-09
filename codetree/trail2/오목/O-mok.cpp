#include <iostream>

using namespace std;

int board[19][19];
int isfive(int i, int j, int color){
//i랑 j에서 시작하는거임 
if( j+4<19 &&  board[i][j+1] == color && board[i][j+2] == color  && board[i][j+3] == color && board[i][j+4] == color){
    return 1;
}
else if(i+4<19 && board[i+1][j] == color && board[i+2][j] == color && board[i+3][j] == color && board[i+4][j] == color){
    return 2;
}
else if(i+4<19 && j+4<19 &&board[i+1][j+1] == color && board[i+2][j+2] == color && board[i+3][j+3] == color && board[i+4][j+4] == color){
    return 3;
}
else if(i+4<19 && j-4>=0 && board[i+1][j-1] == color && board[i+2][j-2] == color && board[i+3][j-3] == color && board[i+4][j-4] == color){
    return 4;
}
else 
return 0;

}
int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> board[i][j];

    // Please write your code here.

//검은색은 1, 흰색은 2 알이 안놓이면 0으로 하기 
// 검또는 흰이 이겼을 때 5개의 바둑알 중 가운데에 있는 바둑알의 가로줄 번호와 세로줄 번호를 공백으로 출력
// 아직 승부 안났으면 0 출력하기 
// 결과는 zero index에서 가져오고 거기서 +1 씩 하기 

for(int i = 0; i< 19 ; i++){
    for(int j = 0; j< 19; j++){
//모든 바둑판 원소들을 보며 
// 어떤 원소에서 검은색이면 검은색 검사하기
if(board[i][j] == 1){
if(isfive(i,j,1) == 1){
cout<< 1<<endl;
cout<< i+1<<" "<< j+3<<endl;
return 0;
}
if(isfive(i,j,1) == 2){
cout<< 1<<endl;
cout<< i+3<<" "<< j+1<<endl;
return 0;
}
if(isfive(i,j,1) == 3){
cout<< 1<<endl;
cout<< i+3<<" "<< j+3<<endl;return 0;
}
if(isfive(i,j,1) == 4){
cout<< 1<<endl;
cout<< i+3<<" "<< j-1<<endl;
return 0;
}
}

// 어떤 원소에서 흰색이면 흰색 검사하기
if(board[i][j] == 2){

if(isfive(i,j,2) == 1){
cout<< 2<<endl;
cout<< i+1<<" "<< j+3<<endl;
return 0;
}
if(isfive(i,j,2) == 2){
cout<< 2<<endl;
cout<< i+3<<" "<< j+1<<endl;
return 0;
}
if(isfive(i,j,2) == 3){
cout<< 2<<endl;
cout<< i+3<<" "<< j+3<<endl;
return 0;
}
if(isfive(i,j,2) == 4){
cout<< 2<<endl;
cout<< i+3<<" "<< j-1<<endl;
return 0;
}

}

    }
}
cout<<0;
    return 0;
}