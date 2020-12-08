#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double step = 0.2;
    double x = 0;
    while (x < 6.28) {
         int val = 30*(sin(x)+1);
         for (int i = 0;i < val;++i){
         cout << " ";
        }
        cout << "*" << endl;
        x+=step;
    }
    return 0;
    
}