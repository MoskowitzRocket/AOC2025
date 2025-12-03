#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <regex>

std::vector<std::string> split(const std::string &s, char delimiter);

long long checkString(std::string s);



int main() {
	std::ifstream inputFile("input.txt");
	if (!inputFile) {
		std::cerr << "Failed to open input.txt\n";
		return 1;
	}

	std::string line;
	std::getline(inputFile, line);
	inputFile.close();

	// std::cout << line << std::endl;

	std::vector<std::string> ranges = split(line, ',');

	std::vector<std::vector<std::string>> all_temps;

    


	for (int i = 0; i <= ranges.size() -1; i++)
	{
		// std::cout << ranges[i] << std::endl;

		std::vector<std::string> temp = split(ranges[i], '-');
		all_temps.push_back(temp);
	}

    long long result = 0;

    for (int i = 0; i < all_temps.size(); ++i)
    {
        std::cout << all_temps[i][0] << "-" << all_temps[i][1] << std::endl;
        long long lower = std::stoll(all_temps[i][0]);
        long long upper = std::stoll(all_temps[i][1]);

        for (long long j = lower; j <= upper; j++)
{
    // Call checkString only once and store the result
    long long checkResult = checkString(std::to_string(j));

    // Optional: Reduce debug output for performance
    if (j % 1000 == 0) // Print every 1000th iteration
    {
        std::cout << "J: " << j << "\tCheck Result: " << checkResult << std::endl;
    }

    result += checkResult;
}
    }

    

    std::cout << "\n\n----------\n----------\n---------\n" << result << "\n";

	return 0;
}

std::vector<std::string> split(const std::string &s, char delimiter) 
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

long long checkString(std::string s)
{
    int n = s.size();

    // length-1 numbers cannot be repeating patterns
    // if (n <= 1) return 0;
    if (n % 2 != 0) return 0;

    // Try all possible pattern lengths
    // for (int len = 1; len <= n / 2; ++len)
    int len = n / 2;
    // {
        // if (n % len != 0) continue;

        std::string pattern = s.substr(0, len);
        bool ok = true;

        for (int i = len; i < n; i += len)
        {
            if (s.substr(i, len) != pattern)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            return std::stoll(s);
    // }

    return 0;
}

