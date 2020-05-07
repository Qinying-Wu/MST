//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: MST using Kruskal's Algorithm
//this is the class definition for the Vertex class object
#pragma once
#include "Vertex.h"
//vertex object constructor
Vertex::Vertex(int vt) {
	v = vt;
	head = nullptr;
	next = nullptr;
	count = 1;

};
//vertex object destructor
Vertex::~Vertex() {
	head = nullptr;
	next = nullptr;
}