#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream file("day2.txt");
    string line;
    int power = 0;

    while (getline(file, line)) {
        int minRed = 0;
        int minBlue = 0;
        int minGreen = 0;
        
        for (int i = 0; i < line.length(); i++) {
            int temp = 0;
            if (isdigit(line.at(i))) {
                if (isdigit(line.at(i-1))) {
                    temp = 10*(line.at(i-1) - '0');
                }
                if (line.substr(i+2, 4) == "blue") {
                    if (minBlue < line.at(i) - '0' + temp) {
                        minBlue = line.at(i) - '0' + temp;
                        
                    }
                } else if (line.substr(i+2, 5) == "green") {
                    if (minGreen < line.at(i) - '0'+ temp) {
                        minGreen = line.at(i) - '0'+ temp;
                        
                    }
                    
                } else if (line.substr(i+2, 3) == "red") {
                    if (minRed < line.at(i) - '0'+ temp) {
                        minRed = line.at(i) - '0'+ temp;
                        
                    }
                }
                
                
          
            }
        }
       
        
        power += minRed * minBlue * minGreen;
    }
   
    std::cout << power << '\n';

    
}
