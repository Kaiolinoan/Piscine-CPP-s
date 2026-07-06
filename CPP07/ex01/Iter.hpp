#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *arr, const size_t &lenght, void (f)(const T&))
{
    for (size_t i = 0; i < lenght; i++)
        f(arr[i]);
}

template <typename T>
void iter(T *arr, const size_t &lenght, void (f)(T&))
{
    for (size_t i = 0; i < lenght; i++)
        f(arr[i]);
}

template <typename T>
void print(const T &p)
{
    std::cout << p << "\n"; 
    return;
}

void increment(int &n);
void increment(double &n);
void addDot(std::string &s);

#endif