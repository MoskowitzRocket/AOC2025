#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <utility>

std::pair<long long,long long> split(std::string s, char delimiter);


int main()
{

    std::string str ;
    std::vector<std::string> ranges;
    std::vector<long long> vals;

    // std::ifstream infile("input.txt");
    std::ifstream infile("input2.txt");

    std::unordered_map<long long,bool> checkVal;


    bool inpSecOne = true;

    while(getline(infile, str))
    {
        if (inpSecOne)
        {
            
            if (str == "")
            {
                std::cout << "Found Empty Line" << std::endl;
                inpSecOne = false;
            } else {
                // std::cout << str << std::endl;
                ranges.push_back(str);
            }
        } else {
            // std::cout << str << std::endl;
            vals.push_back(std::stoll(str));
        }
            
    }

    // std::pair<long long, long long> rangetemp;
    // for (auto& r : ranges)
    // {
    //     rangetemp = split(r,'-');
    //     // std::cout << rangetemp.first << "-" << rangetemp.second << std::endl;

    //     for (int i = rangetemp.first; i <= rangetemp.second; i++)
    //     {
    //         if (checkVal[i])
    //         {
    //             break;
    //         } else {
    //             checkVal.insert({i,true});
    //         }
            
    //     }


    // }

    std::vector<std::pair<long long,long long>> rangelist;
    for (auto& r : ranges)
    {
        rangelist.push_back(split(r,'-'));
    }


    int count = 0;

    for (long long v : vals)
    {
        for (auto& [lo, hi] : rangelist)
        {
            if (v >= lo && v <= hi)
            {
                count++;
                break;  // no need to check more ranges
            }
        }
    }
    // for (const auto& v : vals)
    // {
    //     if (checkVal[v])
    //     {
    //         count ++;
    //     }
    // }


    std::cout << checkVal[3] << std::endl;
    std::cout << checkVal[1] << std::endl;

    std::cout << "Count: " << count << std::endl;


    // std::pair<long long, long long> test = split(ranges[0],'-');



    // std::cout << test.first << "-" << test.second << std::endl;

    // for (const auto& r : ranges)
    // {
    //     std::cout << r << std::endl;
    // }

    // for (const auto& v : vals)
    // {
    //     std::cout << v << std::endl;
    // }

   

    return 0;
}

std::pair<long long, long long> split(std::string s, char delimiter) 
{
    std::pair<long long, long long> valRange;
    std::string part;
    std::istringstream tokenStream(s);

    // Extract the first part
    if (std::getline(tokenStream, part, delimiter)) {
        valRange.first = std::stoll(part);
    }

    // Extract the second part
    if (std::getline(tokenStream, part, delimiter)) {
        valRange.second = std::stoll(part);
    }

    return valRange;
}