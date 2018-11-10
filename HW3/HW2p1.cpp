#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
long long int A[1005][1005];
long long int S[1005][1005];
int sizeo =0;
void populateArray(){
	cin >> sizeo;
	for(int i = 0;i<sizeo;i++){
		for(int j = 0;j<sizeo;j++){
			S[i][j] = -1;//as to say its empty
			cin >> A[i][j];		
		}
	}
}
long long int path(int i,int j){
	//memoization
	if(S[i][j] != -1){
		return S[i][j];
	}
	//value to assign square
	//since the square give will be inverted upside down in the array, then we will traverse only up and right
	if(i >= sizeo-1 && j >= sizeo-1){
		return S[i][j] = 0;
	}
	long long int up = LLONG_MAX;
	long long int right = LLONG_MAX;
	if(i+1 <= sizeo-1){
		up = max(abs(A[i][j] - A[i+1][j]),path(i+1,j));
	}
	if(j+1 <= sizeo-1){
		right = max(abs(A[i][j] - A[i][j+1]),path(i,j+1));
	}
	int count = min(up,right);
	//printf("Up is : %llu\n\tWhile right is : %llu\n\tAnd count is : %llu\n",up,right,count);
	return S[i][j] = count;

}
int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	populateArray();
	long long int finalans = path(0,0);
	cout << finalans<<endl;
	return 0;
}
