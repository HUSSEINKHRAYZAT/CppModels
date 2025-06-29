#include "PmergeMe.hpp"

// Static comparison counter
int PmergeMe::comp = 0;

// calling the ford and reset the comp to zero

void PmergeMe::sortVector(std::vector<int>& data) {
    comp = 0;
    fordJohnsonRecursive(data);
}

void PmergeMe::sortDeque(std::deque<int>& data) {
    comp = 0;
    fordJohnsonRecursive(data);
}

// --------- constractors,getters ,validator functions
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { this->Numbers = other.Numbers; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
        this->Numbers = other.Numbers;
    return *this;
}
std::vector<int> PmergeMe::getNumbers() const {
    return this->Numbers;
}

bool PmergeMe::validInput(int argc, char **argv) {
    int i = 1;
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return false;
    }
    while (i < argc) {
        if (argv[i][0] == '-') {
            std::cerr << "Error" << std::endl;
            return false;
        }
        for (size_t j = 0; j < std::strlen(argv[i]); ++j) {
            if (!std::isdigit(argv[i][j])) {
                std::cerr << "Error" << std::endl;
                return false;
            }
        }
        long num = std::strtol(argv[i], NULL, 10);
        if (num < 0 || num > INT_MAX) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        if (std::find(Numbers.begin(), Numbers.end(), (int)num) != Numbers.end()) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        Numbers.push_back((int)num);
        ++i;
    }
    return true;
}
// ----------------------------jacobthal------------------------------------------------------------------------
void PmergeMe::generateJacobsthalIndices(std::vector<size_t>& indices, size_t n) {
    indices.clear();
    if (n == 0) return;

    size_t j0 = 0;
    size_t j1 = 1;
    std::set<size_t> added;

    while (j1 < n) {
        if (added.find(j1) == added.end()) {
            indices.push_back(j1);
            added.insert(j1);
        }
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }

    if (added.find(0) == added.end()) {
        indices.insert(indices.begin(), 0);
    }
}
// -------------------------------ft_lowerbound
template <typename Iter, typename T>
Iter PmergeMe::myLowerBound(Iter first, Iter last, const T& value, const T& maxValue) {
    Iter limit = last;
    for (Iter it = first; it != last; ++it) {
        if (*it == maxValue) {
            limit = it;
            break;
        }
    }

    Iter low = first;
    Iter high = limit;

    while (low < high) {
        Iter mid = low + (high - low) / 2;
        ++comp;
        if (*mid < value)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}
// ----------------------------fordJohnson--------------------------
void PmergeMe::fordJohnsonRecursive(std::vector<int>& data) {
    if (data.size() <= 1) return;

    std::vector<int> mainChain;
    std::vector<int> pending;

    for (std::vector<int>::iterator it = data.begin(); it != data.end();) {
        int first = *it++;
        if (it != data.end()) {
            int second = *it++;
            ++comp;
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
            ++comp;
            std::vector<int>::iterator pos = myLowerBound(
                mainChain.begin(), mainChain.end(), pending[idx],
                idx < mainChain.size() ? mainChain[idx] : INT_MAX);
            mainChain.insert(pos, pending[idx]);
            inserted[idx] = true;
            if (Numbers.size() == 21 && comp > 66) {
                std::cerr << "Error: Exceeded 66 comparisons on 21 elements." << std::endl;
                exit(1);
            }
        }
    }

    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            std::vector<int>::iterator pos = myLowerBound(
                mainChain.begin(), mainChain.end(), pending[i],
                i < mainChain.size() ? mainChain[i] : INT_MAX);
            mainChain.insert(pos, pending[i]);
            inserted[i] = true;
            if (Numbers.size() == 21 && comp > 66) {
                std::cerr << "Error: Exceeded 66 comparisons on 21 elements." << std::endl;
                exit(1);
            }
        }
    }

    if (mainChain.size() != data.size()) {
        std::cerr << "Logic error: final sorted size mismatch!" << std::endl;
        exit(1);
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
            ++comp;
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
            ++comp;
            std::deque<int>::iterator pos = myLowerBound(
                mainChain.begin(), mainChain.end(), pending[idx],
                idx < mainChain.size() ? mainChain[idx] : INT_MAX);
            mainChain.insert(pos, pending[idx]);
            inserted[idx] = true;
            if (Numbers.size() == 21 && comp > 66) {
                std::cerr << "Error: Exceeded 66 comparisons on 21 elements." << std::endl;
                exit(1);
            }
        }
    }

    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            std::deque<int>::iterator pos = myLowerBound(
                mainChain.begin(), mainChain.end(), pending[i],
                i < mainChain.size() ? mainChain[i] : INT_MAX);
            mainChain.insert(pos, pending[i]);
            inserted[i] = true;
            if (Numbers.size() == 21 && comp > 66) {
                std::cerr << "Error: Exceeded 66 comparisons on 21 elements." << std::endl;
                exit(1);
            }
        }
    }

    if (mainChain.size() != data.size()) {
        std::cerr << "Logic error: final sorted size mismatch!" << std::endl;
        exit(1);
    }

    data = mainChain;
}

