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

#include "bplustree.h"
#include <iostream>
#include <string>

using namespace std;

//constructor
Btree::Btree ()
{
	m_root=NULL;
	
}

//destructor

Btree::~Btree ()
{
	Node *ptr = m_root;
	ptr->tree_destroyer(ptr);

}
/******************************
*Function is used by destructor to
*clear all memory at the end of the program
*******************************/
void Btree::Node::tree_destroyer(Node *ptr)
{
	if(ptr == NULL)
		return;
	Node *temp=ptr;
	ptr = NULL;
	for(int i=0; i < ptr -> count+1; i++)
	{
		temp -> tree_destroyer(temp -> branch[i]);
	}
	delete temp;
}

/**********************
*Function is called by user command and 
*used the preorder function
*********************/
bool Btree::b_print()
{
	if(m_root==NULL)
		return false;
	Node *cur=m_root;
	m_root->preorder(cur);
	cout<<endl;
	return true;
}
/**********************
*Preorder funtion print out all the values
*at the current node then moves to
*its left branch and then right branch
***********************/
void Btree::Node::preorder(Node *ptr)
{
	Node *cur=ptr;
	if(ptr==NULL)
		return;
	for(int i=0; i < cur->count; i++)
	{
		cout<<cur->data[i];
		if((cur->count-1)!=i)
			cout<<",";
		else
			cout<<" ";
	}
	for(int j=0; j < cur -> count+1; j++)
		cur -> preorder(cur -> branch[j]);
}

bool Btree::b_search (int &target1, int &target2)
{/*
Post: If there is an entry in the B-tree whose key matches that in target,
      the parameter target is replaced by the corresponding Record from
      the B-tree and a code of success is returned.  Otherwise
      a code of not_present is returned.
Uses: recursive_search_tree
*/
	return m_root->recursive_search_tree(target1, target2, m_root);
}


bool Btree::Node::recursive_search_tree(int &target1, int &target2, Node *current)
{
/*
Pre:  current is either NULL or points to a subtree of the B_tree.
Post: If the Key of target is not in the subtree, a code of not_present
      is returned. Otherwise, a code of success is returned and
      target is set to the corresponding Record of the subtree.
Uses: recursive_search_tree recursively and search_node
*/
   bool result = false;
   int position;
   if (current != NULL) 
   {
      result = search_node(current, target1, target2, position);
      if (result == false)
         result = recursive_search_tree(target1, target2, current -> branch[position]);
      else
	  {
		  if(target1 == target2)
			  cout<<"Success: here are the values - "<<current -> data[position];
		  else if (target1 < target2)
		  {	//displays range of values between target1 and target2
			  cout<<"Success: here are the values - ";
			  do
			  {
				  if(position != current -> count)
				  {	
					  
					  if(current -> data[position] <= target2)
					  {
						  if(current -> data[position] == target2)
						  {
							  cout<<target2;
							  return result;
						  }
						  
						  cout << current -> data[position++];
						  if(current -> data[position] <= target2)
							  cout<<",";
						  
					  }
					  else if(current -> data[position] > target2)
						  return result;
				  }	
				  else
				  {
					  position = 0;
					  current = current -> sequence;
				  }	//end else
			  }while(current != NULL);
			  
		  }
	  }
   }
   return result;
}


/*
Pre:  current points to a node of a B_tree.
Post: If the Key of target is found in *current, then a code of
      success is returned, the parameter position is set to the index
      of target, and the corresponding Record is copied to
      target.  Otherwise, a code of not_present is returned, and
      position is set to the branch index on which to continue the search.
Uses: Methods of class Record.
*/
bool Btree::Node::search_node(Node *current, int &target1, int &target2,int &position)

{
   position = 0;
   Node *temp = current -> sequence;
   if(target1 == target2)
   {
		while (position < current -> count && target1 > current -> data[position])
		    position++;         //  Perform a sequential search through the keys.
   }
   else
   {
	   while (position < current -> count-1 && target1 > current -> data[position])
			position++;         //  Perform a sequential search through the keys.
   }
   if(target1 < target2 && current -> branch[0] == NULL)
   {
	   if(position == current -> count  && temp == NULL)
		   return false;
	   else if (target2 < current -> data[position])
		   return false;
	   else
	   {
		   cout << current -> data[position];
		   return true;
	   }
   }
   if (position < current -> count && target1 == current -> data[position] && current -> branch[0] == NULL)
      return true;
   else
      return false;
}

