#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double z,x;
    cin>>x;
    if(0<=x<2)
    z=3*x+5;
    cout<<z;
    if(2<=x<3)
    z=2*sin(x);
    cout<<z;
    if(3<=x<5)
    z=sqrt(1+x*x);
    cout<<z;
    if(5<=x<8);
    z=x*x-2*x+5;
    cout<<z;
    if (x<1||x>=8)
    cout<<"不在范围内";
    return 0;
}