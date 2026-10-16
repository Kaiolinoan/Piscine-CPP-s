#include "RPN.hpp"

RPN::~RPN() {}

RPN::RPN() : _stack() {}

void RPN::printError(const std::string& msg)
{
    std::cerr << "Error: " << msg << std::endl;
}

bool RPN::parseArg(std::string arg)
{
    if (arg.empty())
        return (printError("Invalid input"), false);
    if (arg.size() == 1 && arg[0] >= '0' && arg[0] <= '9')
        return (_stack.push(arg[0] - 48), true);
    for (size_t i = 0; arg[i]; i++ )
    {
        char c = arg[i];
        if (c == ' ' && arg[i + 1])
            continue ;
        else if (!arg[i + 1] && c == ' ')
            return (printError("Expression can not end with a space"), false);
        if ((c >= '0' && c <= '9'))
        {
            if ((arg[i + 1] && arg[i + 1] >= '0' && arg[i + 1] <= '9') || (i !=  0 && (arg[i - 1] && arg[i - 1] != ' ')))
                return (printError("Invalid number"), false);
            else if ((arg[i + 1] && arg[i + 1] == ' '))
                _stack.push(c - 48);
            else 
                return (printError("Expression can not end with a number"), false);
        }
        else if (c == '+' && i !=  0 && (arg[i - 1] && arg[i - 1] == ' '))
        {
            if (!sum())
               return (false);
        }
        else if  (c == '-' && i !=  0 && (arg[i - 1] && arg[i - 1] == ' '))
        {
            if (!minus())
                return false;
        }
        else if  (c == '*' && i !=  0 && (arg[i - 1] && arg[i - 1] == ' '))
        {
            if (!times())
                return false;
        }
        else if  (c == '/' && i !=  0 && (arg[i - 1] && arg[i - 1] == ' '))
        {
            if (!division())
               return false;
        }
        else
            return (printError("Invalid character in expression"), false);
    }
    return (true);
}

bool RPN::sum()
{
    if (_stack.empty())
        return (printError("Invalid operator position"), false);
    if (_stack.size() < 2)
        return (printError("Not enough operands for operator"), false);
    long nb1 = _stack.top();
    _stack.pop();
    long nb2 = _stack.top();
    _stack.pop();
   if (nb2 > 0  &&  nb1 > LONG_MAX - nb2)
        return (printError("Result overflows"), false);
   if (nb2 < 0  &&  nb1 < LONG_MIN - nb2)
        return (printError("Result overflows"), false);
    long res = nb2 + nb1;
    _stack.push(res);
    return (true);
}

bool RPN::minus()
{
    if (_stack.empty())
        return (printError("Invalid operator position"), false);
    if (_stack.size() < 2)
        return (printError("Not enough operands for operator"), false);
    long nb1 = _stack.top();
    _stack.pop();
    long nb2 = _stack.top();
    _stack.pop();
    if (nb1 < 0  &&  nb2 > LONG_MAX + nb1)
        return (printError("Result overflows"), false);
    if (nb1 > 0  &&  nb2 < LONG_MIN + nb1)
        return (printError("Result overflows"), false);
    long res = nb2 - nb1;
    _stack.push(res);
    return (true);
}
bool RPN::times()
{
    if (_stack.empty())
        return (printError("Invalid operator position"), false);
    if (_stack.size() < 2)
        return (printError("Not enough operands for operator"), false);
    long nb1 = _stack.top();
    _stack.pop();
    long nb2 = _stack.top();
    _stack.pop();
    if (nb1 > 0)
    {
        if (nb2 > 0 && nb1 > LONG_MAX / nb2)
            return (printError("Result overflows"), false);
        if (nb2 < 0 && nb2 < LONG_MIN / nb1)
            return (printError("Result overflows"), false);
    }
    else if (nb1 < 0)
    {
        if (nb2 > 0 && nb1 < LONG_MIN / nb2)
            return (printError("Result overflows"), false);
        if (nb2 < 0 && nb1 < LONG_MAX / nb2)
            return (printError("Result overflows"), false);
    }
    long res = nb2 * nb1;
    _stack.push(res);
    return (true);  
}

bool RPN::division()
{
    if (_stack.empty())
        return (printError("Invalid operator position"), false);
    if (_stack.size() < 2)
        return (printError("Not enough operands for operator"), false);
    long nb1 = _stack.top();
    if (!nb1)
        return (printError("Can not divide by 0"), false);
    _stack.pop();
    long nb2 = _stack.top();
    _stack.pop();
    if (nb2 == LONG_MIN && nb1 == -1)
        return (printError("Result overflows"), false);
    long res = nb2 / nb1;
    _stack.push(res);
    return (true);
}

bool RPN::calculate(const std::string& arg)
{
    if (!parseArg(arg))
        return false;
    if (_stack.size() != 1)
        return (printError("Missing operator"), false);
    std::cout << _stack.top() << std::endl;
    return true;
}