/*
Post: If the Key of new_entry is already in the B_tree,
      a code of duplicate_error is returned.
      Otherwise, a code of success is returned and the Record new_entry
      is inserted into the B-tree in such a way that the properties of a B-tree
      are preserved.
Uses: Methods of struct B_node and the auxiliary function push_down.
*/

bool Btree::b_insert(int new_data,int order)
{
	int median;
	int position=0;
	Node *new_root, *new_root1=m_root;
	Node *right_branch;
	int result = m_root -> push_down(m_root, new_data, median, right_branch, new_root1, position);
   if (result == overflow)
   {  //  The whole tree grows in height.
                              //  Make a brand new root for the whole B-tree.
      new_root = new Node(order);
      new_root -> count = 1;
	  new_root -> data[0] = median;		//new node
	  new_root -> branch[0] = m_root;
	  new_root -> branch[1] = right_branch;
	  m_root = new_root;
	  result = success;
   }
   else if(result==failure)
	   return false;
   return true;
}

/*
Pre:  current is either NULL or points to a node of a B_tree.
Post: If an entry with a Key matching that of new_entry is in the subtree
      to which current points, a code of duplicate_error is returned.
      Otherwise, new_entry is inserted into the subtree: If this causes the
      height of the subtree to grow, a code of overflow is returned, and the
      Record median is extracted to be reinserted higher in the B-tree,
      together with the subtree right_branch on its right.
      If the height does not grow, a code of success is returned.
Uses: Functions push_down (called recursively), search_node,
      split_node, and push_in.
*/
int Btree::Node::push_down(Node *current, int new_data, int &median, Node *&right_branch, Node *old_current, int old_position)

{
   int result;
   int position;
   
   if (current == NULL) 
   { //  Since we cannot insert in an empty tree, the recursion terminates.
	  median = new_data;
      right_branch = NULL;
      result = overflow;
   }
   else
   {   //   Search the current node.
      if (search_node(current, new_data, new_data, position) == success)
         result = failure;
      else 
	  {
			int extra_entry;
			Node *extra_branch;
			Node *parent_right = old_current -> branch[old_position + 1];
			Node *parent_left = old_current -> branch[old_position - 1];

			result = push_down(current -> branch[position], new_data, extra_entry, extra_branch, current, position);
			if (result == overflow) 
			{  //  Record extra_entry now must be added to current
				if (current -> count < order - 1) 
				{
					result = success;
					push_in(current, extra_entry, extra_branch, position);
				}
				
				//checks to see if there is room in sibling node to delay split
				else if (old_current != current && old_position < old_current -> count &&  parent_right -> count < order-1 || 
							old_current != current && old_position > 0 && parent_left -> count < order-1)
				{	
					push_in(current, extra_entry, extra_branch, position); //push in extra entry in current node
					inv_restore(old_current, old_position);	//figures out rotation
					result = success;
				}
				else
				{
					split_node(current, extra_entry, extra_branch, position, right_branch, median);
					//  Record median and its right_branch will go up to a higher node.
				}
			}
	  }
   }
   return result;
}

/*
Pre:  current points to a node of a B_tree.  The node *current is not full
      and entry belongs in *current at index position.
Post: entry has been inserted along with its right-hand branch
      right_branch into *current at index position.
*/
void Btree::Node::push_in(Node *current, int new_entry, Node *right_branch, int position)

{
   for (int i = current -> count; i > position; i--) 
   {  //  Shift all later data to the right.
      current -> data[i] = current -> data[i - 1];
      current -> branch[i + 1] = current -> branch[i];
   }
   current -> data[position] = new_entry;
   current -> branch[position + 1] = right_branch;
   current -> count++;
}


/*
Pre:  current points to a node of a B_tree.
      The node *current is full, but if there were room, the record
      extra_entry with its right-hand pointer extra_branch would belong
      in *current at position position, 0 <= position < order.
Post: The node *current with extra_entry and pointer extra_branch at
      position position are divided into nodes *current and *right_half
      separated by a Record median.
Uses: Methods of struct B_node, function push_in.
*/
void Btree::Node::split_node(Node *current, int new_entry, Node *extra_branch, int position, Node *&right_half, int &median)

