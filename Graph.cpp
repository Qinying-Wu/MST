//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: MST using Kruskal's Algorithm
//this is the class definition for the Graph class object
#pragma once
#include "Graph.h"
#include "illegal_argument.h"
//constructor for the Graph class
//initialized with edge and node counts of 0 each
Graph::Graph(int e,int v ) {
	edge_count = e;
	node_count = v;
}

//destructor for the Graph class, clears the adjacency matrix storing the graph
Graph::~Graph() {
	graph.clear();
}

//initialization, first command and never called again
//m is the number of vertices in the graph
//returns success if success
//throws an exception if m<0
string Graph::n(int m) {
	try {
		if (m < 0) {
			throw illegal_argument();
		}
		node_count = m;
		graph.resize(m);
		for (int i = 0; i < m; i++) {
			graph[i].resize(m);
		}
		return SUCCESS;
	}
	catch (illegal_argument ia) {
		return ia.FAILEDSTR;
	}

}

//inserts an edge between nodes u and v with weight w
//u and v are integer representation of the vertices, w is the weight of the edge
//returns success if success, update the weight if already a connection between u and v
//throws exception failure if u or v are outside the valid range or w<=0
string Graph::i(int u, int v, double w) {
	try
	{
		//if (u or v outside of valid range) or (w<=0) or u is the same node as v   throw exception
		if (u >= node_count || v >= node_count || u < 0 || v < 0 || w <= 0||u==v) {
			throw illegal_argument();
		}
		else { //else assign the weight to the edge between vertices u and v
			if (graph[u][v] == 0 && graph[v][u] == 0) {
				++edge_count; //only increment the edge count if edge has not existed before
			}
			graph[u][v] = w;
			graph[v][u] = w;
			return SUCCESS;
		}
	}
	catch (illegal_argument ia)
	{
		return ia.FAILEDSTR;
	}
}

//deletes the edge between two vertices
// u and v are integer representation of arbitrary vertices
//if either or both u and v out of range, throws an exception
//else if weight of edge is 0, returns failure
//else deletes the edge between vertices u and v and return success
string Graph::d(int u, int v) {
	try
	{
		//exception case
		if (u < 0 || v < 0 || u >= node_count || v >= node_count) {
			throw illegal_argument();
		}
		//non-exception failure case
		else if (graph[u][v] == 0 and graph[v][u] == 0) {
			return FAILURE;
		}
		//delete by setting the value there to be 0
		else {
			graph[u][v] = 0;
			graph[v][u] = 0;
			--edge_count;
			return SUCCESS;
		}
	}
	catch (illegal_argument ia)
	{
		return ia.FAILEDSTR;
	}
}

//returns the number of edges connected to a vertex
// u is an integer representation of an arbitrary vertex
//if vertex is in the graph, return the degree of the vertex
//if vertex out of range, throw exception
int Graph::degree(int u) {
	try {
		if (u >= node_count) {
			throw illegal_argument();
		}
		int degree = 0;
		//increment degree on every non-zero entries 
		for (int i = 0; i < node_count; i++) {
			if (graph[u][i] > 0) {
				++degree;
			}
		}
		return degree;
	}
	catch (illegal_argument ia) {
		return ia.FAILEDINT;
	}
}

//returns the total count of edges in the graph in string 
int Graph::edges_count() {
	return edge_count;
}

//removes all the edges from the graph
//outputs success in test driver
void Graph::clear() {
	for (int i = 0; i < node_count; i++) {
		for (int j = i; j < node_count; j++) {
			if (graph[i][j] != 0 && graph[j][i] != 0) {
				graph[i][j] = 0;
				graph[j][i] = 0;
				edge_count -= 1;
			}
		}
	}
}

//calculates the mst of the Graph
//returns its minimum weight if connected
//returns -1 if not connected
double Graph::mst() {
	vector<Edge> edges{}; //to store the edges in the graph
	vector<Vertex*> vertices{}; //to store all the vertiex objects of the graph
	//vector<int> visited{}; //to store the list of visited vertices
	DisjointSet ds;
	double weight = 0;
	//make the disjoint sets each of size 1
	for (int i = 0; i < node_count; i++) {
		Vertex* vs = ds.makeSet(i);
		vs->head = vs; //each initial set has the head as itself
		vertices.push_back(vs);
		//visited.push_back(-1); //-1 to represent not visited vertices
	}
	//store all the edges
	for (int i = 0; i < node_count; i++) {
		for (int j = i; j < node_count; j++) {
			if (graph.at(i).at(j) > 0) {
				edges.push_back(Edge(vertices.at(i), vertices.at(j), graph.at(i).at(j))); //store the edge in the edges vector if weight is not 0
			}
		}
	}
	std::sort(edges.begin(), edges.end(), [](const Edge& lhs, const Edge& rhs) {
		return lhs.w < rhs.w;
		}); //sort the edges by ascending order of weight

	int tree_edge_count = 0;
	//union the sets
	for (int i = 0; i < edge_count; i++) {
		//only add the nodes to allNodes if u and v belongs to different disjoint sets
		if (ds.Union(edges.at(i).u,edges.at(i).v)) {
			weight += edges.at(i).w; //add the weight
			//visited.at(edges.at(i).u->v) = edges.at(i).u->v;
			//visited.at(edges.at(i).v->v) = edges.at(i).v->v;
			++tree_edge_count;
		}
		//the handshake theorem, the edges of the mst should be 1 less than the total node count
		if (node_count - tree_edge_count == 1) {
			return weight;
		}
	}
	return -1;
	//for (int i = 0; i < node_count; i++) {
	//	//the graph is not connected as some nodes were not visited because it is connected to any other nodes in the graph
	//	if (visited.at(i) == -1) {
	//		return -1;
	//	}
	//}

	return weight;
}



