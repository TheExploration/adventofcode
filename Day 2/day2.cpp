#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream file("day2.txt");
    string line;
    int id = 0;

    while (getline(file, line)) {
        int red = 0;
        int blue = 0;
        int green = 0;
        bool possible = false;
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line.at(i))) {
                int temp = 0;
                if (isdigit(line.at(i-1))) {
                    temp = 10*(line.at(i-1) - '0');
                }

                if (line.substr(i+2, 4) == "blue") {
                    blue=line.at(i) - '0' + temp;
                   
                } else if (line.substr(i+2, 5) == "green") {
                    green=line.at(i) - '0'+ temp;
                  
                } else if (line.substr(i+2, 3) == "red") {
                    red=line.at(i) - '0'+ temp;
                    
                }
                
            } else if (line.at(i) == ';') {
                if (red <= 12 && green <= 13 && blue <= 14) {
                    blue = 0;
                    green = 0;
                    red = 0;
                } else {
                    possible = false;
                    break;
                }
            }
            if (i == line.length() - 1) {
                if (red <= 12 && green <= 13 && blue <= 14) {
                    blue = 0;
                    green = 0;
                    red = 0;
                    possible = true;
                } else {
                    possible = false;
                    break;
                }
            }
        }
       
        if (possible) {
            int length = line.find(":") -5;
            id += stoi(line.substr(5, length));
        }

    }

    std::cout << id << '\n';

    
}