{
   right_half = new Node(order);
   int mid = order/2;  //  The entries from mid on will go to right_half. round down Ex:3/2=1
   right_half -> sequence = current -> sequence;
   if (position <= mid)
   {   //  First case:  new_entry belongs in left half.
      for (int i = mid; i < order - 1; i++)
	  {  //  Move entries to right_half.
         right_half -> data[i - mid] = current -> data[i];
         right_half -> branch[i + 1 - mid] = current -> branch[i + 1];
      }
      current -> count = mid;
      right_half -> count = order - 1 - mid;
      push_in(current, new_entry, extra_branch, position);
   }
   else
   {  //  Second case:  extra_entry belongs in right half.
      mid++;      //  Temporarily leave the median in left half.
      for (int i = mid; i < order - 1; i++) {  //  Move entries to right_half.
         right_half -> data[i - mid] = current -> data[i];
         right_half -> branch[i + 1 - mid] = current -> branch[i + 1];
      }
      current -> count = mid;
      right_half -> count = order - 1 - mid;
      push_in(right_half, new_entry, extra_branch, position - mid);
   }
      median = current -> data[current -> count - 1];			//  Remove median from left half.
      right_half -> branch[0] = current -> branch[current -> count];

	  if(current -> branch[0]!=NULL)
		  current -> count--;
	  else
		current -> sequence = right_half;
}

bool Btree::b_remove(int &target)
/*
Post: If a Record with Key matching that of target belongs to the
      B_tree, a code of success is returned and the corresponding node
      is removed from the B-tree.  Otherwise, a code of not_present
      is returned.
Uses: Function recursive_remove
*/
{
   bool result=false;
   result = m_root -> recursive_remove(m_root, target);
   if (m_root != NULL && m_root -> count == 0) {  //  root is now empty.
      Node *old_root = m_root;
      m_root = m_root -> branch[0];
      delete old_root;
   }
   return result;
}

bool Btree::Node::recursive_remove(Node *current, int&target)
/*
Pre:  current is either NULL or
      points to the root node of a subtree of a B_tree.
Post: If a Record with Key matching that of target belongs to the subtree,
      a code of success is returned and the corresponding node is removed
      from the subtree so that the properties of a B-tree are maintained.
      Otherwise, a code of not_present is returned.
Uses: Functions search_node, copy_in_predecessor,
      recursive_remove (recursively), remove_data, and restore.
*/
{
   bool result;
   int position;
   if (current == NULL)
	   result = false;
   else 
   {
      if (search_node(current, target, target, position) == true) 
	  {  //  The target is in the current node.
         result = true;
		 remove_data(current, position);     //  Remove from a leaf node.
      }
      else result = recursive_remove(current -> branch[position], target);
      if (current -> branch[position] != NULL)
         if (current -> branch[position]->count < (order - 1) / 2)
            restore(current, position);
   }
   return result;
}


void Btree::Node::remove_data(Node *current, int position)
                                        
/*
Pre:  current points to a leaf node in a B-tree with an entry at position.
Post: This entry is removed from *current.
*/

{
   for (int i = position; i < current -> count - 1; i++)
      current -> data[i] = current -> data[i + 1];
   current -> count--;
}

void Btree::Node::restore(Node *current, int position)
                                    
/*
Pre:  current points to a non-leaf node in a B-tree; the node to which
      current->branch[position] points has one too few entries.
Post: An entry is taken from elsewhere to restore the minimum number of
      entries in the node to which current->branch[position] points.
Uses: move_left, move_right, combine.
*/
{
   if (position == current -> count)   //  case:  rightmost branch
   {
      if (current -> branch[position - 1] -> count > (order - 1) / 2)
         move_right(current, position - 1);
      else
         combine(current, position);
   }
   else if (position == 0)       //  case: leftmost branch
   {
      if (current -> branch[1] -> count > (order - 1) / 2)
         move_left(current, 1);
      else
         combine(current, 1);
   }
   else                          //  remaining cases: intermediate branches
   {
      if (current -> branch[position - 1]-> count > (order - 1) / 2)
         move_right(current, position - 1);
      else if (current -> branch[position + 1] -> count > (order - 1) / 2)
         move_left(current, position + 1);
      else
         combine(current, position);
   }
}

void Btree::Node::inv_restore(Node *current, int old_position)
                                    
