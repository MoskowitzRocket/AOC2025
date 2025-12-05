#include <fstream>
#include <vector>
#include <iostream>
#include <filesystem>
#include <iomanip> // for setw

namespace fs = std::filesystem;

int main()
{
    // Make snapshot directory if not exists
    fs::create_directory("tmp");

    // Track total changes across all iterations
    int totalSum = 0;

    // Read original input
    std::vector<std::string> input_contents;
    std::string str;

    {
        std::ifstream infile("input.txt");
        while (getline(infile, str)) {
            input_contents.push_back(str);
        }
    }

    // Current working matrix
    std::vector<std::vector<char>> fullMatrix;

    for (const auto &line : input_contents) {
        fullMatrix.emplace_back(line.begin(), line.end());
    }

    int iteration = 0;

    while (true) {
        int sum = 0;

        // Output filename
        std::ostringstream ss;
        ss << "tmp/step_" << std::setw(3) << std::setfill('0') << iteration << ".txt";
        std::string outFileName = ss.str();

        std::ofstream output(outFileName);

        // Process grid
        for (int i = 0; i < fullMatrix.size(); i++) {
            for (int j = 0; j < fullMatrix[i].size(); j++) {

                int count = 0;

                // Check neighbors
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {

                        if (di == 0 && dj == 0)
                            continue;

                        int ni = i + di;
                        int nj = j + dj;

                        if (ni >= 0 && ni < fullMatrix.size() &&
                            nj >= 0 && nj < fullMatrix[ni].size())
                        {
                            if (fullMatrix[ni][nj] == '@')
                                count++;
                        }
                    }
                }

                // Apply rule
                if (count < 4 && fullMatrix[i][j] == '@') {
                    output << 'x';
                    sum++;
                } else {
                    output << fullMatrix[i][j];
                }
            }
            output << "\n";
        }

        output.close();

        std::cout << "Iteration " << iteration << ": sum = " << sum << "\n";

        totalSum += sum;

        if (sum == 0)
            break;

        // Load new matrix from the latest snapshot
        std::ifstream nextIn(outFileName);
        fullMatrix.clear();

        while (getline(nextIn, str)) {
            fullMatrix.emplace_back(str.begin(), str.end());
        }

        iteration++;
    }

    std::cout << "\nFinal Total Sum: " << totalSum << "\n";

    return 0;
}
