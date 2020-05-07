//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: Graph using Kruskal's Algorithm
//this is the header for the Graph object
#pragma once
#include "DisjointSet.h"
#include "Edge.h"
#include <algorithm>
#include <string>
#include <vector>
using std::string;
using std::vector;

//string constants for return values to be outputted
const string SUCCESS = "success";
const string FAILURE = "failure";

class Graph {
public:
	string n(int m);

	//inserts an edge between nodes u and v with weight w
	//u and v are integer representation of the vertices, w is the weight of the edge
	//returns success if success, update the weight if already a connection between u and v
	//throws exception failure if u or v are outside the valid range or w<=0
	string i(int u, int v, double w);

	//deletes the edge between two vertices
	// u and v are integer representation of arbitrary vertices
	//if either or both u and v out of range, throws an exception
	//else if weight of edge is 0, returns failure
	//else deletes the edge between vertices u and v and return success
	string d(int u, int v);

	//returns the number of edges connected to a vertex
	// u is an integer representation of an arbitrary vertex
	//if vertex is in the graph, return the degree of the vertex
	//if vertex out of range, throw exception
	int degree(int u);

	//returns the total count of edges in the graph in string 
	int edges_count();

	//removes all the edges from the graph
	//outputs success
	void clear();

	//calculates the mst of the Graph
	//returns its minimum weight if connected
	//returns -1 if not connected
	double mst();

	//constructor for Graph object
	//initialize it with an initial edge count and node count of 0 each
	Graph(int e, int v);
	//destructor for Graph object
	~Graph();


private:
	//to store the graph of of nodes with entries as weight of edges
	vector<vector<double>> graph;

	//to store the total number of edges in the graph
	int edge_count;

	//to store the total number of nodes in the graph
	int node_count;


};



