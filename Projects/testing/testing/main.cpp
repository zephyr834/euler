#include <iostream>
#include <string>
#include <vector>
#include "test_header.h"
using namespace std;

struct Box 
{
    int cards;
};



int main()
{
    
    vector<int> numbers;
    vector<int>::iterator iter;

    for (int i = 1; i < 100; i++)
    {
        numbers.push_back(i);
        iter = numbers.end();
        numbers.insert(iter, i - 1);
    }

    for (iter = numbers.begin(); iter < numbers.end(); iter++)
    {
        cout << *iter << " ";
    }

    Cat meow;

    meow.
    cout << endl;

    cout << numbers.empty() << endl;
    numbers.clear();
    cout << numbers.empty() << endl;
    system("pause");
    return 0;
}