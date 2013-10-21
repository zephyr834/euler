#include <iostream>

using namespace std;

#define MAX_MULTIPLE 1000
#define MULTI_OF_THREE 3
#define MULTI_OF_FIVE 5

int main(int argc, char** argv) {

    int sum = 0;
    int multiple = 0;

    while ( multiple < MAX_MULTIPLE )
    {
        if ( (multiple % 5 == 0) || (multiple % 3 == 0) )
        {
            sum += multiple;
            cout << multiple << endl;
        } 
        
        multiple += 1;
    }

    cout << sum << endl;

    system("pause");
    return 0;
}

