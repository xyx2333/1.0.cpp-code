#include<iostream>
using namespace std;
int main(){
    int m,n,i,min,a;
    cout<<"srlgzs"<<endl;
    cin>>m>>n;
    if(m<n)
    min=m;
    else
    min=n;
    for(i=1;i<=min;i++){
    if(m%i==0)
    a=i;
    else
    continue;
    }
    cout<<a;
    return 0;
}