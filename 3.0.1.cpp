#include<iostream>

int main(){
    int fac (int n);
    int n,i;
    std::cin >> n;
    int s = 1;
    for (i = 1; i < n; i++)
    s = s * i;
    return s;
}