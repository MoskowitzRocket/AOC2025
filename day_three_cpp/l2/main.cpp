#include <fstream>
#include <iostream>
#include <vector>

long long processLine(std::string s);

int main() {

	std::string str ;
    std::vector<std::string> input_contents;


    std::ifstream infile("input.txt");

    while(getline(infile, str))
    {
        input_contents.push_back(str);
    }

    std::cout << "Length of input contents: " << input_contents.size() << std::endl;
    std::cout << "0th input: " << input_contents[0] << std::endl;
    std::cout << "Last input: " << input_contents[input_contents.size()-1] << std::endl;


	// std::cout << processLine(input_contents[0]) << "\n";
	long long total = 0;
	for (auto & str : input_contents)
	{
		long long a = processLine(str);
		total += a;
	}

	std::cout << "Total: " << total << "\n";



	return 0;

}

long long processLine( std::string s)
{
    const int K = 12; // number of digits to pick
    if (s.size() < K) {
        std::cerr << "String too short\n";
        return -1;
    }

    std::string result;
    result.reserve(K);

    size_t start = 0;

    for (int picked = 0; picked < K; picked++)
    {
        // How many chars we need left after picking this one
        int remaining = K - picked - 1;

        // We can only search up to this index
        size_t end = s.size() - remaining;

        // Find max digit in s[start .. end-1]
        char best = '0';
        size_t bestPos = start;

        for (size_t i = start; i < end; i++)
        {
            if (s[i] > best)
            {
                best = s[i];
                bestPos = i;
            }
        }

        result += best;
        start = bestPos + 1; // continue AFTER the chosen digit
    }

    std::cout << "Selected digits: " << result << "\n";

    return std::stoll(result);  // convert 12-digit string to a number
}