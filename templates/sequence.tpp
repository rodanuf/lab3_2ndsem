#include "../headers/sequence.hpp"

template <typename T>
sequence<T>::iterator::iterator() : it(nullptr) {}

template <typename T>
sequence<T>::iterator::iterator(iterator_impl<T> *it) : it(it) {}

template <typename T>
sequence<T>::iterator::iterator(const iterator &other) : it(other.it) {}

template <typename T>
sequence<T>::iterator::~iterator()
{
    delete it;
}

template <typename T>
typename sequence<T>::iterator &sequence<T>::iterator::operator++()
{
    ++it;
    return *this;
}

template <typename T>
typename sequence<T>::iterator sequence<T>::iterator::operator++(int)
{
    iterator tmp = *this;
    ++it;
    return tmp;
}

template <typename T>
typename sequence<T>::iterator &sequence<T>::iterator::operator=(const iterator &other)
{
    it = other.it;
    return *this;
}

template <typename T>
T &sequence<T>::iterator::operator*()
{
    return *it;
}