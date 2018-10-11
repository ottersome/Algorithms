#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;
static const int A[10] = {4,6,23,7,8,21,3,2,94,12};
vector<int> intArray(A,A+(sizeof(A)/sizeof(A[0])));
int counter = 0;
char temp;
void random_select(int k,vector<int> &locA){
	cout << "Running random_select for the "<<++counter<<"th Time"<<endl;
	srand(time(NULL));
	//particionaos esto 
	vector<int> S,L;
	int sizeo = locA.size();
	int pivot = rand() %(sizeo);
	int valuePiv = locA[pivot];

	cout << "Random pivot is : "<<pivot<<" With value : "<<valuePiv<<endl;
	cout << "This is the size "<<sizeo<<" With k : "<<k<<endl;
	
	for(int i =0;i<sizeo;i++){
		if(i == pivot)
			continue;
		if(locA[i] <= valuePiv){
			S.push_back(locA[i]);
		}else{//locA[i] > valuePiv
			L.push_back(locA[i]);
		}
	}
	//con nuestro pivot ya selectcionado sacamos los L partition 
	//if k = the number of elements = 
	cin >> temp;
	if(sizeo==1){
		cout << "This is the value : "<<locA[0]<<endl;
	}else{
		if(pivot == S.size()){
			cout << "K=size, outputing pivot "<<locA[pivot]<<endl;
		}else if(pivot < S.size()){
			random_select(k,S);
		}else{//The number we want to find is greater then 
			random_select(pivot-S.size(),L);

		}
	}
}
int main (){

	random_select(5,intArray);
	return 0;
}
