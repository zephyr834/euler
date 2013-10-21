/*****************************************
*Name: Eighan, Cory
*ECST:ceighan
*ceighan@mail.ecst.csuchico.edu
*CSCI 311: Melody Stapleton
*25 September 2011
* 311 Program 2: B-Plus Tree
*************************************/
#ifndef GRAPHS_TEMP_H
#define GRAPHS_TEMP_H

#include <iostream>
#include <string>
using namespace std;


typedef int Vertex;
template <int max_size>
class Digraph {
   int count;   //  number of vertices, at most max_size
   List <Vertex> neighbors[max_size];
};


class Edge;             //  forward declaration
class Vertex {
   Edge *first_edge;    //  start of the adjacency list
   Vertex *next_vertex; //  next vertex on the linked list
};

class Edge {
   Vertex *end_point;  //  vertex to which the edge points
   Edge *next_edge;    //  next edge on the adjacency list
};

class Digraph {
   Vertex *first_vertex;  //  header for the list of vertices
};


#endif