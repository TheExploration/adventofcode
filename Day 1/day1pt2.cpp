#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    std::ifstream file("day1.txt");
    std::string line;
    int total = 0;

    while (std::getline(file, line))
    {
        int firstNum = -1;
        int lastNum = -1;

        for (int i = 0; i < line.length(); i++)
        {
            if (isdigit(line.at(i)))
            {
                if (firstNum == -1)
                {
                    firstNum = line.at(i) - '0';
                }
            }
            else if (line.substr(i, i + 3) == "one")
            {
                

            }
        }

        if (firstNum != -1 && lastNum != -1)
        {
            total += firstNum * 10 + lastNum;
        }
    }

    std::cout << total << std::endl;

    return 0;
}
