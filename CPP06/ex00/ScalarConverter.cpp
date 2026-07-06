#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter& ) {};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ) { return (*this); };

static bool checkSpecialNumbers(const std::string &input)
{
    std::string float_out;
    std::string double_out;
    if (input == "nan" || input == "nanf")
    {
        float_out = "nanf";
        double_out = "nan";
    }
    else if (input == "inf" || input == "inff")
    {
        float_out = "inff";
        double_out = "inf";
    }
    else if (input == "-inf" || input == "-inff")
    {
        float_out = "-inff";
        double_out = "-inf";
    }
    else if (input == "+inf" || input == "+inff")
    {
        float_out = "+inff";
        double_out = "+inf";
    }
    else
        return false;
    std::cout << "char: impossible\nint: impossible\nfloat: "
    << float_out <<"\ndouble: " << double_out << "\n"; 
    return true;
}

static bool checkSingleChar(const std::string& input)
{
    if (input.length() == 1 && !isdigit(input[0]))
    {
        char c = static_cast<char>(input[0]);
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);
        if (isprint(input[0]))
            std::cout << "char: " <<  c << "\n";
        else
           std::cout << "char: Non displayable\n";    
        std::cout << "int: " << i << "\n";
        std::cout << std::fixed;
        std::cout.precision(1);
        std::cout << "float: " << f <<"f\n"; 
        std::cout << "double: " << d <<"\n"; 
        return true;
    }
    return false;
}

void ScalarConverter::convert(const std::string& input)
{
    if (checkSpecialNumbers(input) || checkSingleChar(input))
        return ;
    char *checker = NULL;
    double d= strtod(input.c_str(), &checker);
    if (checker == input.c_str())
    {
        std::cout << "Invalid Input\n";
        return ;
    }
    if (*checker != '\0')
    {
        if (*checker != 'f' || checker[1] != '\0')
        {
            std::cout << "Invalid Input\n";
            return ;
        }
    }
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    if (i < 0 || i > 127)
        std::cout << "char: impossible\n";
    else
    {
        if (isprint(c))
            std::cout << "char: " << "'"<< c << "'" << "\n";
        else
           std::cout << "char: Non displayable\n";
    }
    std::cout << "int: " << i << "\n";
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << "float: " << f << "f\n"; 
    std::cout << "double: " << d << "\n"; 
};