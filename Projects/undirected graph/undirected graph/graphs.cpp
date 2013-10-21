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