#include<iostream>
int main()
{
    double e_x(double,int);
    double x;
    int n;
    double e_x_i;
    std::cin >> x >> n;
    e_x_i = e_x(x,n);
    std::cin >> x >> n;
    e_x_i += e_x(x,n);
    std::cout << e_x_i;
    return 0;
}
    double e_x(double x, int n) 
{
    double e_x = 1;
    double x_sum;
    int i = 1, m = 1;
    x_sum = x;
    while (i <= n) {
    e_x += x_sum / m;
    i += 1;
    m *= i;
    x_sum *= x;
    }
    return e_x;
}