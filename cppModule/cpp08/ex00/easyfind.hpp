#ifndef EASTFIND_HPP
#define EASTFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::iterator easyfind(T &a, int value)
{
    typename T::iterator iter;
    iter = std::find(a.begin(), a.end(), value);
    return (iter);
}

#endif