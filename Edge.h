//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: MST using Kruskal's Algorithm
//this is the header file for the Edge class object
#pragma once
#include "Vertex.h"
class Edge{
public:
	friend class Graph; 
	Edge(Vertex* u, Vertex* v, double w); //edge object constructor
	~Edge(); //edge object destructor
private:
	Vertex* u; //the two nodes connected by the edge
	Vertex* v;
	double w;		//the weight of the edge
};
