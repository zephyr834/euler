/*******************************
Project Euler - Problem #7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
Answer: 104743
********************************/
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int number);

int main(int argc, char *argv[])
{
    int count = 1;
    int number = 1;
    int count_find = 10001;

    while ( count < count_find )
    {
        number += 2;
        //cout << number << "  ";
        if ( is_prime(number) )
        {
            count++;
        }
    }

    cout << number << endl;
    system("pause");
    return 0;
}

bool is_prime(int number)
{
    int sq_num = int( sqrt(double(number)) );
    int i = 3;
    //cout << sq_num << "  ";

    while ( i <= sq_num )
    {
        if ( ( number % i ) == 0 )
        {
           // cout << "false" << endl;
            return false;
        }

        i += 2;
    }
   // cout << "true" << endl;
    return true;
}