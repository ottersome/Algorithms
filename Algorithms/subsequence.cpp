#include <iostream>
#include <string>
#include <math.h>
#include <cstdio>
char A[] = "zscadacs";
char B[] = "aadzbcda";
int static const sizeo = sizeof(A)/sizeof(A[0]);
char Z[sizeo];
int zcounter = 0;
using namespace std;
void printArray(char arr[], int size){
	cout << "Your array is : {";
	for(int i = 0; i < size;i++){
		//string reto = (i == size-1) ? arr[i]+"" : arr[i]+",";
		cout << A[i];
	}
	cout << "}"<<endl;

}
int LCS(int a,int b){
	if(a == 0||b==0) return 0;
	int max_length = 0;
	printf("Inspecting A[a]=%c and B[b]=%c \n",A[a],B[b]);

	//si tenemos un match 
	if(A[a] == B[b]){
		max_length = 1 + LCS(a-1,b-1);
		//Z[zcounter++] = A[a];//or A[b] regardless
	}else{
		max_length = max(LCS(a-1,b),LCS(a,b-1));
	}
	return max_length;

}
int main(){

	int Asize = sizeof(A)/sizeof(A[0]);
	int Bsize = sizeof(B)/sizeof(B[0]);
	
	cout << "Running A-1"<<endl;
	LCS(Asize-1,Bsize);
	cout << "Running B-1"<<endl;
	LCS(Asize,Bsize-1);

	//int resulto = LCS(Asize,Bsize);
	//printf("The largest is : %d\n",resulto);
	//printArray(Z,sizeo);
	return 0;
}
