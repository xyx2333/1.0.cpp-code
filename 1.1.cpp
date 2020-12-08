#include<iostream>
int main(){
    double x,y(0);
    std::cin>>x;
    if(x<1)
        y=x;else if(1<=x<10)
        y=2*x-1;else if(x>=0)
        y=3*x-11;
    std::cout<<y;
    return 0;
}