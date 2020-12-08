#include <iostream>

int main()
{
    int y = 2;
    extern int x;
    std::cout << x + y;
    return 0;
}