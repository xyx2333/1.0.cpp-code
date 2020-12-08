#include<iostream>
using namespace std;
int main(){
    int x,y,z;
    for(x = 0;x <= 20;++x){
        for(z = 0;z <= 300;++z){
           if(5*x+3*(100-x-z)+z/3.0==100&&x+z<=100)      
             cout << x << endl << z << endl;
           else 
           continue;
        }
    }
    return 0;
}