/*
Note: This is like the restore function but it is called/used for insertions only
Pre:  current points to a non-leaf node in a B-tree; the node to which
      current->branch[position] points has one too few entries.
Post: An entry is taken from elsewhere to restore the minimum number of
      entries in the node to which current->branch[position] points.
Uses: move_left, move_right, combine.
*/
{

   if (old_position == current -> count)   //  case:  rightmost branch
		move_left(current, old_position);

   else if (old_position == 0)       //  case: leftmost branch
         move_right(current, old_position);

   else                          //  remaining cases: intermediate branches
   {
      if (current -> branch[old_position - 1] -> count < (order + 1) / 2 && current -> branch[old_position - 1] -> count <= current -> branch[old_position + 1] -> count)
         move_left(current, old_position);
      else
         move_right(current, old_position);
   }

}

void Btree::Node::move_left(Node *current, int position)
                                      
/*
Pre:  current points to a node in a B-tree with more than the minimum
      number of entries in branch position and one too few entries in branch
      position - 1.
Post: The leftmost entry from branch position has moved into
      current, which has sent an entry into the branch position - 1.
*/
{
	Node *left_branch = current -> branch[position - 1],
         *right_branch = current -> branch[position];
	if(left_branch -> branch[0]!=NULL)		//internal nodes
	{
		left_branch -> data[left_branch -> count] = current -> data[position - 1];  //  Take entry from the parent.
		left_branch -> branch[++left_branch -> count] = right_branch -> branch[0];
		current -> data[position - 1] = right_branch -> data[0];  //   Add the right-hand entry to the parent.
		right_branch -> count--;
	}
	else	//leaf level
	{
		left_branch -> data[left_branch -> count] = right_branch -> data[0];  //  Take entry from the right branch.
		left_branch -> branch[++left_branch -> count] = right_branch -> branch[0];
		current -> data[position - 1] = right_branch -> data[0];  //   Add the right-hand entry to the parent.
		right_branch -> count--;
	}
   for (int i = 0; i < right_branch->count; i++) 
   {   //  Move right-hand entries to fill the hole.
      right_branch -> data[i] = right_branch -> data[i + 1];
      right_branch -> branch[i] = right_branch -> branch[i + 1];
   }

   right_branch -> branch[right_branch -> count] =
      right_branch -> branch[right_branch -> count + 1];
}



void Btree::Node::move_right(Node *current, int position)
                                       
/*
Pre:  current points to a node in a B-tree with more than the minimum
      number of entries in branch position and one too few entries
      in branch position + 1.
Post: The rightmost entry from branch position has moved into
      current, which has sent an entry into the branch position + 1.
*/
{
	
   Node *right_branch = current -> branch[position + 1],
        *left_branch = current -> branch[position];
	right_branch -> branch[right_branch -> count + 1] =
			 right_branch -> branch[right_branch->count];
   for (int i = right_branch -> count ; i > 0; i--) {  //  Make room for new entry.
      right_branch -> data[i] = right_branch -> data[i - 1];
      right_branch -> branch[i] = right_branch -> branch[i - 1];
   }
   right_branch -> count++;
   if(left_branch -> branch[0] != NULL)		//internal nodes of B+ tree
   {
		right_branch -> data[0] = current -> data[position]; //  Take entry from parent.
		right_branch -> branch[0] = left_branch -> branch[left_branch -> count--];
		current -> data[position] = left_branch -> data[left_branch -> count];
   }
   else		//leaf nodes for B+ tree
   {
	   right_branch -> data[0] = left_branch -> data[left_branch -> count-1]; //  Take entry from left branch.
	   
	   left_branch -> count--;
	   current -> data[position] = left_branch -> data[left_branch -> count-1];
   }
}


void Btree::Node::combine(Node *current, int position)
                                    
/*
Pre:  current points to a node in a B-tree with entries in the branches
      position and position - 1, with too few to move entries.
Post: The nodes at branches position - 1 and position have been combined
      into one node, which also includes the entry formerly in current at
      index  position - 1.
*/
{
   int i;
   Node *left_branch = current -> branch[position - 1],
        *right_branch = current -> branch[position];
   if(left_branch -> branch[0]!=NULL)
   {
		left_branch -> data[left_branch -> count] = current -> data[position - 1];
		left_branch -> branch[++left_branch -> count] = right_branch -> branch[0];
   }
   for (i = 0; i < right_branch->count; i++) {
      left_branch -> data[left_branch -> count] = right_branch -> data[i];
      left_branch -> branch[++left_branch -> count] =
                                        right_branch -> branch[i + 1];
   }
   current -> count--;
   for (i = position - 1; i < current -> count; i++) {
      current -> data[i] = current -> data[i + 1];
      current -> branch[i + 1] = current -> branch[i + 2];
   }
   delete right_branch;
}


