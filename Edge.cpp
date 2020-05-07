//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: MST using Kruskal's Algorithm
//this is the class definition for the Edge class object
#pragma once
#include "Edge.h"
//Edge object constructor
//u and v are two vertex objects connected by an edge
//w is the weight of the edge
Edge::Edge(Vertex* u, Vertex* v, double w) {
	this->u = u;
	this->v = v;
	this->w = w;
}
//destructor of the edge object
Edge::~Edge() {
	u = nullptr;
	v = nullptr;
}