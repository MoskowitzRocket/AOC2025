#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <utility>

#include <algorithm>
// #include <cstdint>

std::pair<long long,long long> split(std::string s, char delimiter);

long long unique_range_count(std::vector<std::pair<long long, long long>>& rangelist);

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
            // vals.push_back(std::stoll(str));
        }
            
    }

   

    std::vector<std::pair<long long,long long>> rangelist;
    for (auto& r : ranges)
    {
        rangelist.push_back(split(r,'-'));
    }

    int count = 0;

    for (auto& r : rangelist)
    {
        count += (r.second - r.first);
    }

    long long result = unique_range_count(rangelist);

    

    // for (long long v : vals)
    // {
    //     for (auto& [lo, hi] : rangelist)
    //     {
    //         if (v >= lo && v <= hi)
    //         {
    //             count++;
    //             break;  // no need to check more ranges
    //         }
    //     }
    // }
   


    std::cout << checkVal[3] << std::endl;
    std::cout << checkVal[1] << std::endl;

    std::cout << "Count: " << count << std::endl;
    std::cout << "Result: " << result << std::endl;


   

   

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



long long unique_range_count(std::vector<std::pair<long long, long long>>& rangelist)
{
    if (rangelist.empty()) return 0;

    // Sort by start
    std::sort(rangelist.begin(), rangelist.end());

    std::vector<std::pair<long long,long long>> merged;
    merged.push_back(rangelist[0]);

    for (size_t i = 1; i < rangelist.size(); i++)
    {
        auto& [curL, curR] = rangelist[i];
        auto& [lastL, lastR] = merged.back();

        if (curL <= lastR + 1)  // Overlapping or touching
        {
            lastR = std::max(lastR, curR);  // Extend merged range
        }
        else
        {
            merged.push_back({curL, curR});
        }
    }

    long long total = 0;

    for (auto& [L, R] : merged)
        total += (R - L + 1);  // inclusive ranges

    return total;
}
