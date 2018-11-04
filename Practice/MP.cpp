#include <iostream>
#include <cstdio>
#define N 105
#define NEGINF -999999

using namespace std;
long long A[N][N];
long long S[N][N];
int sizeo;
void initS(){
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			S[i][j] = NEGINF;
		}
	}

}
long long path(long long A[N][N],int i,int j){
	if(S[i][j] != NEGINF){//memoization
		//printf("Memoized Return at (%d,%d) With Value %d\n",i,j,S[i][j]);
		return S[i][j];
	}
	if(j == sizeo-2 && i == sizeo-1){
		S[i][j] = A[i][j+1] - A[i][j]; 
		//printf("at (%d,%d) Vale = %d. Best case = %d\n",i,j,A[i][j],S[i][j]);
		return S[i][j];
	}else if(j == sizeo-1 && i == sizeo-2){
		S[i][j] = A[i+1][j] - A[i][j];
		//printf("at (%d,%d) Vale = %d. Best case = %d\n",i,j,A[i][j],S[i][j]);
		return S[i][j];
	}
	//printf("Going through (%d,%d)=%d\n",i,j,A[i][j]);
	//if memoized
	int diffDown = A[i+1][j] - A[i][j];
	int diffRight = A[i][j+1] - A[i][j];
	int valDown = NEGINF;
	int valRight = NEGINF;
	if(i != sizeo-1) 
		valDown = path(A,i+1,j);
	if(j != sizeo-1)
		valRight = path(A,i,j+1);
	//printf("\t(%d,%d),DiffDown and DiffRight are: %d, %d\n",i,j,diffDown,diffRight);
	//printf("\t(%d,%d),Valdown and Valright are: %d, %d\n",i,j,valDown,valRight);

	if(diffDown == valDown){
		S[i][j] = diffDown;
	}else if(diffRight == valRight){
		S[i][j] = diffRight;
	}else{
		S[i][j] = NEGINF;
	}
	//printf("at (%d,%d) Vale = %d. Best case = %d\n",i,j,A[i][j],S[i][j]);
	return S[i][j];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	initS(); 
	cin >> sizeo;
	for(int i = 0;i<sizeo;i++){
		for(int j =0;j<sizeo;j++){
			cin >> A[i][j];
		}
	}
	if(path(A,0,0) != NEGINF){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}

