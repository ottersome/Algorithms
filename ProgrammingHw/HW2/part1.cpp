#include <iostream>
#include <cstdio>

using namespace std;
int A[1005][1005];
int S[1005][1005];
int sizeo = 0;//will be the amonut ofin puts
int path(int i, int j){
	if(S[i][j] >= 0){
		return S[i][j];
	}
	int count = ;
	if(i==sizeo-1 && j==sizeo-1){
		return S[i][j] = 0;
	}
	if(i<sizeo-1){
		return S[i][j] = path(i,j+1);
	}
	if(j<sizeo-1){
		return S[i][j] = path(i+1,j);
	}
	S[i][j] = min(path(i+1,j),path(i,j+1);

	return 0;//TODO fix that
}
void getInputNPop(){
	cin >> sizeo;
	for(int i =0;i<sizeo;i++){
		for(int j =0;j<sizeo;j++){
			cin >> A[i][j];
			//fill S with -1
			S[i][j] = -1;
		}
	}

}
int main(){
	getInputNPop();

	return 0;
}
