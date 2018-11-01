#include "OJ.h"
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

bool update(int n,vector<Point> & points){
	bool flag = 0;
	vector<Line> lines = vector<Line>(n);
	for(int i = 0;i<n;i++){
		lines[i] = {points[i],points[n+i]-points[i]};
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			//create lines
			if(intersection(lines[i],lines[j])){
				flag = 1;
				swap(points[n+i],points[n+j]);
				lines[i] = {points[i],points[n+i]-points[i]};
				lines[j] = {points[j],points[n+j]-points[j]};
			}
		}
	}
	return flag;
}
long long crossProduct(Point a,Point b, Point p){
	long long determinant  = ((p.x-a.x)*(b.y-a.y))-((b.x-a.x)*(p.y-a.y));
	return determinant;//this should mean p is to the right of AB
}
void partition(vector<Point> &points,vector<Point> &sub1, vector<Point> &sub2){
	int n = points.size()/2;
	vector<int> sub1Reds,sub1Blues;
	vector<int> sub2Reds,sub2Blues;
	Point A,B,P;
	for(int i = 0;i < n;i++){
		//check all points 
		A.x = points[i].x;
		A.y = points[i].y;
		B.x = points[n+i].x;
		B.y = points[n+i].y;
		for(int j = 0;j<n;j++){
			Point red = {points[j].x,points[j].y};
			Point blue = {points[n+j].x,points[n+j].y};
			long long cPR = crossProduct(A,B,red);
			long long cPB = crossProduct(A,B,blue);
			if(cPR > 0){
				sub2Reds.push_back(j);
			}else if(cPR<0){ 
				sub1Reds.push_back(j);
			}
			if(cPB > 0){
				sub2Blues.push_back(n+j);
			}else if(cPB<0){
				sub1Blues.push_back(n+j);
			}
			if(cPR == 0){//i believe this also means cPB equals zero
				//we dont add to any of the other sides
			}
			//check both points
		}
		if(sub1Reds.size() == sub1Blues.size()){//meaning the same for the other side
			sub1.clear();
			sub2.clear();
			int sub1LS = sub1Reds.size();
			int sub2LS = sub2Blues.size();
			int j =0;
			for(j =0;j<sub1LS;j++){
				sub1.push_back(points[sub1Reds[j]]);
			}
			for(j = 0;j<sub1LS;j++){
				sub1.push_back(points[sub1Blues[j]]);
			}
			for(j =0;j<sub2LS;j++){
				sub2.push_back(points[sub2Reds[j]]);
			}
			for(j =0;j<sub2LS;j++){
				sub2.push_back(points[sub2Blues[j]]);
			}
			//now for points
			points.clear();
			points.push_back(A);
			points.push_back(B);
			return;
		}
		//clean vectors
		sub1Reds.clear();
		sub1Blues.clear();
		sub2Reds.clear();
		sub2Blues.clear();

	}
	//now check sub1 sub2 and points

}
void naive(vector<Point> &points){
	int n = (int) points.size()/2;
	int counter =0;
	oj.set_match(points);
	while (update(n,points));
	oj.set_match(points);
	display();
}
void DC(vector<Point> &points){
	int n = (int) points.size()/2;//basically number of lines = or number of rats
	if(n <= 2000){//como tenes que hacer swap me imagino que talvez dos lineas 
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
