#include "PmergeMe.hpp"

int PmergeMe::counter = 0;

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& data) {
    counter = 0;
    fordJohnsonRecursive(data);
}

void PmergeMe::sortDeque(std::deque<int>& data) {
    counter = 0;
    fordJohnsonRecursive(data);
}

void PmergeMe::generateJacobsthalIndices(std::vector<size_t>& indices, size_t n) {
    size_t j0 = 0, j1 = 1;
    while (j1 < n) {
        indices.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
}

template <typename Iter, typename T>
Iter PmergeMe::myLowerBound(Iter low, Iter high, const T& value) {
    while (low != high) {
        Iter mid = low + (high - low) / 2;
        ++counter;
        if (*mid < value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

void PmergeMe::fordJohnsonRecursive(std::vector<int>& data) {
    if (data.size() <= 1) return;

    std::vector<int> mainChain;
    std::vector<int> pending;

    for (std::vector<int>::iterator it = data.begin(); it != data.end();) {
        int first = *it++;
        if (it != data.end()) {
            int second = *it++;
            ++counter;
            if (first < second) std::swap(first, second);
            mainChain.push_back(first);
            pending.push_back(second);
        } else {
            pending.push_back(first);
        }
    }

    fordJohnsonRecursive(mainChain);

    std::vector<size_t> jacobIndices;
    generateJacobsthalIndices(jacobIndices, pending.size());
    std::vector<bool> inserted(pending.size(), false);

    for (size_t i = 0; i < jacobIndices.size(); ++i) {
        size_t idx = jacobIndices[i];
        if (idx < pending.size() && !inserted[idx]) {
            std::vector<int>::iterator pos = myLowerBound(mainChain.begin(), mainChain.end(), pending[idx]);
            mainChain.insert(pos, pending[idx]);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            std::vector<int>::iterator pos = myLowerBound(mainChain.begin(), mainChain.end(), pending[i]);
            mainChain.insert(pos, pending[i]);
        }
    }

    data = mainChain;
}

void PmergeMe::fordJohnsonRecursive(std::deque<int>& data) {
    if (data.size() <= 1) return;

    std::deque<int> mainChain;
    std::deque<int> pending;

    for (std::deque<int>::iterator it = data.begin(); it != data.end();) {
        int first = *it++;
        if (it != data.end()) {
            int second = *it++;
            ++counter;
            if (first < second) std::swap(first, second);
            mainChain.push_back(first);
            pending.push_back(second);
        } else {
            pending.push_back(first);
        }
    }

    fordJohnsonRecursive(mainChain);

    std::vector<size_t> jacobIndices;
    generateJacobsthalIndices(jacobIndices, pending.size());
    std::vector<bool> inserted(pending.size(), false);

    for (size_t i = 0; i < jacobIndices.size(); ++i) {
        size_t idx = jacobIndices[i];
        if (idx < pending.size() && !inserted[idx]) {
            std::deque<int>::iterator pos = myLowerBound(mainChain.begin(), mainChain.end(), pending[idx]);
            mainChain.insert(pos, pending[idx]);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            std::deque<int>::iterator pos = myLowerBound(mainChain.begin(), mainChain.end(), pending[i]);
            mainChain.insert(pos, pending[i]);
        }
    }

    data = mainChain;
}
