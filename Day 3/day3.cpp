#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char symbols[] = "!@#$%^&*()_+/=-{}[]|:;<>?,";
    int sum = 0;

    ifstream file("day3.txt");
    string line;
    vector<vector<char>> arr;

    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        arr.push_back(row);
    }

    for (int r = 0; r < arr.size(); r++) {
        for (int c = 0; c < arr[r].size(); c++) {
            if (isdigit(arr[r][c])) {
                bool found = false;
                int i = 1;
                while (isdigit(arr[r][c+i])) {
                    i++;
                }
                for (int k = -1; k <= i; k++) {
                    
                    if (r < arr.size()-1 && (c+k) >=0 && (c+k) < arr[r].size() && arr[r+1][c+k] != '.') {
                        found = true;
                        break;
                    }
                    if (r > 0 && (c+k) >=0 && (c+k) < arr[r].size() && arr[r-1][c+k] != '.') {
                        found = true;
                        break;
                    }
                    if (c+i < arr.size() && arr[r][c+i] != '.') {
                        found = true;
                        break;
                    }
                    if (c-1 >= 0 && arr[r][c-1] != '.') {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    
                    string str;
                    for (int j = 0; j < i; j++) {
                        str += arr[r][c+j];
                    } 
                    cout << str << endl;
                    sum += stoi(str);
                }
                c+=i;
                
            }
        }
    }

    std::cout << sum << '\n';

    
}
