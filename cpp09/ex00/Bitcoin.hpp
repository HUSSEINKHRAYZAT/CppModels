#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFile);
    ~BitcoinExchange();

    void processInput(const std::string& inputFile);

private:
    std::map<std::string, double> _rateMap;

    void loadDatabase(const std::string& dbFile);
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& valueStr, double &value);
    std::string findClosestDate(const std::string& date);
};

#endif
