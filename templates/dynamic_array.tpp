#include "iostream"
#include "../headers/dynamic_array.hpp"

template <typename T>
dynamic_array<T>::array_iterator::array_iterator(T *ptr) : current(ptr) {}

template <typename T>
dynamic_array<T>::array_iterator::array_iterator(const array_iterator &other) : current(other.current) {}

template <typename T>
typename dynamic_array<T>::array_iterator &dynamic_array<T>::array_iterator::operator++()
{
    current++;
    return *this;
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator++(int)
{
    array_iterator temp = *this;
    current++;
    return temp;
}

template <typename T>
typename dynamic_array<T>::array_iterator &dynamic_array<T>::array_iterator::operator--()
{
    current--;
    return *this;
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator--(int)
{
    array_iterator temp = *this;
    current--;
    return temp;
}

template <typename T>
typename dynamic_array<T>::array_iterator &dynamic_array<T>::array_iterator::operator=(const array_iterator &other)
{
    if (this != &other)
    {
        current = other.current;
    }
    return *this;
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator+(size_t n)
{
    current += n;
    return *this;
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator-(size_t n)
{
    current -= n;
    return *this;
}

template <typename T>
T &dynamic_array<T>::array_iterator::operator*()
{
    return *current;
}

template <typename T>
T &dynamic_array<T>::array_iterator::operator[](size_t index)
{
    return *(current + index);
}

template <typename T>
bool dynamic_array<T>::array_iterator::operator==(const array_iterator &other)
{
    return current == other.current;
}

template <typename T>
bool dynamic_array<T>::array_iterator::operator!=(const array_iterator &other)
{
    return current != other.current;
}

template class dynamic_array<int>;
template class dynamic_array<int>::array_iterator;