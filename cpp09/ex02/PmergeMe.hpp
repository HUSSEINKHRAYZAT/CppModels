#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <algorithm>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    static void sortVector(std::vector<int>& data);
    static void sortDeque(std::deque<int>& data);
    static int counterV;
    static int counterD;  

private:
    template <typename Container>
    static void fordJohnsonRecursive(Container& data);
};

#endif 

