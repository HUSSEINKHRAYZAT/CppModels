#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sortVector(std::vector<int>& data);
    void sortDeque(std::deque<int>& data);

    static int counter;

private:
    void fordJohnsonRecursive(std::vector<int>& data);
    void fordJohnsonRecursive(std::deque<int>& data);

    void generateJacobsthalIndices(std::vector<size_t>& indices, size_t n);

    template <typename Iter, typename T>
    Iter myLowerBound(Iter low, Iter high, const T& value);
};

#endif
