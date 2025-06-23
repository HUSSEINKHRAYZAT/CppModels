#include "PmergeMe.hpp"

int PmergeMe::counterV = 0;
int PmergeMe::counterD = 0;

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& data) {
    fordJohnsonRecursive(data);
}

void PmergeMe::sortDeque(std::deque<int>& data) {
    fordJohnsonRecursive(data);
}

template <typename Container>
void PmergeMe::fordJohnsonRecursive(Container& data) {
    if (data.size() <= 1) return;

    Container mainChain;
    Container pending;

    

    typename Container::iterator it = data.begin();
    while (it != data.end()) {
        typename Container::value_type first = *it;
        ++it;
        if (it != data.end()) {
            typename Container::value_type second = *it;
            ++it;
            if (first < second){
                std::swap(first, second);
               counter++;
            }
            mainChain.push_back(first);
            pending.push_back(second);
        } else {
            pending.push_back(first);
        }
    }

    fordJohnsonRecursive(mainChain);

    for (typename Container::iterator pit = pending.begin(); pit != pending.end(); ++pit) {
        typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), *pit);
        mainChain.insert(pos, *pit);
    }

    data = mainChain;
    
}








