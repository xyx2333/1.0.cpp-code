#include<iostream>

int main(){
    int a[2][2], i, j, sum;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cin >> a[i][j];
            sum +=a[i][j];
        }
    }
     std::cout << sum;
    return 0;    
}