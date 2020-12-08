#include <iostream>
#include <string>
#include <cstring>

int main()
{
    std::string a = "刘剑锋";
    std::string a2 = "高雷雨";
    std::string b = "nb!";
    std::string b2 = "caiji";
    std::cout << a << b << std::endl;
    std::cout << a2 << b2 << std::endl;
    std::cout << a.size() << " " << b2.size() << std::endl;
    std::cout << b.at(1) << b.at(2) << std::endl;
    char c[] = "glynb";
    std::cout << strlen(c) << std::endl;
    char d[10];
    for (auto &n:d)
    std::cin >> n;
    int i;
    for (i = 1; i < 10; i++)
    {
        std::cout << d[i];
    }
    return 0;
}    