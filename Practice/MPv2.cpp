//one test is not working
#include <iostream>
#include <cstdio>
#define N 105
#define X -1
using namespace std;
int A[N][N];
int S[N][N];//here -1:hasnt been visited, 0 not possible, 1 possible
int pos1;
int pos2;
int sizeo = 0;
//since there are only to outgoing paths from both the last corner and the first corner we only have two possible values to choose from.
//without loss of generality las voy escoger desde el ultimo ya que el primer y el ultimo van a tener uno de los outputs igual(si es que existe el monotonic path);
int path(int i, int j,int posDiff){
	if(S[i][j] != X){
		//printf("Returning memoized : #(%d,%d)=%d\n",i,j,S[i][j]);
		return S[i][j];
	}
	if(i == sizeo-1 && j == sizeo-1){
		//final corner 
		//printf("Reached Final Corner\n");
		S[i][j] = 1;
		return S[i][j];
	}
	//printf("w/D:%d ,@(%d,%d)=%d\n",posDiff,i,j,A[i][j]);
	//default values
	bool down, right,downPos,rightPos;
	down = right = downPos = rightPos = 0;
	if(i != sizeo-1){
		down = path(i+1,j,posDiff);
		downPos = ((A[i+1][j]-A[i][j] == posDiff) && (down == 1))? 1 : 0;
	}
	if(j != sizeo-1){
		right =	path(i,j+1,posDiff);
		rightPos = ((A[i][j+1]-A[i][j] == posDiff) && (right == 1))? 1 : 0;
	}
	S[i][j] = (downPos == 1 || rightPos == 1)? 1: 0;
	//printf("\t @(%d,%d)=%d Collective Deceision = %d\n",i,j,A[i][j],S[i][j]);
	return S[i][j];
}
void populateArrays(){
	cin >> sizeo;
	for(int i =0;i<sizeo;i++){
		for(int j = 0;j<sizeo;j++){
			S[i][j] = X;
			cin >> A[i][j];
		}
	}
}
int main(){
	populateArrays();
	pos1 = A[sizeo-1][sizeo-1] - A[sizeo-2][sizeo-1];
	pos2 = A[sizeo-1][sizeo-1] - A[sizeo-1][sizeo-2];	
	if(path(0,0,pos1) == 1){
		cout << "Yes"<<endl;
	}else if(path(0,0,pos2) == 1){
		cout << "Yes"<<endl;
	}else{
		cout << "No"<<endl;
	}

	return 0;
}
