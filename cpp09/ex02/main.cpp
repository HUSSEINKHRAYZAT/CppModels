#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <deque>

extern int comp;

int main(int argc, char **argv)
{
    PmergeMe input;
    int a = 0;
    int b = 0;

    if (!input.validInput(argc, argv))
    {
        return 0;
    }
    else
    {

        std::vector<int> vec = input.getNumbers();
        std::deque<int> deq(vec.begin(), vec.end());

        std::cout << "Before:";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << " " << vec[i];
        std::cout << std::endl;

        comp = 0;
        clock_t v_start = clock();
        std::vector<int> inputed_vec = input.fordJohnsonVector(vec);
        clock_t v_end = clock();
        double v_time = 1e6 * (v_end - v_start) / CLOCKS_PER_SEC;
        a = comp;

        comp = 0;
        clock_t d_start = clock();
        std::deque<int> inputed_deq = input.fordJohnsonDeque(deq);
        clock_t d_end = clock();
        double d_time = 1e6 * (d_end - d_start) / CLOCKS_PER_SEC;
        b = comp;

        std::cout << "After:";
        for (size_t i = 0; i < inputed_vec.size(); ++i)
            std::cout << " " << inputed_vec[i];
        std::cout << std::endl<< std::endl;

        std::cout << "Time to process a range of " << vec.size()
                  << " elements with std::vector : ";
        std::cout << std::fixed << std::setprecision(5) << v_time << " us" << std::endl;

        std::cout << "Time to process a range of " << deq.size()
                  << " elements with std::deque : ";
        std::cout << std::fixed << std::setprecision(5) << d_time << " us" << std::endl<< std::endl;
        if ((a > 67 || b > 67) && input.getNumbers().size() == 21)
            std::cout << "Comparaisons greater than 66\n" << std::endl;
        else
        {
            std::cout << "Counting the vector comparaisons:  " << a << std::endl;
            std::cout << "Counting the deque comparaisons:  " << b << std::endl<< std::endl;
        }
    }
    return 0;
}
