#pragma once
#include <iostream>
#include <climits>
#include <stack>

class RPN
{
private:
    std::stack<long> _stack;    
public:
    RPN();
    ~RPN();
    bool calculate(const std::string& arg);
    bool sum();
    bool minus();
    bool times();
    bool division();
    bool parseArg(std::string arg);
    void printError(const std::string &msg);
};


