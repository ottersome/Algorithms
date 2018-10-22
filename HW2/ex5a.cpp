#include <iostream>
#include <cstdio>

using namespace std;
int curCount = 0;
int mode = 0;
int getMax(int arr[],int sizeo){//O(n)
	int mx = arr[0];
	for(int i = 1;i < sizeo;i++){
		if(arr[i] > mx)
			mx = arr[i];
	}
	return mx;
}
void countSort(int arr[],int n, int exp){
	
	int output[n];//output array 
	int i , count[10] = {0};
	//store occurences in our counting arrya 
	for(i = 0;i<n;i++){//O(n)
		count[(arr[i]/exp)%10]++;
	}
	//add previous entries
	for(i = 1;i<10;i++){
		count[i] += count[i-1];
	}
	for(i = n-1;i>=0;i--){
		output[count[(arr[i]/exp)%10]-1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(i = 0;i < n;i++){
		arr[i] = output[i];
	}
}

void radixSort(int arr[],int sizeo){
	//get max number for the largetst number of counting array 
	int m = getMax(arr,sizeo);
	for (int exp = 1;m/exp > 0;exp*= 10){//loop through eveyr n umber
		countSort(arr,sizeo,exp);//exp is the current factor of 10 that divides into digits
	}
}
int main(){
	
	int amount;
	printf("Please input the amount of numbers youll input: ");
	cin >> amount;
	int * arrayo = new int[amount];

	for(int i =0;i<amount;i++){
		cin >> arrayo[i];
	}

	int sizeo = amount;
	printf("This is our unsorted array : \n");
	for(int i =0;i < sizeo;i++){//output sorted array 
		cout << arrayo[i] << " ";
	}
	radixSort(arrayo,sizeo);
	printf("\nThis is our sorted array : \n");

	int prevMode = -1;
	int prevCount =-1 ;
	int possmode = arrayo[0];
	int possCount = 1;
	for(int i = 0;i<sizeo;i++){
		cout << arrayo[i] << " ";
	}
	cout <<endl;
	for(int i =1;i < sizeo;i++){//output sorted array 
		printf("prevMode = %d while arrao[%d] = %d\n",prevMode,i,arrayo[i]);
		if(possmode != arrayo[i] || (i ==sizeo-1 && possmode!= arrayo[i])){
			if(prevCount < possCount){
				prevMode = possmode;
				prevCount = possCount;
			}
			possmode = arrayo[i];
			possCount = 1;
		}
		if(possmode == arrayo[i])
			possCount++;
	}
	printf("This is prevMode : %d\n",prevMode);
	//now that the array is sorted we analyze it
	cout<<endl;
	return 0;
}
