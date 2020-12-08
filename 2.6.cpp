#include<iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    double e_x = 1;
    double x_sum;
    double x;
    int i = 1, m = 1;
    cin >> x >> n;
    x_sum = x;
    while (i <= n) {
    e_x += x_sum / m;
    i += 1;
    m *= i;
    x_sum *= x;
    }
    printf("%.15lf", e_x);
    return 0;
}