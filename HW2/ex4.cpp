#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;
int A[] = {2,3,5,6,11,13};
int solve(int pointer, int diff){

	//case case
	if(pointer == 0)
		return 0;
	//create two subproblems
	int considering = solve(pointer-1,diff);
	solve(pointer,diff);
	return 0;//TODO output appropiate value
}

int firstRun(){
	int sizeo = sizeof(A)/sizeof(A[0]);
	solve(sizeo,diff);
	int maxo = 
	return ;
}
int main(){



	return 0;
}
