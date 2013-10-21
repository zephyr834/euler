/*******************************
Project Euler - Problem #6
The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
Answer: 25164150
********************************/
#include <iostream>

using namespace std;

#define square(x) (x)*(x)

int sum_square(int count);
int square_sum(int count);

int main(int argc, char *argv[])
{
    int count = 100;
    int sum_sq = sum_square(count);
    int sq_sum = square_sum(count);

    cout << sq_sum - sum_sq << endl;

    system("pause");
    return 0;
}

int sum_square(int count)
{
    int sum = 0;
    while ( count > 0 )
    {
        sum += square(count--);
    }
    return sum;
}

int square_sum(int count)
{
    int sum = 0;
    while ( count > 0 )
    {
        sum += count--;
    }

    return square(sum);
}