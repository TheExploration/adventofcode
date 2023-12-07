#include <bits/stdc++.h>
using namespace std;
int gearNum(vector<vector<char>> arr, int r, int c);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;

    ifstream file("day3.txt");
    string line;
    vector<vector<char>> arr;

    while (getline(file, line))
    {
        vector<char> row(line.begin(), line.end());
        arr.push_back(row);
    }

    for (int r = 0; r < arr.size(); r++)
    {
        for (int c = 0; c < arr[r].size(); c++)
        {
            int ratio = 1;
            int adj = 0;
            if (arr[r][c] == '*')
            {

                if ((c - 1) >= 0 && isdigit(arr[r][c - 1]))
                {
                    adj++;
                    ratio = ratio * gearNum(arr, r, c - 1);
                }
                if ((c + 1) < arr[r].size() && isdigit(arr[r][c + 1]))
                {
                    adj++;
                    ratio = ratio * gearNum(arr, r, c + 1);
                }
                if ((r - 1) >= 0 && isdigit(arr[r - 1][c]))
                {
                    adj++;
                    ratio = ratio * gearNum(arr, r - 1, c);
                }
                else
                {
                    if ((r - 1) >= 0 && (c - 1) >= 0 && isdigit(arr[r - 1][c - 1]))
                    {
                        adj++;
                        ratio = ratio * gearNum(arr, r - 1, c - 1);
                        if ((r - 1) >= 0 && (c + 1) < arr[r].size() && isdigit(arr[r - 1][c + 1]))
                        {
                            adj++;
                            ratio = ratio * gearNum(arr, r - 1, c + 1);
                        }
                    } else if ((r - 1) >= 0 && (c + 1) < arr[r].size() && isdigit(arr[r - 1][c + 1]))
                    {
                        adj++;
                        ratio = ratio * gearNum(arr, r - 1, c + 1);
                        if ((r - 1) >= 0 && (c - 1) >= 0 &&  isdigit(arr[r - 1][c - 1]))
                        {
                            adj++;
                            ratio = ratio * gearNum(arr, r - 1, c - 1);
                        }
                    }
                }
                if ((r + 1) < arr[r].size() && isdigit(arr[r + 1][c]))
                {
                    adj++;
                    ratio = ratio * gearNum(arr, r + 1, c);
                }
                else
                {
                    if ((r + 1) < arr.size() && (c - 1) >= 0 && isdigit(arr[r - 1][c - 1]))
                    {
                        adj++;
                        ratio = ratio * gearNum(arr, r + 1, c - 1);
                        if ((r + 1) < arr.size() && (c + 1) < arr[r].size() && isdigit(arr[r + 1][c + 1]))
                        {
                            adj++;
                            ratio = ratio * gearNum(arr, r + 1, c + 1);
                        }
                    } else
                    if ((r + 1) >= 0 && (c + 1) < arr[r].size() && isdigit(arr[r + 1][c + 1]))
                    {
                        adj++;
                        ratio = ratio * gearNum(arr, r + 1, c + 1);
                        if ((r + 1) < arr.size() && (c - 1) >= 0 && isdigit(arr[r + 1][c - 1]))
                        {
                            adj++;
                            ratio = ratio * gearNum(arr, r + 1, c - 1);
                        }
                    }
                }
            }
            if (adj == 2)
            {
                sum += ratio;
            }
        }
    }

    std::cout << sum << '\n';
}

int gearNum(vector<vector<char>> arr, int r, int c)
{
    int l = 1;
    while (isdigit(arr[r][c - l]))
    {
        l++;
    }
    int left = c - l + 1;

    string str;
    for (int j = 0; isdigit(arr[r][left + j]); j++)
    {
        str += arr[r][left + j];
    }
    if (str.empty())
    {
        return 0;
    }

    return stoi(str);
}
