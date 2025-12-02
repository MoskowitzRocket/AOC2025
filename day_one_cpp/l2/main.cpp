#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int procInstr(std::string shift);

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

    procInstr(input_contents[0]);

    int password = 0;
    int dial = 50;

    for (auto& line : input_contents)
    {
        int delta = 1;
        if (line[0] == 'L')
        {
            delta = -1;
        }
        
        int val =  abs(procInstr(line));
        for (int i = 0; i < val; i++)
        {
            dial += delta;
            dial = (dial % 100 + 100) % 100;
            if (dial == 0)
            {
                password++;
            }   

        }

        

        

    }

    std::cout << "Password: " << password << std::endl;


    return 0;
}


int procInstr(std::string shift)
{
    // std::cout << shift[0] << std::endl;

    int value = std::stoi(shift.substr(1));

    switch (shift[0]) {
        case 'L': 
            // std::cout << "Left:" << value << std::endl;
            // shiftby = std::stoi(shift);
            // std::cout << shiftby << std::endl; 
            value *= -1;
            break;
        case 'R':
            // std::cout << "Right:" << value << std::endl;
            break;

        default:
            break;

    }

    return value;
}