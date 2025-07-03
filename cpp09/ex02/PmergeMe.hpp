#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <algorithm>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    bool validInput(int argc, char **argv);
    std::vector<int> getNumbers() const;

    std::vector<int> fordJohnsonVector(const std::vector<int>& vec);
    std::deque<int> fordJohnsonDeque(const std::deque<int>& deq);

private:
    std::vector<int> Numbers;
    std::vector<int> generateJacobSequence(int limit);
    std::vector<int> generateJacobIndices(int n);

    void binarySearchVector(std::vector<int>& vec, int value, int maxValue);
    void buildPairsVector(const std::vector<int>& arr, std::vector<int>& Main, std::vector<int>& Pending, bool& Unpaired);
    std::vector<int> reorderPendingVector(const std::vector<int>& Main, const std::vector<int>& sortedMain, const std::vector<int>& Pending, bool Unpaired);
    void insertPendingVector(std::vector<int>& result, const std::vector<int>& pending, const std::vector<int>& sortedMain);
    
    void binarySearchDeque(std::deque<int>& deq, int value, int maxValue);
    void buildPairsDeque(const std::deque<int>& arr, std::deque<int>& Main, std::deque<int>& Pending, bool& Unpaired);
    std::deque<int> reorderPendingDeque(const std::deque<int>& Main, const std::deque<int>& sortedMain, const std::deque<int>& Pending, bool Unpaired);
    void insertPendingDeque(std::deque<int>& result, const std::deque<int>& pending, const std::deque<int>& sortedMain);
};

#endif 