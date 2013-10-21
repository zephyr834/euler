#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{
public:
    Stack();
    ~Stack();
    void push();
    void pop();
    void print();

private:
    class Node
    {
    public:
        Node(int n_index, Node *n_next)
        {
            next = n_next;
            index = n_index;
        }
        int index;
        Node *next;
        void destroy();
    };
    Node *root;
    int count;
};

#endif
