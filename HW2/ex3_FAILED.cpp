#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
using namespace std;
int A[] = {1,3,5,2,5,1,4};
int S[21];//this is the array of all possible sums 
//this is ismilar to knapsack but wed dont care about check size of individual element because all
//elements have size = 1
int solve(int pointer, int capacity,int sumSoFar){//a and be represent the left and right limits of the subset
	printf("We have entered pointer=%d(%d), and capacity=%d,Finally sumSoFar=%d.\n",
			pointer,A[pointer],capacity,sumSoFar);
	cin.get();//stop until key pressed
	//base case
	//when we reach the base case we will the capacity left->
	//	since every element only represents weight 1 then 
	//	we will obtain the amount of elemnt not used
	//	thus we obtain the size of  array
	
	//since there is no more space or we have reached the last possible candidate
	//thus no more can be added we return 0; not affecting the last summation
	if(pointer == 0 || capacity == 0){
		printf("Just letting you know im here mato\n");
		return sumSoFar;
	}
	//else
	//call two funcitons
	//not considering this element
	int notConsidering = solve(pointer-1,capacity,sumSoFar+0);

	//considering this elemnet
	int considering  = solve(pointer-1, capacity-1,sumSoFar+A[pointer]);
	
	//we dont actually have to consider max here
	int result = max(notConsidering,considering);
	printf("We have considered both in the pointer=%d with capacity %d\nConsider=%d while notConsidering=%d\n\n",
			pointer,capacity,considering,notConsidering);
	cin.get();//stop until key pressed

	return result; //TODO fix that 0 to what it should be 
}
int firstCase(){
	
	//we have to consider both not taking in the first value and taking in the first value
	int sizeo = sizeof(A)/sizeof(A[0]);
	//we havent added anything yet so we pass 0 
	int considering = solve(sizeo-1,sizeo-1,0);//we consider the first value
	int notConsidering= solve(sizeo-1,sizeo,0);//we dont consider the first value->still have n open slots
	return max(considering,notConsidering);
}
int main(){
	firstCase();
	//R is a subset of S 
	//when we plug R in to w we get the sum of all elments in R
}
