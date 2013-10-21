#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack()
{	
    root = NULL;
    count = 1;
}
Stack::~Stack ()
{

}

void Stack::push()
{
    if (root == NULL)
    {
        root = new Node(count, NULL);
        count++;
    }
    else
    {
        root = new Node(count, root);
        count++;
    }
}

void Stack::pop()
{
    if (root == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        count--;
        Node *ptr = root;
        root = root -> next;
        ptr = NULL;
        delete ptr;
    }
}

void Stack::print()
{
    Node *ptr = root;
    while (ptr != NULL)
    {
        cout << ptr -> index << " ";
        ptr = ptr -> next;
    }
}