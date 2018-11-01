#include "OJ.h"

#include <bits/stdc++.h>
using namespace std;

struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
bool update(int n,vector<Line> lines){
	//First: Check for intersections
	//create iterator
	//i think we can assume that here i connects to n+i
	//vector<Line> linesi(n);
	//vector<Line> linesj(n);
	int counter = 0;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if ( intersection(lines[i], lines[j] ) ){
				//switch them up
				Point tempo = lines[i].v;
				lines[i].v = lines[j].v;
				lines[j].v = tempo;
				cout << "Changing"<<endl;
				counter++;
			}
		}
	}
	if(counter > 0)
		return true;
	cout << "Donde with one update"<<endl;
	//que podemos tratar primero.... como es naive lo que podemos hacer es
	return false;//TODO change this false for something appropiate
}
void naive(vector<Point> &points){
	int n = (int) points.size()/2;
	int counter =0;
	oj.set_match(points);
	vector<Line> lines = vector<Line>(n);
	for(int i =0;i<n;i++){
            lines[i] = { points[i], points[n+i]-points[i]};	
	}
	do{
		display();
	} while ( update(n,lines) );
	vector<Point> newPoints = vector<Point>(n*2);
	for(int i =0;i<n;i++){
		newPoints[i] = lines[i].p;
		newPoints[n+i] = lines[i].v;
	}
	oj.set_match(newPoints);
}

void DC(vector<Point> &points){
	// boundary case (naive) ...V
	//check for size
	int n = (int) points.size()/2;//basically number of lines = or number of rats
	if(n <= 1000){//como tenes que hacer swap me imagino que talvez dos lineas 
		naive(points);
		return;
	}
	//else
	vector<Point> sub1, sub2;
	partition(points,sub1,sub2);
	oj.set_match(points);
	oj.set_match(sub1);
	oj.set_match(sub2);
	display();

	// D&C ...
	DC(sub1);
	DC(sub2);
}
