#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define N 1000

using namespace std;

string A;
//int S[N][N];
int sizeo  = 0;

void fillArray(int **S){
	for (int i = 0; i < sizeo; i++)
		S[i][i] = 1; 
	for(int L=2;L<=sizeo;L++){
		for(int i=0;i<sizeo-L+1;i++){
			int k = i+L-1;
			if(A[i] == A[k] && L == 2){
				S[i][k] = 2;
			}else if(A[i] == A[k]){
				S[i][k] = 2 + S[i+1][k-1];
			}else{
				S[i][k] = max(S[i+1][k],S[i][k-1]);
			}
		}
	}
}
void outPutFunc(){
	cout <<endl;
}
int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A;
	sizeo = A.length();
	int **S;
	S = new int*[sizeo];
	for(int i = 0;i<sizeo;i++)
		S[i] = new int[sizeo];
	//memset( A, '\0', sizeof(char)*N );
	//	memset( S,0, sizeof(int)*N*N);
	fillArray(S);
	for(int i = 0;i<sizeo;i++){
		int mino = min(i-0,(sizeo-1)-i);
		cout << S[i-mino][i+mino]<<" ";
	}
	cout << endl;

	return 0;
}
