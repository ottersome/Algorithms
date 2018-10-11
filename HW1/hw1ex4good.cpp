#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//int arrayo[] = {-3,-2,1,3,4};
//int arrayo[] = {-7,-6,-4,-2,-1,0,1,3,4,5,6};
int arrayo[] = {-5,-4,-4,-3,-2,-1};


int multiplayo[100][100];
int sizeo =0;

void printMultiplayo(){	
	cout << "Sizeo es " <<sizeo<<endl;
	for(int i=0;i<sizeo;i++){
		for(int j=0;j<sizeo;j++){
			printf("[%5d]",multiplayo[i][j]);
		}
		cout <<endl;

	}
}
void populate(int small[],int sizeSmall,int k){
	for(int i =0;i<sizeSmall;i++){
		for(int j=0;j<sizeSmall;j++){
			//multiplayo[i][j] = (floaty==floor(k/small[j])) ? floor(floaty) : -62;
			multiplayo[i][j] = small[i] * small[j];
		}
	}
}
void search(int k){
	int i,j;
	i = j = sizeo-1;//we start at the lower corner 
	cout << "I and jare : "<<i<<endl;
	while(i > 0 && j>0){
		printf("Inspecting at multiplayo[%d][%d]\n",i,j);
		if(multiplayo[i-1][j] >= k){
			if(multiplayo[i-1][j] == k){
				printf("Found A[%d][%d] = %d\n",i-1,j,multiplayo[i-1][j]);
				break;
			}
			i--;
			continue;
		}else{
			if(multiplayo[i][j-1] == k){
				printf("Found A[%d][%d] = %d\n",i,j-1,multiplayo[i][j-1]);
				break;
			}
			j--;
		}
	}
}
int main(){
	sizeo =sizeof(arrayo)/sizeof(arrayo[0]);
	populate(arrayo,sizeo,4);
	printMultiplayo();
	//search(2);
	
}
