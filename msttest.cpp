//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: MST using Kruskal's Algorithm
//this is the main cpp file
#include "Graph.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::stoi;
using std::stod;


int main()
{
	//initialize a MST object
	Graph graph(0,0);
	string input = "";
	while (std::getline(cin, input)) {
		int space = input.find(' ');
		string command = input;
		string parameter = "";
		if (space != -1) {//some parameters are passed
			command = input.substr(0, space);
			parameter = input.substr(space + 1, input.length());
		}
		if (command == "n") {
			int para = stoi(parameter);
			if (para <0) {
				break;
			}
			cout << graph.n(para) << endl;

		}
		else if (command == "i") {
			int semi_colon = parameter.find_first_of(';');
			int u = stoi(parameter.substr(0, semi_colon)); //take out u
			parameter = parameter.substr(semi_colon + 1, parameter.length());
			semi_colon = parameter.find_first_of(';');
			int v = stoi(parameter.substr(0, semi_colon)); //take out v
			double w = stod(parameter.substr(semi_colon + 1, parameter.length())); //take out w
			cout << graph.i(u, v, w) << endl;
		}
		else if (command == "d") {
			int semi_colon = parameter.find_first_of(';');
			int u = stoi(parameter.substr(0, semi_colon)); //take out u
			int v = stoi(parameter.substr(semi_colon + 1, parameter.length()));
			cout << graph.d(u, v) << endl;
		}
		else if (command == "degree") {
			int degree = graph.degree(stoi(parameter));
			if (degree == -1) {
				cout << FAILURE << endl;
			}
			else {
				cout << "degree of " << parameter << " is " <<degree << endl;
			}

		}
		else if (command == "edge_count") {
			cout<<"edge count is " << graph.edges_count() << endl;;
		}
		else if (command == "clear") {
			graph.clear();
			cout << SUCCESS << endl;
		}
		else if (command == "mst") {
			double weight = graph.mst();
			if (weight == -1) {
				cout << "not connected" << endl;
			}
			else {
				cout << "mst " << weight << endl;
			}
		}
	}
	return 0;
}






