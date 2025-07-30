#include "../headers/sequence.hpp"

template <typename T>
sequence<T>::iterator::iterator() : it(nullptr) {}

template <typename T>
sequence<T>::iterator::iterator(typename sequence<T>::iterator_impl *it) : it(it) {}

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
typename sequence<T>::iterator &sequence<T>::iterator::operator--()
{
    --it;
    return *this;
}

template <typename T>
typename sequence<T>::iterator sequence<T>::iterator::operator--(int)
{
    iterator tmp = *this;
    --it;
    return tmp;
}

template <typename T>
typename sequence<T>::iterator &sequence<T>::iterator::operator=(const iterator &other)
{
    it = other.it;
    return *this;
}

template <typename T>
typename sequence<T>::iterator sequence<T>::iterator::operator+(const int n)
{
    it += n;
    return *this;
}

template <typename T>
typename sequence<T>::iterator sequence<T>::iterator::operator-(const int n)
{
    it -= n;
    return *this;
}

template <typename T>
T &sequence<T>::iterator::operator*()
{
    return (*it).operator*();
}

template <typename T>
bool sequence<T>::iterator::operator==(const iterator &other) const
{
    return it == other.it;
}

template <typename T>
bool sequence<T>::iterator::operator!=(const iterator &other) const
{
    return it != other.it;
}

template <typename T>
typename sequence<T>::iterator sequence<T>::begin()
{
    return iterator(begin_impl());
}

template <typename T>
typename sequence<T>::iterator sequence<T>::end()
{
    return iterator(end_impl());
}

template <typename T>
sequence<T>::const_iterator::const_iterator() : it(nullptr) {}

template <typename T>
sequence<T>::const_iterator::const_iterator(const typename sequence<T>::iterator_impl *it) : it(it) {}

template <typename T>
sequence<T>::const_iterator::const_iterator(const const_iterator &other) : it(other.it) {}

template <typename T>
sequence<T>::const_iterator::~const_iterator()
{
    delete it;
}

template <typename T>
typename sequence<T>::const_iterator &sequence<T>::const_iterator::operator++()
{
    ++it;
    return *this;
}

template <typename T>
typename sequence<T>::const_iterator sequence<T>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++it;
    return tmp;
}

template <typename T>
typename sequence<T>::const_iterator &sequence<T>::const_iterator::operator--()
{
    --it;
    return *this;
}

template <typename T>
typename sequence<T>::const_iterator sequence<T>::const_iterator::operator--(int)
{
    const_iterator tmp = *this;
    --it;
    return tmp;
}

template <typename T>
typename sequence<T>::const_iterator &sequence<T>::const_iterator::operator=(const const_iterator &other)
{
    it = other.it;
    return *this;
}

template <typename T>
typename sequence<T>::const_iterator sequence<T>::const_iterator::operator+(const int n)
{
    it += n;
    return *this;
}

template <typename T>
typename sequence<T>::const_iterator sequence<T>::const_iterator::operator-(const int n)
{
    it -= n;
    return *this;
}

template <typename T>
const T &sequence<T>::const_iterator::operator*() const
{
    return (*it).operator*();
}

template <typename T>
bool sequence<T>::const_iterator::operator==(const const_iterator &other) const
{
    return it == other.it;
}

template <typename T>
bool sequence<T>::const_iterator::operator!=(const const_iterator &other) const
{
    return it != other.it;
}

template <typename T>
typename sequence<T>::const_iterator sequence<T>::cbegin() const
{
    return const_iterator(cbegin_impl());
}

template <typename T>
typename sequence<T>::const_iterator sequence<T>::cend() const
{
    return const_iterator(cend_impl());
}