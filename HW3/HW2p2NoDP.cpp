#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int sizeo = 0;
int count(string A,int i){
	int x = i-1;
	int y = i+1;
	int count = 1;
	while(x >= 0 && y<sizeo){
		if(A[x] == A[y]){
			count+=2;
		}else{
			break;
		}
		x--;
		y++;
	}
	return count;
}

int main(){
	
	string A;
	cin >> A;
	sizeo = A.length();
	for(int i =0;i< sizeo;i++){
		cout << count(A,i) << " ";
	}
	cout << endl;
	return 0;
}
