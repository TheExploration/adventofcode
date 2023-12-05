#include <fstream>
#include <string>
#include <iostream>


int main()
	{
        int temp = 0
	std::ifstream Infile("day1.txt");
	long Total = 0;
	if (Infile.is_open())
		{
		std::string Line;
		int Temp;
		while (getline(Infile, Line))
			{
			int First = -1;
			int Last = -1;
			for (int i = 0; i < Line.length(); i++)
				{
                    	if (isdigit(Line.at(i)))
		Temp = Line.at(i) - '0';
	if (Line.substr(i, 3) == "one")
		Temp =  1;
	if (Line.substr(i, 3) == "two")
		Temp =  2;
	if (Line.substr(i, 5) == "three")
		Temp =  3;
	if (Line.substr(i, 4) == "four")
		Temp =  4;
	if (Line.substr(i, 4) == "five")
		Temp =  5;
	if (Line.substr(i, 3) == "six")
		Temp =  6;
	if (Line.substr(i, 5) == "seven")
		Temp =  7;
	if (Line.substr(i, 5) == "eight")
		Temp =  8;
	if (Line.substr(i, 4) == "nine")
		Temp =  9;

				
				if (Temp > 0)
					{
					if (First == -1)
						First = Temp;
					Last = Temp;
					}
				}
			Total += (First * 10) + Last;
			}
		std::cout << "Total: " << Total << std::endl;
		}

        
	}
