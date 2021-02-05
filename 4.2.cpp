#include <iostream>
#include <string>
using namespace std;

int main ()
{
    std::cout << "Do you want to give up?";
    string is;
    std::cin >> is;
    if (is == "yes")
    {
        std::cout << "You are loser forever!";
    }
    if (is == "no")
    {
        std::cout << "Fighting, just do it!";
    }
    if (is != "yes" && is != "no") 
    std::cout << "You must make a choice!";
    return 0;
}