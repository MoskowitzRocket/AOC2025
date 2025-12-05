#include <fstream>
#include <vector>
#include <iostream>



int main()
{

    std::string str ;
    std::vector<std::string> input_contents;


    std::ifstream infile("input.txt");

    std::ofstream output("output.txt");

    while(getline(infile, str))
    {
        input_contents.push_back(str);
    }

    std::vector<std::vector<char>> fullMatrix;

    for (const auto& line : input_contents) {
        std::vector<char> row(line.begin(), line.end());
        fullMatrix.push_back(row);
    }

    int sum = 0;

    for (int i = 0; i < fullMatrix.size(); i++) {
    for (int j = 0; j < fullMatrix[i].size(); j++) {

        int count = 0;

        // Check all 8 neighbors
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {

                // Skip the cell itself
                if (di == 0 && dj == 0)
                    continue;

                int ni = i + di;
                int nj = j + dj;

                // Bounds check
                if (ni >= 0 && ni < fullMatrix.size() &&
                    nj >= 0 && nj < fullMatrix[ni].size()) 
                {
                    if (fullMatrix[ni][nj] == '@')
                        count++;
                }
            }
        }
        if (count < 4) {
            if (fullMatrix[i][j] == '@') {
                std::cout << "x";
                output << "x";
                sum++;
            } else {
              std::cout << fullMatrix[i][j];   
              output << fullMatrix[i][j];
            }
        } else {
            std::cout << fullMatrix[i][j];
            output << fullMatrix[i][j];

        }
        // std::cout << count << " 
    }
    std::cout << "\n";

    output << "\n";

}

    output.close();

    std::cout << "\n\n\n-----\n|||||\nsum: "  << sum << "\n|||||\n-----"; 

    // std::cout << fullMatrix[0][0] << fullMatrix[0][1] << fullMatrix[0][2] << fullMatrix[0][3];



    return 0;
}