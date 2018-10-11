#include <iostream>
#include <cstdio>

using namespace std;

//int arrayo[] = {2,3,5,9,10,13,16,19};
int arrayo[] = {1,1,1,1,1,1,1,1,1};
int binarySearch(int arr[],int searchFor,int l,int r){
	if(r-l!=1){
		int m = l+((r-l)/2);
		if(searchFor > arr[m]){
			binarySearch(arr,searchFor,m+1,r);
		}else if(searchFor <= arr[m]){
			binarySearch(arr,searchFor,l,m);
		}	
	}else{
		if(searchFor == arr[r]){
			cout << "Its : index"<<r<<endl;
		}else{
			cout << "Its : index"<<l<<endl;
		}
	}
	return 0;
}
void printArray(int arr[],int sizeo){
	for(int i =0;i < sizeo;i++){
		cout <<arr[i]<<" ";
	}
	cout <<endl;
}
int main(){
	int sizeo = sizeof(arrayo)/sizeof(arrayo[0]);
	printf("Please write the element you want two write among:\n");
	printArray(arrayo,sizeo);
	int searchFor = 0;
	cin >> searchFor;

	binarySearch(arrayo,searchFor,0,sizeo-1);
return 0;
}
