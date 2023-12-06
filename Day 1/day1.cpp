#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    std::ifstream file("day1.txt");
    std::string line;
    int total = 0;

    while (std::getline(file, line)) {
        int firstNum = -1;
        int lastNum = -1;

        for (char c : line) {
            if (std::isdigit(c)) {
                int num = c - '0';
                if (firstNum == -1) {
                    firstNum = num;
                }
                lastNum = num;
            }
        }

        if (firstNum != -1 && lastNum != -1) {
            total += firstNum*10 + lastNum;
        }
    }

    std::cout << total << std::endl;

    return 0;
}
