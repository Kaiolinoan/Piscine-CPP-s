#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>

template <typename T>
T easyfind(T t_param, int int_param)
{
    int i = 0;
    while (t_param[i])
    {
        if (t_param[i] == int_param)
            return (t_param[i]);
        i++;
    }
    return (-1);
}
#endif
