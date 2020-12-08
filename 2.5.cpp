#include<iostream>
using namespace std;
int main(){
    int a = 1;
    int & i = a;
    const double b = 3.14;
    const double & c = 5.20;
    decltype (c) d = 5.21;
    int *j = & a;
    const double *k = & b;
    auto h = b;
    cout << d << endl << i << endl << j << endl << k << endl << h <<"😂\n";
    return 0;
}