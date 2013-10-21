/*******************************
Project Euler - Problem #9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

Answer: 
********************************/
#include <iostream>
#define sqr(x) (x)*(x)
using namespace std;

void pythagorean_trip(int &a, int &b, int &c);
bool check_thousand(int a, int b, int c);

int main(int argc, char *argv[])
{
    int a = 3;
    int b = 4;
    int c = 340;

    while ( c < 1000 )
    {
        while ( b < c )
        {
            while ( a < b )
            {
                if ( (a + b + c == 1000) && (sqr(a) + sqr(b) == sqr(c)))
                {
                    cout << a << " " << b << " " << c << endl;
                    break;
                }
                a++;
            }

            b++;
            a = 3;
        }
        b = 4;
        c += 4;
    }
    
    

    cout << a * b * c << endl;

    system("pause");
    return 0;
}



bool check_thousand(int a, int b, int c)
{
    return ( (a + b + c) == 1000);
}