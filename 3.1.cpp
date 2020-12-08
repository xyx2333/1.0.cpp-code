#include <iostream>
#include "test1.cpp"

int main()
{
    int y = 2;
    extern int x;
    std::cout << x + y;
    return 0;
}