#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>

using namespace std;
int A[10] ={4,6,23,7,8,21,3,2,94,12};
//int A[10] = {10, 80, 30, 90, 40, 50, 70};
int partition(int *suba,int p, int q){
	int temp =0;
	int pivot = suba[q];//last element of the give array or subarrray
	int i = p-1;//index of the smaller element;
	cout << "Value of i is : "<<i<<endl;
	//este i es el que va a ir incrementando en lo uqe vamos haciendo s mas grande
	//es como la linea entre S y L
	cout << "Values of p and q-1 : "<<p<<" "<<q<<endl; 
	//you never move pivot until the last move where S and L are completely defined
	for(int j = p;j<q-1;j++){
		if(suba[j] <= pivot){
			//exchange 
			i++;
			//cout <<"\t new value of i : "<<i<<endl;
			//exchange suba[i] and suba[j] for making it consecutive
			temp = suba[i];
			suba[i] = suba[j];
			suba[j] = temp;
		}
	}
	cout << " i get out "<<endl;
	temp = suba[i+1];
	suba[i+1] = pivot;
	suba[q] = temp;
	return i+1;
}
void quicksort(int *loca,int p, int q){
	if(q > p){
		int k = partition(loca,p,q);//the index where we cut it, or pivot(?)
		quicksort(loca,p,k-1);
		quicksort(loca,k+1,q);
	}
}
int main(){
	int sizeArr = sizeof(A)/sizeof(int);
	quicksort(A,0,sizeArr-1);
	cout << "Outputting your sorted Array :"<<endl;
	for(int i  =0;i<sizeArr-1;i++){
		printf("At index %d, we have %d\n",i,A[i]);
	}

	return 0;
}
