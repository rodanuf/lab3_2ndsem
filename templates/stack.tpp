#include <iostream>
#include "../headers/stack.hpp"

template <typename T>
stack<T>::node::node(const T &item) : element(item), next(nullptr) {}

template <typename T>
stack<T>::st_iterator::st_iterator(node *point) : current(&point) {}

template <typename T>
stack<T>::st_iterator::st_iterator(node **point) : current(point) {}

template <typename T>
stack<T>::st_iterator::st_iterator(const st_iterator &other) : current(other.current) {}

template <typename T>
typename stack<T>::st_iterator &stack<T>::st_iterator::operator++()
{
    *current = (*current)->next;
    return *this;
}

template <typename T>
typename stack<T>::st_iterator stack<T>::st_iterator::operator++(int)
{
    st_iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
typename stack<T>::st_iterator &stack<T>::st_iterator::operator=(const st_iterator &other)
{
    current = other.current;
    return *this;
}

template <typename T>
typename stack<T>::st_iterator stack<T>::st_iterator::operator+(const size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        ++(*this);
    }
    return *this;
}

template <typename T>
T &stack<T>::st_iterator::operator*()
{
    return (*current)->element;
}

template <typename T>
T &stack<T>::st_iterator::operator[](const size_t n)
{
    st_iterator temp = static_cast<stack<T> *>(this)->begin();
    for (size_t i = 0; i < n; ++i)
    {
        ++temp;
    }
    return *temp;
}

template <typename T>
bool stack<T>::st_iterator::operator==(const typename sequence<T>::iterator &other) const
{
    const st_iterator &derived = dynamic_cast<const st_iterator &>(other);
    return current == derived.current;
}

template <typename T>
bool stack<T>::st_iterator::operator!=(const typename sequence<T>::iterator &other) const
{
    const st_iterator &derived = dynamic_cast<const st_iterator &>(other);
    return current != derived.current;
}

template <typename T>
void stack<T>::st_iterator::set(const T &element)
{
    (*current)->element = element;
}

template <typename T>
void stack<T>::st_iterator::erase()
{
    (*current)->element = T();
}

template <typename T>
typename stack<T>::st_iterator stack<T>::begin()
{
    return st_iterator(&head);
}

template <typename T>
typename stack<T>::st_iterator stack<T>::end()
{
    return st_iterator(nullptr);
}