#include "OJ.h"
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
struct pointLoc{//simply used to determine if the point is the left or right endpoint
	Point point;
	Point* correspLeft = NULL;//will be null if this pointLoc is left itselft
	int index;//this describes the pair it belongs to (i,n+i)
	Line correspondingLine;
};
struct LineNode
{
	long long key;//y value of left endpoint
	//blue is default
	pointLoc * pl_ptr;
	struct LineNode *left, *right;
	int height;
};
int max(int a,int b){return (a > b)? a : b;}
// A utility function to create a new BST node
/*struct LineNode *newNode(int item,Line line)
  {
  struct LineNode *temp =  (struct LineNodE *)malloc(sizeof(struct LineNode));
  temp->key = item;
  temp->line = line;
  temp->left = temp->right = NULL;
  return teNmp;
  }*/
struct LineNode* newNode(int key,pointLoc * line) 
{ 
	struct LineNode* node = (struct LineNode*) 
		malloc(sizeof(struct LineNode)); 
	node->key   = key; 
	node->left   = NULL; 
	node->right  = NULL; 
	node->pl_ptr = line;
	node->height = 1;  // new node is initially added at leaf 
	return(node); 
} 
int height(struct LineNode *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 
// A utility function to do inorder traversal of BST
void inorder(struct LineNode *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}

struct LineNode *rightRotate(struct LineNode *y)
{
	struct LineNode *x = y->left;
	struct LineNode *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct LineNode *leftRotate(struct LineNode *x)
{
	struct LineNode *y = x->right;
	struct LineNode *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	//  Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct LineNode *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct LineNode* insert(struct LineNode* node, int key,pointLoc * line)
{
	/* 1.  Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key,line));

	if (key < node->key)
		node->left  = insert(node->left, key,line);
	else if (key > node->key)
		node->right = insert(node->right, key,line);
	else {// Equal keys are not allowed in BST
		//Doesnt happen in test cases 
		printf("Equeal keys found\n");
		return node;
	}
	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
			height(node->right));

	/* 3. Get the balance factor of this ancestor
	   node to check whether this node became
	   unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left =  leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	/* return the (unchanged) node pointer */
	return node;
}
struct LineNode * minValueNode(struct LineNode* node)
{
	struct LineNode* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}
struct LineNode* deleteNode(struct LineNode* root, int key)
{
	//printf("\tEntering with key: %d\n",key);
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == NULL)
		return root;
	//printf("\t\tContinues...\n");
	// If the key to be deleted is smaller than the
	// root's key, then it lies in left subtree
	if ( key < root->key )
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the
	// root's key, then it lies in right subtree
	else if( key > root->key )
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == NULL) || (root->right == NULL) )
		{
			struct LineNode *temp = root->left ? root->left :
				root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
				*root = *temp; // Copy the contents of
			// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			struct LineNode* temp = minValueNode(root->right);

			// Copy the inorder successor's data to this node
			// temp is the inorder successor
			//height no se compia porque estamos asignandole un nuevo valor al mismo lugar(height)
			root->key = temp->key;
			root->pl_ptr = temp->pl_ptr;//I THINK this should be right
			//why would you delete the inorder successor ?
			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
		return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),
			height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left =  leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}
