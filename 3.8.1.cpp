#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"input a:";
    cin>>a;
    cin.ignore(1024, '\n');
    cout<<"input b:";
    cin>>b;
    cin.ignore(1024, '\n');
    cout<<"input c:";
    cin>>c;
    cout<<a<<"\t"<<b<<"\t"<<c<<endl;
    return 0;
}