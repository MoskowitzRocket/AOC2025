#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int procInstr(std::string shift);

int main() {

    std::vector<std::vector<std::string>> grid;
    std::string line;

    std::ifstream infile("input2.txt");

    while (std::getline(infile, line)) {

        // skip empty lines
        if (line.find_first_not_of(" \t") == std::string::npos)
            continue;

        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        // split by whitespace
        while (ss >> cell) {
            row.push_back(cell);
        }

        grid.push_back(row);
    }

    // Example: print what we parsed
    // std::cout << "Parsed grid:\n";
    // for (auto& row : grid) {
    //     for (auto& c : row)
    //         std::cout << c << " ";
    //     std::cout << "\n";
    // }

    int cols = grid[0].size();
    std::vector<std::vector<std::string>> columns(cols);

    for (auto& row : grid) {
        for (int c = 0; c < row.size(); c++) {
            columns[c].push_back(row[c]);
        }
    }

    long long total = 0;

    for (auto& col : columns)
    {
        std::string op = col.back();
        
        long long result = std::stoll(col[0]);
        
        for (int i = 1; i < col.size()- 1; i++)
        {
            // std::cout << col[i] << " ";
            long long value = std::stoi(col[i]);

            if (op == "+")
            {
                result += value;
            }                
            else if (op == "*")
            {
                result *= value;
            }             

        }
        // std::cout << std::endl;
        total += result;
    }

    std::cout << "Result: " << total << "\n";

    return 0;
}
