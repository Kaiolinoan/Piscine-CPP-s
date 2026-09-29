#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>

template <typename T>
int easyfind(T t_param, int int_param)
{
    for (typename T::iterator it = t_param.begin(); it != t_param.end(); it++)
    {
        if (*it == int_param)
            return (*it);
    }
    return (-1);
}
#endif
