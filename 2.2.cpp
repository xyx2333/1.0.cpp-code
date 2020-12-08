#include<iostream>
using namespace std;

int main(){
    int i;
    float t,s;
    t = 1,s = t;
    for(i = 2;i <= 20;i++){
    t = t*1/i;
    s+=t;
    }
    cout << s;
    return 0;
}