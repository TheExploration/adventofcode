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
            int temp=-1;
            if (isdigit(line.at(i)))
            {
                if (firstNum == -1)
                {
                    firstNum = line.at(i) - '0';
                } 
                lastNum = line.at(i) - '0';
                
            }
            else if (line.substr(i, 3) == "one")
            {   
                temp = 1;

            } else if (line.substr(i,3) == "two") {
                temp = 2;

            } else if (line.substr(i, 5) == "three") {
                temp = 3;
            } else if (line.substr(i, 4) == "four") {
                temp = 4;
            } else if (line.substr(i,4) == "five") {
                temp = 5;
            } else if (line.substr(i,3) == "six") {
                temp = 6;
            } else if (line.substr(i,5) == "seven") {
                temp = 7;
            } else if (line.substr(i,5) == "eight") {
                temp = 8;
            } else if (line.substr(i,4) == "nine") {
                temp = 9;
            }

            if (firstNum == -1) {
                firstNum = temp;
            } 
            if (temp != -1) {
                lastNum = temp;
            }
            
        }
         
        

        if (firstNum != -1 && lastNum != -1)
        {
            total += firstNum * 10 + lastNum;
        }
    }

    std::cout << total << endl;

    return 0;
}
