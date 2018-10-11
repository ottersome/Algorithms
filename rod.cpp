#include <iostream>
#include <cstdio>

using namespace std;
int prices[] = {2,5,6};
int sizeo = sizeof(prices)/sizeof(prices[0]);
int rod_cutting(int size){
	int maxRevenue = prices[size];//prize of entered size
	for(int i =1;i< size-1;i++){
		if(prices[size] + rod_cutting(size-1) > maxRevenue){
			maxRevenue = prices[i] + rod_cutting(size-1);
		}
	}
	return maxRevenue;
}
int main(){
	
	for(int i = 0;i <sizeo;i++){
		
	}

}
