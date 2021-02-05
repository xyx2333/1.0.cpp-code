#include <iostream>

int main()
{
    void fun(int n, int *s);
    int x;
    fun(8, &x);
    std::cout << x;
    return 0;
}

void fun(int n, int *s)
{
    int f1 = 0, f2 = 0;
    if (n == 1 || n == 2)
    *s = 1;
    else
    {
        fun (n - 1, &f1);
        fun (n - 2, &f2);
        *s = f1 + f2;
    }  
}