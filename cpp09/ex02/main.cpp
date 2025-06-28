#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cctype>

bool isPositiveInteger(const std::string &s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); ++i)
        if (!isdigit(s[i]))
            return false;
    return true;
}

#include <unordered_set>

bool hasDuplicates(const std::string &s)
{
    std::unordered_set<int> seen(data.begin(), data.end());
    return seen.size() != data.size();
}
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (!isPositiveInteger(arg))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        if (hasDuplicates(vec))
        {
            std::cerr << "Error: Duplicate numbers are not allowed" << std::endl;
            return 1;
        }
        int value;
        std::istringstream iss(arg);
        iss >> value;
        vec.push_back(value);
        deq.push_back(value);
    }

    std::cout << "Before:";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << " " << vec[i];
    std::cout << std::endl;

    clock_t startVec = clock();
    sorter.sortVector(vec);
    clock_t endVec = clock();

    std::cout << "After:";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << " " << vec[i];
    std::cout << std::endl;

    double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
    std::cout << "Time to process " << vec.size() << " elements with std::vector: " << timeVec << " us" << std::endl;
    std::cout << "Total comparisons (vector): " << PmergeMe::counter << std::endl;

    clock_t startDeq = clock();
    sorter.sortDeque(deq);
    clock_t endDeq = clock();

    double timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;
    std::cout << "Time to process " << deq.size() << " elements with std::deque: " << timeDeq << " us" << std::endl;
    std::cout << "Total comparisons (deque): " << PmergeMe::counter << std::endl;

    return 0;
}
