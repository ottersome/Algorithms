#include <iostream>
#include <cmath>

using namespace std;
int heap[] = {1,32,42,12,3,41,28,31,52,23,51,2};
int sizeo = 0;
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int left(int i){
	return i*2;
}
int right(int i ){
	return (i*2)+1;
}
int layersTree(int num){
	return (log(num)/log(2)) + 1;
}
void maxHeapify(int maxheap[],int index){
	int largest = index;
	if(maxheap[index] < maxheap[left(index)]){
		largest = left(index);
	}else if(maxheap[index] < maxheap[right(index)]){
		largest = right(index);
	}
	if(largest != index){
		swap(maxheap[largest],maxheap[index]);
		maxHeapify(maxheap,largest);
	}
}

void buildMaxHeap(int maxheap[],int index){
	if(layersTree(index) < layersTree(sizeo)){
		printf("We are inside with index : %d\n",index);
		//since the conditition to heapify is for the left and right subtress
		//to already be max heaps we then need to make sure that we begin from 
		//the leaves to build max heaps and then if the upper branches need we 
		//recurse
		buildMaxHeap(maxheap,left(index));
		buildMaxHeap(maxheap,right(index));

		maxHeapify(maxheap,index);
	}
}
void heapsort(int maxheap[],int r){
	buildMaxHeap(maxheap,1);
	for(int i = r;i>= 1;i--){
		swap(maxheap[1],maxheap[r]);
		maxHeapify(maxheap,1);
	}
}
void printByLayers(int heapo[],int sizeo){
	int curLayer = layersTree(0);
	for(int i  =0;i<sizeo;i++){
		if(curLayer != layersTree(i)){
			cout <<endl;
			curLayer = layersTree(i);
		}
		cout << heapo[i]<<" ";
		
	}
	cout <<endl;
}
int main(){
	//since a heap is a binary tree im guessing we can calculate its height
	//by logn thus
	//Calculate height of tree:
	sizeo = sizeof(heap)/sizeof(heap[0]);
	int height = layersTree(sizeo);
	cout << "The height of your array is : "<<height<<endl;
	cout << "Outputting current binary tree : "<<endl;
	printByLayers(heap,sizeo);
	//now order it
	heapsort(heap,sizeo-1);
	//Ill finish it later
	printByLayers(heap,sizeo);

return 0;
}
