#include "Bitcoin.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str()); //.c_str() converts std::string to const char* (needed for C++98 file opening).
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    // skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, rateStr;
        if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
            std::stringstream ss(rateStr);
            double rate;
            ss >> rate;
            if (!ss.fail())
                _rateMap[date] = rate;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10 ||
        date[4] != '-' || date[7] != '-')
        return false;

    int y, m, d;
    std::istringstream ss(date);
    char dash1, dash2;
    ss >> y >> dash1 >> m >> dash2 >> d;
    if (ss.fail() || dash1 != '-' || dash2 != '-')
        return false;

    if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double &value) {
    std::istringstream ss(valueStr);
    ss >> value;
    if (ss.fail() || !ss.eof())
        return false;
    if (value < 0)
        return false;
    if (value > 1000)
        return false;
    return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
    std::map<std::string, double>::const_iterator it = _rateMap.upper_bound(date);
    if (it == _rateMap.begin())
        return "";
    --it;
    return it->first;
}

void BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    // skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;

        if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim whitespace
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;
        if (!isValidValue(valueStr, value)) {
            if (valueStr.empty() || value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::string closestDate = _rateMap.count(date) ? date : findClosestDate(date);
        if (closestDate.empty()) {
            std::cerr << "Error: no exchange rate available before " << date << std::endl;
            continue;
        }

        double rate = _rateMap[closestDate];
        double result = rate * value;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}
