#include "PmergeMe.hpp"
int comp = 0;

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : Numbers(other.Numbers) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
        Numbers = other.Numbers;
    return *this;
}

bool PmergeMe::validInput(int argc, char **argv)
{
    Numbers.clear();
    if (argc == 1)
    {
        std::cout << "No Numbers Entered" << std::endl;
        return false;
    }

    for (int i = 1; i < argc; ++i)
    {
        bool invalid = false;
        for (size_t j = 0; j < std::strlen(argv[i]); ++j)
        {
            if (!std::isdigit(argv[i][j]))
            {
                invalid = true;
                break;
            }
        }
        if (argv[i][0] == '-' || invalid)
        {
            std::cout << "Error" << std::endl;
            return false;
        }

        long num = std::strtol(argv[i], NULL, 10);
        if (num < 0 || num > INT_MAX || std::find(Numbers.begin(), Numbers.end(), static_cast<int>(num)) != Numbers.end())
        {
            std::cout << "Error" << std::endl;
            return false;
        }
        Numbers.push_back(static_cast<int>(num));
    }
    return true;
}

std::vector<int> PmergeMe::getNumbers() const
{
    return Numbers;
}
// -------------------jacob part--------------------------------------
std::vector<int> PmergeMe::generateJacobSequence(int limit)
{
    std::vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);
    while (seq.back() < limit)
        seq.push_back(seq.back() + 2 * seq[seq.size() - 2]);
    return seq;
}

std::vector<int> PmergeMe::generateJacobIndices(int n)
{
    std::vector<int> jacob = generateJacobSequence(n);
    std::vector<int> result;
    for (size_t i = 1; i < jacob.size(); ++i)
    {
        for (int j = std::min(jacob[i], n); j > jacob[i - 1]; --j)
            result.push_back(j);
    }
    return result;
}

// -------------------Vector part--------------------------------------
void PmergeMe::binarySearchVector(std::vector<int> &vec, int value, int maxValue)
{
    int limit = std::find(vec.begin(), vec.end(), maxValue) - vec.begin();
    int low = 0, high = limit;
    while (low < high)
    {
        int mid = (low + high) / 2;
        ++comp;
        if (vec[mid] > value)
            high = mid;
        else
            low = mid + 1;
    }
    vec.insert(vec.begin() + low, value);
}
void PmergeMe::buildPairsVector(const std::vector<int> &arr, std::vector<int> &Main, std::vector<int> &Pending, bool &Unpaired)
{
    size_t pairs = arr.size() / 2;
    Unpaired = arr.size() % 2;
    for (size_t i = 0; i < pairs * 2; i += 2)
    {
        ++comp;
        int a = arr[i], b = arr[i + 1];
        if (a > b)
        {
            Main.push_back(a);
            Pending.push_back(b);
        }
        else
        {
            Main.push_back(b);
            Pending.push_back(a);
        }
    }
    if (Unpaired)
        Pending.push_back(arr.back());
}
std::vector<int> PmergeMe::reorderPendingVector(const std::vector<int> &Main, const std::vector<int> &sortedMain, const std::vector<int> &Pending, bool Unpaired)
{
    std::vector<int> reordered(sortedMain.size());
    for (size_t i = 0; i < sortedMain.size(); ++i)
        reordered[i] = Pending[std::find(Main.begin(), Main.end(), sortedMain[i]) - Main.begin()];
    if (Unpaired)
        reordered.push_back(Pending.back());
    return reordered;
}
void PmergeMe::insertPendingVector(std::vector<int> &result, const std::vector<int> &pending, const std::vector<int> &sortedMain)
{
    if (pending.size() == 1)
    {
        binarySearchVector(result, pending[0], INT_MAX);
        return;
    }
    std::vector<int> indices = generateJacobIndices((int)pending.size());
    for (size_t i = 0; i < indices.size(); ++i)
    {
        int idx = indices[i] - 1;
        binarySearchVector(result, pending[idx], idx < (int)sortedMain.size() ? sortedMain[idx] : INT_MAX);
    }
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return vec;
    if (vec.size() == 2)
    {
        std::vector<int> res = vec;
        ++comp;
        if (res[0] > res[1])
            std::swap(res[0], res[1]);
        return res;
    }
    std::vector<int> Main, Pending;
    bool Unpaired;
    buildPairsVector(vec, Main, Pending, Unpaired);
    std::vector<int> sortedMain = fordJohnsonVector(Main);
    std::vector<int> reordered = reorderPendingVector(Main, sortedMain, Pending, Unpaired);
    std::vector<int> Result = sortedMain;
    insertPendingVector(Result, reordered, sortedMain);
    return Result;
}

// -------------------Deque part--------------------------------------
void PmergeMe::binarySearchDeque(std::deque<int> &deq, int value, int maxValue)
{
    int limit = std::find(deq.begin(), deq.end(), maxValue) - deq.begin();
    int low = 0, high = limit;
    while (low < high)
    {
        int mid = (low + high) / 2;
        ++comp;
        if (deq[mid] > value)
            high = mid;
        else
            low = mid + 1;
    }
    deq.insert(deq.begin() + low, value);
}

void PmergeMe::buildPairsDeque(const std::deque<int> &arr, std::deque<int> &Main, std::deque<int> &Pending, bool &Unpaired)
{
    size_t pairs = arr.size() / 2;
    Unpaired = arr.size() % 2;
    for (size_t i = 0; i < pairs * 2; i += 2)
    {
        ++comp;
        int a = arr[i], b = arr[i + 1];
        if (a > b)
        {
            Main.push_back(a);
            Pending.push_back(b);
        }
        else
        {
            Main.push_back(b);
            Pending.push_back(a);
        }
    }
    if (Unpaired)
        Pending.push_back(arr.back());
}

std::deque<int> PmergeMe::reorderPendingDeque(const std::deque<int> &Main, const std::deque<int> &sortedMain, const std::deque<int> &Pending, bool Unpaired)
{
    std::deque<int> reordered(sortedMain.size());
    for (size_t i = 0; i < sortedMain.size(); ++i)
        reordered[i] = Pending[std::find(Main.begin(), Main.end(), sortedMain[i]) - Main.begin()];
    if (Unpaired)
        reordered.push_back(Pending.back());
    return reordered;
}

void PmergeMe::insertPendingDeque(std::deque<int> &result, const std::deque<int> &pending, const std::deque<int> &sortedMain)
{
    if (pending.size() == 1)
    {
        binarySearchDeque(result, pending[0], INT_MAX);
        return;
    }
    std::vector<int> indices = generateJacobIndices((int)pending.size());
    for (size_t i = 0; i < indices.size(); ++i)
    {
        int idx = indices[i] - 1;
        binarySearchDeque(result, pending[idx], idx < (int)sortedMain.size() ? sortedMain[idx] : INT_MAX);
    }
}

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &deq)
{
    if (deq.size() <= 1)
        return deq;
    if (deq.size() == 2)
    {
        std::deque<int> res = deq;
        ++comp;
        if (res[0] > res[1])
            std::swap(res[0], res[1]);
        return res;
    }
    std::deque<int> Main, Pending;
    bool Unpaired;
    buildPairsDeque(deq, Main, Pending, Unpaired);
    std::deque<int> sortedMain = fordJohnsonDeque(Main);
    std::deque<int> reordered = reorderPendingDeque(Main, sortedMain, Pending, Unpaired);
    std::deque<int> Result = sortedMain;
    insertPendingDeque(Result, reordered, sortedMain);
    return Result;
}
