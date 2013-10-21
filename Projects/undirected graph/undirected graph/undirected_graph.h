
#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include <string>

using namespace std;

class Graph             
{
public:
       Graph();							
       ~Graph();							
	   void edges (int vertex1, int destination, int weight);
	   void set_path_and_distance (int source, int size) const;
	   void print_graph (int size);
	   
private:
		static const int max_size = 30;
		static const int infinity = 1000;
		
       class Node
       {
       public:
		   Node (int n_edge, Node * edge_ahead) // Constructor changes 
		   { 
			   edge = n_edge
			   next_edge = edge_ahead;
		   }
		    bool source;
			int edge;
			Node *next_edge;
			
			void graph_destroyer(Node *ptr);

	   };
		Node *vertex[max_size];
		
		//Node int distance[max_size];
};

#endif