#include "BitcoinExchange.hpp"

double strToDouble(const std::string& str)
{
    if (str.empty())
        return (-1);
    std::stringstream ss(str);
    double n;
   
    ss >> n;
    return (n);
}
int strToInt(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        else 
            return (-1);
    }
    std::stringstream ss(str);
    double n;

    ss >> n;
    return (n);
}

void BitcoinExchange::printError(const std::string& msg)
{
    std::cerr << "Error: " << msg << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string& filename) : _data(), _filename(filename) {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::parseDate(const std::string& date)
{
    if (date.empty())
        return (printError("Invalid date"), false);
    size_t separator1 = date.find("-");
    std::string year = date.substr(0, separator1);
    std::string temp_date = date.substr(++separator1);
    size_t separator2 = temp_date.find("-");
    std::string month = temp_date.substr(0, separator2);
    std::string day = temp_date.substr(++separator2);

    //CONSIDERAR SE USO REGEX

    if (year.empty() || month.empty() || day.empty() || separator1 == std::string::npos || separator2 == std::string::npos )
        return (printError("Missing information on date"), false);
    int year_nb = strToInt(year);
    int month_nb = strToInt(month);
    int day_nb = strToInt(day);
    if ((month_nb == 2 && day_nb > 28) || (month_nb == 4 && day_nb > 30) || (month_nb == 6 && day_nb > 30) || (month_nb == 9 && day_nb > 30) || (month_nb == 11 && day_nb > 30))
        return (printError("Invalid date"), false);
    if (year.size() != 4 || year_nb <= 0 || year_nb > 2026) 
        return (printError("Invalid year"), false);
    if (month.size() != 2 || month_nb <= 0 || month_nb > 12)
        return (printError("Invalid month"), false);
    if (day.size() != 2 ||  day_nb <= 0 || day_nb > 31)
        return (printError("Invalid day"), false);

    // std::cout << "year: " << year << " month: " << month << " day: " << day << std::endl;
    return (true);
}

bool BitcoinExchange::parseValue(const std::string& value, bool is_DB)
{
    if (value.empty())
        return (printError("Invalid value"), false);
    for (int i = 0; value[i]; i++)
    {
        if (std::isdigit(value[i]))
            continue;
        else
        {
            if (value[i] == '.' && value[i - 1] && std::isdigit(value[i  - 1]) && value[i + 1] && std::isdigit(value[i + 1]))
                continue;
            return (printError("Value expects a valid positive number"), false);
        }
    }
    double val_nb = strToDouble(value);
    if (val_nb < 0)
        return (printError("Invalid value"), false);
    else if (!is_DB && val_nb > 1000)
        return (printError("Value is too large"), false);

    // std::cout << "value: " << val_nb << std::endl;
    return (true);
}

void BitcoinExchange::parseInputFile()
{
    std::ifstream file(_filename.c_str());
    if (!file)
        return (printError("Could not open file")) ;
    std::string line;
    size_t i = 0;
    while (std::getline(file, line))
    {
        i++;
        if (line.size() == 0)
            continue;
        if (i == 1)
        {
            if (line.compare("date | value") == 0)
                continue;
            else
                return (printError("First line of input file must be: 'date | value'"));
        }
        else
        {
            std::stringstream ss(line);
            std::string date;
            std::string separator;
            std::string value;

            ss >> date >> separator >> value;
            if (!parseDate(date))
                continue ;
            if (separator != "|")
            {
                printError("Invalid separator");
                continue ;
            }
            if (!parseValue(value, false))
                continue;
            std::map<std::string, double>::iterator it = _data.find(date);
            if (it != _data.end())
                std::cout << it->first << " => " << it->second << " * " << value << " = " << it->second * strToDouble(value) << std::endl;
            else
            {
                std::map<std::string, double>::iterator lower_match = _data.lower_bound(date);
                if (lower_match == _data.begin())
                {
                    printError("Date is earlier than the database");
                    continue;
                }
                if (lower_match == _data.end() || lower_match->first != date)
                    --lower_match;
                std::cout << lower_match->first << " => " << lower_match->second <<  " * " << value << " = " << lower_match->second * strToDouble(value) << std::endl;
            }
        }
    }
}

bool BitcoinExchange::validateAndGetData()
{
    std::ifstream file("data.csv");
    if (!file)
        return (printError("Could not open database file"), false);
    std::string line;
    size_t i = 0;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
            break;
        i++;
        if (i == 1)
        {
            if (line.compare("date,exchange_rate") == 0)
                continue;
            else
                return (printError("First line of DB file must be: 'date,exchange_rate'"), false);
        }
        else
        {
            size_t pos = line.find(",");
            if (pos == std::string::npos)
                return (printError("Malformed data in DB file"), false);
            std::string key = line.substr(0, pos);
            if (!parseDate(key))
                return (false);
            ++pos;
            if (!parseValue(line.substr(pos), true))
                return (false);
            double value = strToDouble(line.substr(pos));
            if (value < 0)
                return (printError("Malformed data in DB file"), false);
            _data.insert(std::make_pair(key, value));
        }
    }
    if (i < 2)
        return (printError("DB file must have at least one valid row"), false);

    //debug
    // for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); ++it)
            // std::cout << std::fixed << std::setprecision(2) <<  "key: " << it->first << " value: "<< it->second << std::endl;
    return (true);
}

void BitcoinExchange::run()
{
    if (!validateAndGetData())
        return;
    parseInputFile();
}

