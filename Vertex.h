//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: MST using Kruskal's Algorithm
//this is the header for the Vertex class object
#pragma once
class Vertex {
public:
	friend class Edge;
	friend class DisjointSet;
	friend class Graph;
	Vertex(int v); //vertex object constructor
	~Vertex(); //vertex object destructor
private:
	int v; //the integer representation of the vertex v
	Vertex* head; //the representative vertex of the disjoint set that the current vertex resides in
	Vertex* next; //the next vertex linked to the current vertex to form a disjoint set
	//if the current vertex is the representative vertex, count stores the total number of nodes in the current disjoint set
	//count is 1 for the rest of the nodes in the disjoint set
	int count; 
};
