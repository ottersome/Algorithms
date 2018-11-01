#include "OJ.h"
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

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
				return true;
			}
		}
	}
	//if(counter == 0)
	//	return true;
	//que podemos tratar primero.... como es naive lo que podemos hacer es 
	return false;//TODO change this false for something appropiate
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
}
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

