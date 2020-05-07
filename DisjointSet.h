#pragma once
//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: MST using Kruskal's Algorithm
//this is the Disjoint Set class header file to make sure the Kruskal's Algorithm does not form loops in the tree

#include "Vertex.h"
//class object to represent the DisjointSet class
class DisjointSet {
public:

	//performs a union operation on the disjoint sets of x and y
	//x and y are vertices in the graph
	//returns true if the the disjoint set that x resides in is different than that of y after unioning
	//returns false if x and y are in the same disjoint set -> to prevent forming a loop
	bool Union(Vertex* x, Vertex* y);

	//make node x in the graph into a vertex object
	//x is the integer representation of the node in the graph
	//returns the newly created vertex pointer object
	Vertex* makeSet(int x);
	
	//find the disjoint set of a given vertex
	//x is the vertex object
	//returns the head representative vertex of the disjoint set (linked list)
	Vertex* findSet(Vertex* x);

	//constructor for the disjoint set object
	DisjointSet();
	//destructor for the disjoint set object
	~DisjointSet();
};





