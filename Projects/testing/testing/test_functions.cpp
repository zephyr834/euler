#include "test_header.h"
#include <iostream>

using namespace std;

Cat::Cat(){
    y = 0;
}

void Cat::value(int x){
    y = x;
}

int Cat::ref(){
    return y;
}