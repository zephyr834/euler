#include "stack.h"
#include <iostream>
#define PUSH 0
#define POP 1

using namespace std;

int main()
{
    Stack stack;
    int command;

    while(1)
    {
        cin >> command;

        if(command == PUSH)
        {
            stack.push();
        }
        else if (command == POP)
        {
            stack.pop();
        }
        else
        {
            stack.print();
        }
    }

    system("pause");
    return 0;
}