//Verified to work por tu papi rico 
#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
bool getArray();
//void merge(int arr[],int,int,int);
//void mergeSort(int arr[],int,int);
void merge(int arr[],int l,int m,int r){
	//l m and r stand for the lowest index, middle and last index
	//our two subarrays will be divided in subA[l...m] nad subB[m+1..r]
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;


	int A[n1],B[n2];
	//copy the data from the original array to the new one
	for(i= 0;i<n1;i++)
		A[i] = arr[l+i];
	for(j = 0;j<n2;j++)
		B[j] = arr[m+1+j];
	i = j = 0;
	k =l;
	//we willl now merge t into the new array 
	while(i < n1 && j < n2){
		if(A[i] <= B[j]){
			arr[k] = A[i];
			cout << "Inserting : "<<A[i]<<endl;
			i++;
		}else{
			arr[k] = B[j];
			cout << "Inserting : "<<A[j]<<endl;
			j++;
		}
		k++;
	}
	//if there remains any elements in i or j we copy them 
	//at this point either i or j hit their limit
	//if j hit its limit -> i didnt so we do this while loop
	//otherwise se skip and do the while loop for k 
	while(i < n1){
		arr[k] = A[i];
		k++;
		i++;
	}
	while(j < n2){
		arr[k] = B[j];
		j++;
		k++;
	}

	cout << "We here bois "<<endl;
}
void mergeSort(int arr[],int l,int r){
	    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
/*	if(r>l){
		cout << "Fuck youuu"<<endl;
		//this function will take an array and divide it into two.
		//call itself for the other two mids 
		//and finally call megesort
		//the arrays where they already have two arrays will be the first ones to 
		//call sort in the stack. The rest as stack logic goes will follow to be 
		//sorted
		int m = l+((r-l)/2);
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);

		merge(arr,l,m,r);
	}*/
}
int main(){
	
	//printf("Please enter every element of the earray separated by spaces.\nWhen you are done please press enter");
	//getArray();
	//now do the mergesort thingy 
	//int arrayo[] = {2,31,23,51,25,1,5,123,64,65,345,26};
	int arrayo[] = {12, 11, 13, 5, 6, 7};
	int sizeo = sizeof(arrayo)/sizeof(int);
	mergeSort(arrayo,0,sizeo-1);//recorda que este es el default way de pasar un array como pointer a una funcion 
	//print that bitch
	for(int i = 0;i<sizeo;i++){
		printf("Element no.%d: %d\n",i,arrayo[i]);
	}
	return 0;
}/*
bool getArray(){
	int temp = 0;
	char inputo[100];
	cin.getline(inputo,100);
	stringstream ss(inputo);
	while(ss >> temp && !ss.eof()){
		arrayo[counter++] = temp;
	}
	return true;
};*/
