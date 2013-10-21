/*****************************************
*Name: Eighan, Cory
*ECST:ceighan
*ceighan@mail.ecst.csuchico.edu
*CSCI 311: Melody Stapleton
*25 September 2011
* 311 Program 2: Graphs
*************************************/
#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include <string>

using namespace std;

class Graph             
{
public:
       Graph();							//complete
       ~Graph();							//complete
	   void edges (int vertex1, int destination, int weight);
	   void set_path_and_distance (int source, int size) const;
	   void print_graph (int size);
	  // void print_sources(int source);
	   
private:
		static const int max_size = 30;
		static const int infinity = 1000;
		
       class Node
       {
       public:
		   Node (int n_edge, int n_weight, Node * edge_ahead) // Constructor changes 
		   { 
			   edge = n_edge;
			   weight = n_weight;
			   next_edge = edge_ahead;
		   }
		    bool source;
			int edge;
			int weight;
			Node *next_edge;
			
			void tree_destroyer(Node *ptr);

	   };
		Node *vertex[max_size];
		
};

#endif