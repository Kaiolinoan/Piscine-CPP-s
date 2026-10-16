#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
class BitcoinExchange
{
private:
    std::map<std::string, double>   _data;
    std::string                     _filename;

    void parseInputFile();
    bool validateAndGetData();
    void printError(const std::string& msg);
    bool parseDate(const std::string& date);
    bool parseValue(const std::string& value, bool is_DB);

public:
    BitcoinExchange(const std::string& filename);
    ~BitcoinExchange();
    void run();
};


