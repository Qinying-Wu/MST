//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: MST using Kruskal's Algorithm
//this is the DisjointSet class object definition
#pragma once
#include "DisjointSet.h"
//constructor for the DisjointSet object
DisjointSet::DisjointSet() {};
//destructor for the DisjointSet
DisjointSet::~DisjointSet() {};

//performs a union operation on the disjoint sets of x and y
//x and y are vertices in the graph
//returns true if the the disjoint set that x resides in is different than that of y after unioning
//returns false if x and y are in the same disjoint set -> to prevent forming a loop
bool DisjointSet::Union(Vertex* x, Vertex* y) {
	Vertex* xSet = findSet(x); //first find the sets
	Vertex* ySet = findSet(y);
	//if x set size >= y set size -> add y to x
	if (xSet != ySet) {
		if (xSet->count >= ySet->count) {
			xSet->count += ySet->count; //increase the size of the set
			Vertex* temp = xSet->next; //temporarily store the next pointer
			//add to rest of y to x in the overallset
			xSet->next = ySet;
			Vertex* temp2 = ySet;
			//set the rest of ySet to have the same head as xSet
			while (temp2->next != nullptr) {
				temp2->count = 1;
				temp2->head = xSet;
				temp2 = temp2->next;
			} //non-head nodes should have a count of 1
			//reached the last node in ySet
			temp2->count = 1;
			temp2->head = xSet;
			temp2->next = temp; // finish up the brand new set
			temp2 = nullptr; //dereference temp2
		}
		//else y set size> x set size -> add x to y
		else {
			ySet->count += xSet->count; //increase the size of the set
			Vertex* temp = ySet->next; //temporarily store the next pointer
			//add to rest of x to y in the overallset
			ySet->next = xSet;
			Vertex* temp2 = xSet;
			//set the rest of xSet to have the same head as the ySet
			while (temp2->next != nullptr) {
				temp2->count = 1;
				temp2->head = ySet;
				temp2 = temp2->next;
			} //non-head nodes should have a count of 1
			//reached the last node in ySet
			temp2->count = 1;
			temp2->head = ySet;
			temp2->next = temp; // finish up the brand new set
			temp2 = nullptr; //dereference temp2
		}
		return true;
	}
	//the vertices are in the same set and will form a loop
	else {
		return false;
	}


};

//make node x in the graph into a vertex object
//x is the integer representation of the node in the graph
//returns the newly created vertex pointer object
Vertex* DisjointSet::makeSet(int x) {
	Vertex* hv = new Vertex(x);
	return hv;
}

//find the disjoint set of a given vertex
//x is the vertex object
//returns the head representative vertex of the disjoint set (linked list)
Vertex* DisjointSet::findSet(Vertex* x) {
	return x->head;

}
