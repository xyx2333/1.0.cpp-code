#include<iostream>
using namespace std;
int main(){
    int n;
    for(n = 100;n <= 999;++n){
    int a = n/100;
    int b = n/10%10;
    int c = n%10;
    if(n == a*a*a+b*b*b+c*c*c)
    cout << n << endl;
    else 
    continue;
    }
    return 0;
}