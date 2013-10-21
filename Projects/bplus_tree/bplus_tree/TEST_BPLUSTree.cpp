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
#include "bplustree.h"
#include <fstream>
#include <iostream>

#include <string>

using namespace std;

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

	Btree bplustree;
	int new_data, target2, order;
	bool status;
	string command;
	
	
	do		//takes in the order of the tree
	{
		cin >> command;
		if(command == "O")
			cin >> order;
		else
		{
			cout <<"Must declare order of tree!"<<endl;
			while(cin.peek() != '\n')		//ignores anything else after error until next line
			{
				cin.ignore();
			}
		}
	}while(command != "O");
	

	while( !cin.eof())
	{	
		status=true;
		cin >> command;

		if(command == "A")			//Insert command
		{
			cin >> new_data;
			status = bplustree.b_insert(new_data, order);
			if(status == true)
				cout << "Success: " << new_data << " was inserted into the tree" << endl;
			else
				cout << "Error: attempt to insert duplicate value of " << new_data << endl;
		}
		else if(command == "S")			//search command
		{
			cin >> new_data >> target2;
			status = bplustree.b_search(new_data, target2);
			if(status == false)
				cout << "Error: attempt to locate values not found in the tree between " << new_data << " and " << target2 << endl;
			else
				cout << endl;
		}
		
		else if(command == "P")		//preorder traversal command
		{
			status = bplustree.b_print();
			if(status == false)
				cout << "Error: attempt to perform a Preorder on an empty tree" << endl;
		}
		
		else if(command == "D")		//delete command
		{
			cin >> new_data;
			status = bplustree.b_remove(new_data);
			if(status == false)
				 cout << "Error: attempt to delete a value not found in the tree of " << new_data << endl;
			else
				cout<<"Success: " << new_data << " was deleted from the tree" << endl;
		}
		
		else		//output error statement for any other input
		{
			cout<<"Error: <"<<command<<"> is not a valid command"<<endl;
			while(cin.peek()!='\n')		//ignores anything else after error until next line
			{
				cin.ignore();
			}
		}
			
	}//end of while loop
	
	return 0;
}
	