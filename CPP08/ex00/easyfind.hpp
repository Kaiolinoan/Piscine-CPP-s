#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& t_param, int int_param)
{
    typename T::iterator it = std::find(t_param.begin(), t_param.end(), int_param);
    if (it == t_param.end()) 
        throw std::runtime_error("Could find the item.\n"); 
    return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T& t_param, int int_param) 
{
    typename T::const_iterator it = std::find(t_param.begin(), t_param.end(), int_param);
    if (it == t_param.end()) 
        throw std::runtime_error("Could find the item.\n"); 
    return (it);
}
#endif