/* A utility function to insert a new node with given key in BST */
void findPreSuc(LineNode* root, LineNode*& pre, LineNode*& suc, int key)
{
	// Base case
	if (root == NULL){
		cout << "Root is null "<<endl;
		return ;
	}

	// If key is present at root
	if (root->key == key)
	{
		// the maximum value in left subtree is predecessor
		if (root->left != NULL)
		{
			LineNode* tmp = root->left;
			while (tmp->right)
				tmp = tmp->right;
			pre = tmp ;
		}

		// the minimum value in right subtree is successor
		if (root->right != NULL)
		{
			LineNode* tmp = root->right ;
			while (tmp->left)
				tmp = tmp->left ;
			suc = tmp ;
		}
		return ;
	}

	// If key is smaller than root's key, go to left subtree
	if (root->key > key)
	{
		suc = root ;
		findPreSuc(root->left, pre, suc, key) ;
	}
	else // go to right subtree
	{
		pre = root ;
		findPreSuc(root->right, pre, suc, key) ;
	}
}
void deleteTree(struct LineNode* node)
{
	if (node == NULL) return;
	//printf("Deteting subroot : %d\n",node->key);
	/* first delete both subtrees */
	deleteTree(node->left);
	deleteTree(node->right);

	/* then delete the node */
	//printf("\n Deleting node: %d", node->data);
	free(node);
}
struct LineNode *root = NULL; 
void swapGivenLines(int n,vector<Point> & points, int i,int j){
	printf("Switching indeces i=%d,j=%d\n\t (x,y)=%d,%d and\n\t (x,y)=%d,%d\n",n+i,n+j,points[n+i].x,points[n+i].y,points[n+j].x,points[n+j].y);
	//drawPoint(lineLineIntersection(points[i],points[n+i],points[j],points[n+j]));
	Point tempo = points[n+i];
	points[n+i] = points[n+j];
	points[n+j] = tempo;

	//cin.get();
	oj.set_match(points);

}
bool sortVecs(pointLoc a,pointLoc b){return (a.point.x< b.point.x)? true: false;}//working perfectly fine
bool update(int n,vector<Point> & points,int caseno){//TODO remove caseno as prameter
	//use sweeping line since point struct already 
	//printf("Point ingresados son : \n");
	/*for(int i =0;i<n;i++){
		printf("Here : (%d,%d) with (%d,%d) with indices:%d,%d\n",points[i].x,points[i].y,points[n+i].x,points[n+i].y,i,n+i);
	}*/
	printf("Counter is : %d\n",caseno);
	vector<pointLoc> pointloc = vector<pointLoc>(n*2);
	for(int i =0;i<n;i++){//lets arbitarly decide the the lines are formed by points (i,n+i)
		Line theirLine = {points[i],points[n+i]-points[i]};
		if(points[i].x < points[n+i].x){
			pointloc[i] = {points[i],NULL,i,theirLine};
			pointloc[n+i] = {points[n+i],&points[i],i,theirLine};
		}else{//if(points[i].x > points[n+i].x):
			pointloc[i] = {points[i],&points[n+i],i,theirLine};
			pointloc[n+i] = {points[n+i],NULL,i,theirLine};
		}
	}
	//now sort pointLoc from left to right
	std::sort(pointloc.begin(),pointloc.end(),sortVecs);//O(nlogn)
	for(int i = 0;i<n*2;i++){//this is working perfecty fine
		//printf("Pos %d ->\t x=%d, y=%d \n",i,pointloc[i].point.x,pointloc[i].point.y);
	}
	//now that everything is sorted we may proceed to use sweeping line
	for(int i = 0;i<n*2;i++){
		//values of insertion are correct
		display();
		printf("We are visiting with index :%d\n",i);
		string testo = (pointloc[i].correspLeft == NULL)?" This is a lefty":"This is a right";
		cout << "For the next one: "<<testo<<endl;
		if(pointloc[i].correspLeft == NULL){
			pointLoc * ptre = &pointloc[i];
			root = insert(root,pointloc[i].point.y,ptre);//INSERT HERE 
			LineNode * pre = NULL;
			LineNode * suc = NULL;
			findPreSuc(root, pre, suc, pointloc[i].point.y); 
			printf("pointloc index : %d,(%d,%d), from : is(%d,%d)->(%d,%d)\n",i,pointloc[i].point.x,pointloc[i].point.y,points[pointloc[i].index].x,points[pointloc[i].index].y,points[n+pointloc[i].index].x,points[n+pointloc[i].index].y);
			Line linen = {points[pointloc[i].index],points[n+pointloc[i].index]-points[pointloc[i].index]};
			if(pre!=NULL){
				printf("Displaying predecessor\n");
				oj.displayPoint(pre->pl_ptr->point,1,1,0);//yellow for predecessor BELOW
			}
			if(suc!=NULL){
				printf("Displaying sucessor\n");
				oj.displayPoint(suc->pl_ptr->point,0.9,0.7,0);//oragey for successor ABOVE
			}
			oj.displayPoint(pointloc[i].point,0,1,0);//TODO remove
			if(caseno == 10){
				//cin.get();
			}
			//Debugging
			//testo
			if(pre != NULL){
				if(intersection(pointloc[i].correspondingLine,pre->pl_ptr->correspondingLine)){//CHECK FOR INTERSECTIONS WITH PREDECESSORS HERE
					//swap
					printf("Swap between new and predecessor\n");
					printf("New.y is %d, and predecessor.y is %d\n",pointloc[i].point.y,pre->pl_ptr->point.y);
					int a = pointloc[i].index;
					int b = pre->pl_ptr->index;
					//printf("Before switch with : %d,%d\n",a,b);
					cout << "Insideo"<<endl;
					cout << "Log counter pt2: "<<i<<endl;
					swapGivenLines(n,points,a,b);
					return true;
				}
			}
			if(suc != NULL){
				if(intersection(pointloc[i].correspondingLine,suc->pl_ptr->correspondingLine)){
					printf("Swap between new and successor\n");
					printf("New.y is %d, and successor.y is %d\n",pointloc[i].point.y,suc->pl_ptr->point.y);
					int a = pointloc[i].index;
					int b = suc->pl_ptr->index;
					swapGivenLines(n,points,a,b);
					return true;
				}
			}
		}else{
			//get y key for getting the respective line and deleting it
			LineNode * pre = NULL;
			LineNode * suc = NULL;
			findPreSuc(root, pre, suc, pointloc[i].correspLeft->y); 
			printf("We are here and we want to delete : %d\n",pointloc[i].correspLeft->y);
			oj.displayPoint(pointloc[i].point,0,1,0);//TODO remove
			if(caseno == 10){
				//cin.get();
			}
			if(suc!=NULL && pre!=NULL){//is right means we must delete one fo the points because no intersewction was found
				if(intersection(pre->pl_ptr->correspondingLine,suc->pl_ptr->correspondingLine)){
					printf("Swap between predecessor and successor\n");
					printf("pre.y is %d, and successor.y is %d\n",pre->pl_ptr->point.y,suc->pl_ptr->point.y);
					int a = pre->pl_ptr->index;
					int b = suc->pl_ptr->index;
					swapGivenLines(n,points,a,b);
					return true;
				}
			}
			root = deleteNode(root,pointloc[i].correspLeft->y);
		}
		cout << "************************************************************"<<endl;
	}
	return false;
}
void naive(vector<Point> &points){
	//sort points
	//gotta flag blue and red points
	int n = (int) points.size()/2;
	int counter =0;
	oj.set_match(points);
	display();
	while (update(n,points,counter)){
		display();
		printf("Case number : %d\n",counter++);
		deleteTree(root);
		root =NULL;
	} 
	cout << "Assigning now "<<endl;
	oj.set_match(points);
}
/*
   BUENO
   bool update(int n, vector<Point> points,vector<int> & match){
//First: Check for intersections
Line curPoint;
//create iterator
//i think we can assume that here i connects to n+i
//vector<Line> linesi(n);
//vector<Line> linesj(n);
vector<Line> lines(n);
int counter =0;
for (int i=0; i<n; i++){
lines[i] = { points[i], points[n+match[i]]-points[i] };
}
for (int i=0; i<n; i++){
for (int j=i+1; j<n; j++){
if ( intersection( lines[i], lines[j] ) ){
//switch them up
int tempo = match[i];
match[i] = match[j];
match[j] = tempo;
oj.set_match(i,match[i]);
oj.set_match(j,match[j]);
counter++;
}
}
}
if(counter == 0)
return false;
//if(counter == 0)
//	return true;
//que podemos tratar primero.... como es naive lo que podemos hacer es 
return true;//TODO change this false for something appropiate
}
// check whether current matching have intersection.
// if no intersection return 0

void partition( vector<Point> &points,
vector<Point> &sub1,
vector<Point> &sub2
);
// find one straight line
// points on one side store in vector sub1
// points on the other side store in vector sub2
// points on the straight line store in vector points
//
// A = { (0,0)(1,2,),(7,10),(2,1),(10,7) |
//           (1,1),(3,4),(6,9),(4,3),(9,6) }
// B = C = { }
// after partition(A,B,C);
// A = { (0,0)|(1,1) } // line (0,0) -> (1,1)
// B = { (1,2),(7,10) | (3,4),(6,9) }
// C = { (2,1),(10,7) | (4,3),(9,6) }
void naive(vector<Point> &points){
int n = (int) points.size()/2;
int counter =0;
oj.set_match(points);
vector<int> match = vector<int>(n);
int updateCounter =0;
for(int i =0;i<n;i++){
match[i] = i;//defautl state
}
do{
//oj.set_match(points);
display();
printf("On counter : %d.\n",++updateCounter);
} while ( update(n,points,match) );
}*/
/*
   void DC(vector<Point> &points){
// boundary case (naive) ...
vector<Point> sub1, sub2;
partition(points,sub1,sub2);
oj.set_match(sub1);
oj.set_match(sub2);
display();
//two partitions for two subproblems called 
// D&C ...
}*/
//El debugging
		/*if(pre!=NULL){
		  Line linep ={points[pre->pl_ptr->index],points[n+pre->pl_ptr->index]-points[pre->pl_ptr->index]};
		  string stringo = (intersection(linen,linep))? "Do intersect" : "Dont intersect";
		  cout << "This brobeans "<<stringo<<endl;
		//printf("\t With indices n=%d,p=%d\n",pointloc[i].index,pre->pl_ptr->index);
		}
		if(suc!=NULL){
		Line linesuc = {points[suc->pl_ptr->index],points[n+suc->pl_ptr->index]-points[suc->pl_ptr->index]};
		string stringo = (intersection(linen,linesuc))? "Do intersect" : "Dont intersect";
		cout << "In terms of successor, The "<<stringo<<endl;
		//printf("\t With indices n=%d,p=%d sucesor being:(%d,%d)\n",pointloc[i].index,suc->pl_ptr->index,points[suc->pl_ptr->index].y,points[n+suc->pl_ptr->index].y);
		}*/

