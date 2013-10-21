/*******************************
Project Euler - Problem #5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
Answer:
232792560
********************************/
#include <iostream>

using namespace std;

#define MAX 20

int number_divisble();

int main(int argc, char *argv[])
{

    cout << number_divisble() << endl;

    system("pause");
    return 0;
}

int number_divisble()
{
    int multiple = 1;
    int hold_num = 1;
    for (int i = 1; i < (MAX + 1); i++)
    {
        hold_num = multiple;
        while ( (multiple % i) != 0 )
        {
            multiple += hold_num;
        }
    }
    return multiple;
}