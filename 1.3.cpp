#include<iostream>
using namespace std;
int main(){
    float x,y;
    cout<<"please input x,y"<<endl;
    cin>>x>>y;
    bool c1,c2,c3,c4;
    c1=(x-2)*(x-2)+(y-2)*(y-2)<=1;   
    c2=(x-2)*(x-2)+(y+2)*(y+2)<=1;
    c3=(x+2)*(x+2)+(y-2)*(y-2)<=1;
    c4=(x+2)*(x+2)+(y+2)*(y+2)<=1;
    if(c1||c2||c3||c4){
    cout<<"h=10";
    }
    else {
    cout<<"h=0";
    }
    return 0;
}