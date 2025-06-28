#ifndef PmergeMe_hpp
#define PmergeMe_hpp

#include <iostream>
#include <sstream>
#include <ctime>
#include <cctype>
#include <vector>
#include <deque>
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>


class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    bool validInput(int argc, char **argv);
    std::vector<int> getNumbers() const;

    void sortVector(std::vector<int>& data);
    void sortDeque(std::deque<int>& data);

    static int comp;

private:
    std::vector<int> Numbers;

    void fordJohnsonRecursive(std::vector<int>& data);
    void fordJohnsonRecursive(std::deque<int>& data);

    void generateJacobsthalIndices(std::vector<size_t>& indices, size_t n);

    template <typename Iter, typename T>
    Iter myLowerBound(Iter first, Iter last, const T& value, const T& maxValue);
};

#endif
