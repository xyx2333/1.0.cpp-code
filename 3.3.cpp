#include <iostream>
#include <vector>

int main()
{
    std::vector<double> allnum;
    double n;
    int num = 0;
    while (std::cin >> n)
    {   
        if (std::cin.get() == '\n') //遇到回车，终止
            break;
        allnum.push_back(n);
        num++;
    }
    for (int i = 0; i < num; i++)
    {   
        int j;
        for (j = i + 1; j < num; j++)
        {
            if (allnum.at(i) != allnum.at(j))
            continue;
            else
            break;
        }
        if (j == num)
        std::cout << allnum.at(i) << " ";
    }
    return 0;
}