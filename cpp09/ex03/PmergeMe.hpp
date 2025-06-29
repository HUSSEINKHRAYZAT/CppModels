#ifndef PmergeMe_hpp
#define PmergeMe_hpp

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <cctype>


class PmergeMe {
public:
        static int comp;
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        std::vector<int> getNumbers() const;
        bool validInput(int argc, char **argv);
        void sortVector(std::vector<int>& data);
        void sortDeque(std::deque<int>& data);
private:
    std::vector<int> Numbers;

    void fordJohnsonRecursive(std::vector<int>& data);
    void fordJohnsonRecursive(std::deque<int>& data);
    void generateJacobsthalIndices(std::vector<size_t>& indices, size_t n);
    template <typename Iter, typename T>
    Iter myLowerBound(Iter first, Iter last, const T& value, const T& maxValue);
};

#endif
