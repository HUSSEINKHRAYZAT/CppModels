#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe sorter;

    if (!sorter.validInput(argc, argv))
        return 1;

    std::vector<int> vec = sorter.getNumbers();
    std::deque<int> deq(vec.begin(), vec.end());

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
    std::cout << "Total comparisons (vector): " << sorter.comp << std::endl;

    clock_t startDeq = clock();
    sorter.sortDeque(deq);
    clock_t endDeq = clock();

    double timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;
    std::cout << "Time to process " << deq.size() << " elements with std::deque: " << timeDeq << " us" << std::endl;
    std::cout << "Total comparisons (deque): " << sorter.comp << std::endl;

    return 0;
}
