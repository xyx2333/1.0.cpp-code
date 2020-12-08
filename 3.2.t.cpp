#include <iostream>

int main()
{
    char a[10];
    for (auto &n:a)
    std::cin >> n;
    for (int i = 0; i < 10; i++)
    {
        std::cout << a[i];
    }
    return 0;
}