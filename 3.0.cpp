#include<iostream>
using namespace std;

int main()
{
    int n,i,j,k = 1;
    cin >> n;
    for (i = n; i >= 0; i--)
    {
        for (j = 1; j <= i; j++)
        {
            if (k <= 9)
            cout << 0 << k; 
            else
            cout << k;
            k++;
        }
        cout << endl;
    }
    return 0;
}