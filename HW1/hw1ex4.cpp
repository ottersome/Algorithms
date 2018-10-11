#include <iostream>
#include <cstdio>
using namespace std;
int A[] = {-3,-2,0,1,2,5,9,12,16,23,51,74};
int k = 5;
int main(){

	cout << "Please enter your k:";
	cin >> k;
	
	int intArrSize = sizeof(A)/sizeof(int);
	for(int i = 0;i < intArrSize;i++){
		cout << "i="<<i<<endl;
		if(0 != A[i]){
			//since it is not zero we can divide by zero 
			if((k/A[i] >= A[i]) && (k/A[i] <= A[intArrSize-1])){
				for(int j = i;j<intArrSize;j++){
					cout << "j="<<j<<endl;
					if(A[i] * A[j] == k)
						printf("These are your values my boi : %d * %d \nIn indexes i=%d,j=%d\n",A[i],A[j],i,j);
				}

			}
		}else{
			if(k==0){
				cout << "Any number will do "<<endl;	
			}
		}
	}
	cout << "None where found amigo"<<endl;
	return 0;
}
