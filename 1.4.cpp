#include<iostream>
int main(){
    double i(1);
    double n(1);
    do {
    i+=1;
    n=n*i;
    }
    while(i<4);
    std::cout<<n;
    return 0;



}