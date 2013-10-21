/*Name: Eighan, Cory
*ECST:ceighan
*ceighan@mail.ecst.csuchico.edu
*CSCI 311: Melody Stapleton
*25 September 2011
* 311 Program 2: B-Plus Tree
*
*Program: 
*Main.cpp file
* The program takes in data and sorts it into a B+ tree structure
*Credit is to be given for Kruse's code for B trees
*as I used it and implemented the B+ tree.
*
*
*NOTE:The user must specifify the Order of the tree in the first command.
*It is made to accept any order as far as my testing has shown!
*************************************/
#include "graphs.h"
#include <fstream>
#include <iostream>

#include <string>

using namespace std;

//fstream outputfilePointer;

int main(/*int argc, char *argv[]*/)
{/*
	if(argc != 3) {
		cerr << "usage: ./a.out <input-file> <output-file>" << endl;
		return 1;
	}

	//Reading input and output file from command line arguments	
	char *input_file = argv[1];
	char *output_file = argv[2];
	char buffer[100];

	//Creating filepointer to read input-file
	fstream inputfilePointer;
	
	//Opening input-file in read mode
	inputfilePointer.open( input_file, ios::in );
	if( !inputfilePointer ) {
		cerr << "Failed to open file" << endl;
		return 1;
	} 
	//Creating filePointer to create/access output-file
	fstream outputfilePointer;
	//Opening output-file in append mode
	outputfilePointer.open( output_file, ios::out | ios::app );
	if( !outputfilePointer.is_open() ) {
		cerr << "Failed to access file" << endl;
		return 1;
	}
	*/

	Graph graphy;
	int source, vertex, destination, weight, size;
	

	
	cin >> size;		//Input number of vertices

	
	while(1)
	{					//This loop creates the edges for the vertices
		
		cin >> vertex;
		
		if ( cin.peek() == '\n')	//when it finds an end line after the source it goes to next loop
			break;
		
		cin >> destination;
		cin >> weight;

 		graphy.edges (vertex, destination, weight);
		
	}	//end of while loop

	cout << "Graph:" << endl;

	graphy.print_graph(size);

	cout << endl;

	source = vertex;

	cout << "source: " << source << endl << endl;

	graphy.set_path_and_distance(source, size);

	while(!cin.eof())
	{
		cin >> source;

		cout << "source: " << source << endl << endl;

		graphy.set_path_and_distance(source, size);

	}
	
	system ("pause");

	return 0;
}
	