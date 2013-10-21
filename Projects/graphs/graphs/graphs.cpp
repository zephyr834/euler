/*****************************************
*Name: Eighan, Cory
*ECST:ceighan
*ceighan@mail.ecst.csuchico.edu
*CSCI 311: Melody Stapleton
*25 September 2011
* 311 Program 2: B-Plus Tree
*
*Program: These are the functions for the B+ Tree.
* The program takes in data and sorts it into a B+ tree structure
*Credit is to be given for Kruse's code for B trees
*as I used it and implemented the B+ tree
*************************************/

#include "graphs.h"
#include <iostream>
//#include <fstream>

using namespace std;

Graph::Graph()
{	
	for(int i = 0; i < max_size; i++)
		vertex[i] = NULL;

}
Graph::~Graph ()
{

}

void Graph::edges(int vertex1, int destination, int weight)
{
	if ( vertex[vertex1] == NULL )		//if very first edge for a vertex
		vertex[vertex1] = new Node (destination, weight, NULL);

	else
	{
		Node *cur = vertex[vertex1];
		Node *prev = vertex[vertex1];


		while(1)
		{
			
			if( cur == NULL || destination < cur -> edge)
			{
				if ( cur == vertex[vertex1])		//if it is to be first node
					vertex[vertex1] = new Node (destination, weight, cur);
				else
					prev -> next_edge = new Node (destination, weight, cur);

				break;
			}

			prev = cur;
			cur = cur -> next_edge;
		}

	}
}

void Graph::print_graph(int size)
{
	Node *ptr;

	for (int i = 0; i < size; i++)
	{
		ptr = vertex[i];

		cout << "vertex["<< i << "] ->";

		while( ptr != NULL)
		{
			cout << ptr -> edge << "," << ptr -> weight << "->";

			ptr = ptr -> next_edge;
		}

		cout << "NULL" << endl;

	}
}


void Graph::set_path_and_distance(int source, int size) const
/*
Post: The array distance gives the minimal path weight from vertex source
      to each vertex of the Digraph.
*/

{	
	Node *ptr = vertex[source];

	int counter, min, destination;

	int temp_array[max_size];		//array to reverse order of values during printing process
	int adjacent_vertex[max_size];	//array for vertex other than source to store weights
	int pathpred[max_size];
	int distance[max_size];

   bool found[max_size];   //  Vertices found in S

   if( vertex[source] == NULL )
   {
	   for(int i = 0; i < size; i++)
		  cout << "No path from " << source << " to " << i <<endl << endl;

	   return;
   }

   for (int i = 0; i < size; i++)
   {
      found[i] = false;

	 // temp_array[i] = infinity;
	  pathpred[i] = infinity;
	  distance[i] = infinity;

	  if ( ptr != NULL )
	  {
		  if ( ptr -> edge == i )
		  {
			  pathpred[i] = source;
			  distance[i] = ptr -> weight;

			  ptr = ptr -> next_edge;
		  }
	  }

   }

   found[source] = true; //  Initialize with vertex source alone in the set S.
   pathpred[source] = -1;	//indicate it is the source



   for (int i = 0; i < size; i++) 
   { //  Add one vertex v to S on each pass.
      min = infinity;

      for (int w = 0; w < size; w++)			
	  {
		if (!found[w])
		{
			if (distance[w] < min)
			{
			   destination = w;
			   min = distance[w];

			}
		}
	  }		//end for loop
    

	  found[destination] = true;
	  
	  ptr = vertex[destination];

	  for (int i = 0; i < size; i++)
	  {
		  adjacent_vertex[i] = infinity;	//sets weight to infinity if no path to that vertex

		  if ( ptr != NULL && ptr -> edge == i)
		  {
			  adjacent_vertex[i] = ptr -> weight;	//changes weight if edge to vertex is found

			  ptr = ptr -> next_edge;
		  }

	  }


	  for (int w = 0; w < size; w++)
	  {	//updates pathpred and distance array if adjacent vertex has a shorter path

		if (!found[w] && vertex[destination] != NULL )
		{
			if (min + adjacent_vertex[w] < distance[w])
			{
				distance[w] = min + adjacent_vertex[w];
				pathpred[w] = destination;
			}
		}
	  }			//end for loop

   }			//end for loop





   for ( int i = 0; i < size; i++ )	//prints our final distance array and hops
   {
	   if( i != source )
	   {
		   if( distance[i] != infinity )
			{
				cout << "The distance from " << source << " to " << i << " is " << distance[i] << endl

					 << "The shortest path from " << source << " to " << i << " is with hops:" << endl;
				
				int temp = pathpred[i];
				int temp2;

				temp_array[source] = i;

				while ( temp != source )		//sorts pathpred into temp_array for easier printing
				{
					temp2 = pathpred[temp];

					temp_array[temp2] = temp;

					if( temp == pathpred[i] )
						temp_array[temp] = i;

					temp = temp2;
				} 

				temp = source;
				
				distance[source] = 0;

				int subtract = 0;	//temporary variable used to find weight from vertex to vertex

				do
				{
					cout << temp << " to " << temp_array[temp] << " of weight ";

					subtract = distance[temp];

					temp = temp_array[temp];

					cout << distance[temp] - subtract <<endl;
				}
				while( temp != i );		

				cout << endl;
			}

			else
				cout << "No path from " << source << " to " << i <<endl << endl;
	   }

   }

}