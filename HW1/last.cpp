#include <iostream>
#include <cstdio>

using namespace std;
//int A[] = {-3,-2,1,3,4};
//int A[] = {-7,-6,-4,-2,-1,0,1,3,4,5,6};
int A[] = {-5,-4,-4,-3,-2,-1};
int sizeo = sizeof(A)/sizeof(A[0]);
void printArray(){
	cout << "Your array : {";
	for(int i =0;i<sizeo;i++){
		if(i != sizeo-1)
			cout <<A[i]<<",";
		else 
			cout <<A[i];
	}
	cout << "}"<<endl;
}
//scan for greatest negative numer
int gnni(){//greatest negative number integer
	int i =0,curNum = 0;
	do{
		curNum = A[i++];
	}while(A[i] < 0);
	return (i-1);
}
int main(){
	int k;
	printArray();
	cout << "Please input your number k : ";
	cin >> k;
	cin.ignore();
	int i,j;
	i = 0;
	j = gnni()+1;
	int tempo;
	if(k<0){
		while(i<=gnni() && j <= (sizeo-1)){
			//printf("Inspecting at i=%d j=%d posk=%d\n",i,j,(A[i]*A[j]));
			if(A[i] * A[j] == k){
				printf("Found at i=%d,j=%d its %d*%d\n",i,j,A[i],A[j]);
				break;
			}else{
				if(A[i+1] * A[j] <= k){
					i++;
				}else{
					j++;
				}
			}
		}
	}else{
		//now we inspect two young tables 
		//searching each young table takes O(m+n) making two tables 2O(m+n) still constant time
		//searching greatest negative number in linear time(linear scan)
		//search in table of positve products
		int i = gnni()+1;
		int j = sizeo-1;
		while(i <= sizeo && j >= 0){
			//printf("Inspecting at i=%d j=%d posk=%d\n",i,j,(A[i]*A[j]));
			if(A[i] * A[j] == k){
				printf("Found at i=%d,j=%d its %d*%d\n",i,j,A[i],A[j]);
				break;
			}else{
				if(A[i+1] * A[j] <= k){
					i++;
				}else{
					j--;
				}
			}		
			//cin.get();
		}
		//if not found as product of positive numbers then
		i =0;
		j = gnni();
		while(i <= gnni() && j>=0){
			if(A[i] * A[j] == k){
				printf("Found at i=%d,j=%d its %d*%d\n",i,j,A[i],A[j]);
				break;
			}else{
				if(A[i] * A[j-1] <=k){
					j--;
				}else{
					i++;
				} 
			}
		}

	}

	return 0;
}
