#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream file("input2.txt");
    
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    vector<vector<char>> matrix;
    string line;
    
    // Read line by line
    while (getline(file, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        matrix.push_back(row);
    }
    
    file.close();
    
    // // Display the matrix
    // for (const auto& row : matrix) {
    //     for (char c : row) {
    //         cout << c ;
    //     }
    //     cout << endl;
    // }
    
    int cols = matrix[0].size();

    std::vector<std::vector<char>> matrix_t(cols);
    for (auto& row : matrix)
    {
        for (int c = 0; c < row.size(); c++)
        {
            matrix_t[c].push_back(row[c]);
        }
    }

    // for (const auto& row : matrix_t) {
    //     for (char c : row) {
    //         cout << c ;
    //     }
    //     cout << endl;
    // }

    // cout << "TEST TEST TEST\n\n\nTEST TEST TEST\n\n\n______________\n\n\n";

    std::vector<std::string> final_data;

    for (const auto& row : matrix_t) {
    std::string str(row.begin(), row.end());
    final_data.push_back(str);
    }

    
    long long count = 0;
   // Print every 4th column
    for (int i = 0; i < final_data.size(); i += 4)
{
    try {
        cout << "Trying to convert: [" << final_data[i] << "]" << endl;
        long long result = std::stoll(final_data[i].substr(0, 3));        
        char op = final_data[i][3];
        if (op == '*')
        {
            result *= std::stoll(final_data[i+1]) * std::stoll(final_data[i+2]) * std::stoll(final_data[i+3]);
        } else if (op =='+')
        {
             result += std::stoll(final_data[i+1]) + std::stoll(final_data[i+2]) + std::stoll(final_data[i+3]);
        }
        count += result;
    } catch (const std::invalid_argument& e) {
        cerr << "Invalid argument at index " << i << ": [" << final_data[i] << "]" << endl;
        cerr << "Length: " << final_data[i].length() << endl;
    }
}
    
    std::cout << count << endl;
    // std::cout << matrix_t[0].size() << endl;
    // cout << matrix_t.size() << endl;

    
    

    return 0;
}