#include <iostream>

int main()
{
    int allnum(int);
    int n, num = 1;
    std::cin >> n;
    for (; n > 1; n--)
    {
        num = allnum(num);
    }
    std::cout << num;
    return 0;
}

int allnum(int tnum)
{
    tnum = 2 * (tnum + 1);
    return tnum;
}