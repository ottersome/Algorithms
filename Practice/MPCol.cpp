#include <iostream>
#include <cstdio>
#define NU 'n'
#define XU 'x'
#define N 105

struct posCol{
    char d;
    char r;
    bool isPos(char){
    
    }
};
char A[N][N];
posCol S[N][N];
using namespace std;

char last = NU;
int sizeo = 0;
void fillS(int sizeo){
    for(int i=0;i<sizeo;i++){
        for(int j=0;j<sizeo;j++){
            S[i][j] = {NU,NU};//n standing for null
        }
    }
}
posCol path(int i,int j){
	//memoization 
    posCol s = S[i][j];
    if(S[i][j].d != NU && S[i][j].r != NU){
        //printf("At (%d,%d)=%c Returning memoized\n",i,j,A[i][j]);
        return S[i][j];
    }
    //final condition 
    if(i==sizeo-1 && j==sizeo-1){
        S[i][j] = {A[i][j],A[i][j]};
        last = A[i][j];
        //printf("We are in ultimate value %c\n",A[i][j]);
        return S[i][j];
    }
    //printf("At (%d,%d)=%c No mem no tops\n",i,j,A[i][j]);
    posCol down = {XU,XU};
    posCol right = {XU,XU};
    if(i != sizeo-1){
        down = path(i+1,j);
    }
    if(j != sizeo-1){
        right = path(i,j+1);
    }
    //new
    if(A[i][j] == last && (right.d != XU || right.r != XU)){
        S[i][j] = right;
    }else if(A[i][j] == (down.d != XU || down.r != XU)){
        S[i][j] = down;
    }else if(right != last && A[i][j] == right){
        S[i][j] = A[i][j];
    }else if(down != last && A[i][j] == down){
        S[i][j] = A[i][j];
    }else if(right == last && A[i][j] != last){
        S[i][j] = A[i][j];
    }else if(down == last && A[i][j] != last){
        S[i][j] = A[i][j];
    }else{
        S[i][j] = 'x';
    }
    //printf("At (%d,%d)=%c, selection is: %c\n",i,j,A[i][j],S[i][j]);
    return S[i][j];
}
int main(){
    cin >> sizeo;
    fillS(sizeo);
    for(int i =0;i<sizeo;i++){
        for(int j = 0;j<sizeo;j++){
            cin >> A[i][j];
        }
    }
	char result = path(0,0);
    if(result != 'x'){
        cout << "Yes"<<endl;
    }else{
        cout << "No"<<endl;
    }
	return 0;
}
