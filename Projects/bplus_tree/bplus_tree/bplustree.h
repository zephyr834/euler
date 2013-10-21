/*****************************************
*Name: Eighan, Cory
*ECST:ceighan
*ceighan@mail.ecst.csuchico.edu
*CSCI 311: Melody Stapleton
*25 September 2011
* 311 Program 2: B-Plus Tree
*************************************/
#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <iostream>
#include <string>
using namespace std;

class Btree
{
public:
       Btree();							//complete
       ~Btree();							//complete
	   bool b_insert (int new_data, int order);		
	   bool b_search (int &target1, int &target2);			
	   bool b_print();	
	   bool b_remove(int &target);

private:
		static const int overflow=2;
		static const int success=1;
		static const int failure=0;
       class Node
       {
       public:
		   Node (int n_order) // Constructor changes 
		   { 
			   count = 0;
			   data = new int[n_order - 1]; 
			   branch = new Node *[n_order];
			   sequence = NULL;
			   order=n_order;
		   }
			 int count;
			 int order;
			 int *data;
			 Node *sequence;
			 Node **branch;
			 bool search_node(Node *current, int &target1, int &target2, int &position);		//complete
			 bool recursive_search_tree(int &target1, int &target2, Node *current);			//complete
			 int push_down(Node *current, int new_data, int &median, Node *&right_branch, Node *old_current, int old_position);		//complete
			 void push_in(Node *current, int new_entry, Node *right_branch, int position);		//complete 
			 void split_node(Node *current, int new_entry, Node *extra_branch, int position,Node *&right_half, int &median);		//complete
			 void tree_destroyer(Node *ptr);		//complete
			 void preorder(Node *ptr);		//complete
			 bool recursive_remove(Node *current, int&target);		//complete
			 void move_left(Node *current, int position);		//complete
			 void move_right(Node *current, int position);		//complete
			 void combine(Node *current, int position);		//complete
			 void restore(Node *current, int position);		//complete
			 void inv_restore(Node *current, int old_position);		//used to delay splits for insert
			 void remove_data(Node *current, int position);		//complete
	   };
       Node *m_root;										

};

#endif
