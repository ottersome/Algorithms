#include "OJ.h"

#include <bits/stdc++.h>
bool update(int n, vector<Point> points);
// check whether current matching have intersection.
// remove the intersection by swap two line and return 1
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
using namespace std;

void naive(vector<Point> &points){
    int n = (int) points.size()/2;
    do{
        oj.set_match(points);
        display();
    } while ( update(n,points) );
}

void DC(vector<Point> &points){
    // boundary case (naive) ...

    vector<Point> sub1, sub2;
    partition(points,sub1,sub2);
    oj.set_match(sub1);
    oj.set_match(sub2);
    display();

    // D&C ...
}
