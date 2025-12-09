#include <fstream>
#include <iostream>
#include <vector>

int processLine(std::string s);

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
	int total = 0;
	for (auto & str : input_contents)
	{
		int a = processLine(str);
		total += a;
	}

	std::cout << "Total: " << total << "\n";



	return 0;

}

int processLine(std::string s)
{
	// for (size_t i = 0; i <= s.size()-1; ++i)
	// {
		// std::cout << s[i] << " ";
	// }

	// std::cout << "\n";

	// int n = (s[0] - '0') * 10 + (s[1] - '0');
	// std::cout << n << std::endl;

	int maxDigit = s[0] - '0';   // start with the first digit
	int maxDigitPos = 0;

	for (size_t i = 1; i < s.size()-1; ++i)
	{
		int current = s[i] - '0';

		if (current > maxDigit)
		{
			maxDigit = current;   // update max
			// std::cout << "Found new max (" << maxDigit 
			// 		<< ") at position " << i << "\n";
			maxDigitPos = i;
		}
		else
		{
			// std::cout << "Not larger\n";
		}
	}

	// std::cout << "Max 1st DIGIT: " << maxDigit << "\n" << "Position: " << maxDigitPos <<"\n";
	// std::cout << s[maxDigitPos] << "\n";

	int maxSecondDigit = s[maxDigitPos+1] - '0';
	int maxSecondDigitPos = maxDigitPos + 1;

	for (size_t i = maxDigitPos+1; i < s.size(); ++i)
	{
		int current = s[i] - '0';

		if (current > maxSecondDigit)
		{
			maxSecondDigit = current;   // update max
			// std::cout << "Found new max (" << maxSecondDigit 
					// << ") at position " << i << "\n";
			maxSecondDigitPos = i;
		}
		else
		{
			// std::cout << "Not larger\n";
		}
	}

	std::cout << "Max 1st DIGIT: " << maxDigit << " Position: " << maxDigitPos << " (" << s[maxDigitPos] << ")"
			  << "  Max 2nd DIGIT: " << maxSecondDigit << " Position: " << maxSecondDigitPos << " (" << s[maxSecondDigitPos] << ")\n";

	return maxDigit * 10 + maxSecondDigit;


	// return 0;
}