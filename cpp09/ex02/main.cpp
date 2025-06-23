#include "PmergeMe.hpp"

bool isPositiveInteger(const std::string& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i])) return false;
    }
    return !s.empty();
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!isPositiveInteger(arg)) {
            std::cerr << "Error" << std::endl;
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
    PmergeMe::sortVector(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    PmergeMe::sortDeque(deq);
    clock_t endDeq = clock();

    std::cout << "After:";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << " " << vec[i];
    std::cout << std::endl;

    double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
    double timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
    std::cout <<"counting :  " << PmergeMe::counter++;

    return 0;
}
