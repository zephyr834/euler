#ifndef TEST_HEADER
#define TEST_HEADER

#include <iostream>
using namespace std;

class Cat 
{
    public:
        Cat();
        void value(int x);
        int ref();
    private:
        int y;
        class Node{};

};

#endif