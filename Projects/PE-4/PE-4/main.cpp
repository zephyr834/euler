/*******************************
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
Notes: Somewhat optimized
********************************/
#include <iostream>

using namespace std;

#define DIGIT_MAX 9999
#define DIGIT_MIN 999

int inverse_number(int number);
void palindrome_number(int &answer);

int main(int argc, char *argv[])
{
    int answer = 0;

    palindrome_number(answer);
    cout << answer << endl;

    system("pause");
    return 0;
}

int inverse_number(int number)
{
    int num = number;
    int rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }

    return rev_num;
}

void palindrome_number(int &answer)
{
    int product = 0;
    int rev_num = 0;

    for (int i=DIGIT_MAX; i > DIGIT_MIN; i--)
    {
        if (i * i < answer)
        {
            break;
        }
        for (int j=DIGIT_MAX; j > DIGIT_MIN; j--)
        {
            product = i * j;
            rev_num = inverse_number(product);
            
            if ( (rev_num == product) && (product > answer) )
            {
                answer = product;
            }
        }     
    }
}