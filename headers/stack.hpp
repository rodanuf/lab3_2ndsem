#pragma once
#include <string>
#include "array_sequence.hpp"
#include "list_sequence.hpp"
#include "sequence.hpp"

template <typename T>
class stack
{
public:
    using value_type = T;

private:
    sequence<T> *container;

public:
    typename sequence<T>::iterator begin();
    typename sequence<T>::iterator end();
    typename sequence<T>::const_iterator cbegin() const;
    typename sequence<T>::const_iterator cend() const;

    stack(sequence<T> *s = new list_sequence<T>());
    stack(const std::initializer_list<T> &list, sequence<T> *s = new list_sequence<T>());
    stack(const sequence<T> &other);
    stack(const stack<T> &other);
    stack(stack<T> &&other);
    ~stack();

    stack<T> &operator=(const stack<T> &other);
    stack<T> &operator=(const sequence<T> &other);
    stack<T> operator+(const T &value);
    stack<T> &operator+=(const T &value);

    int size() const;

    T &top();
    const T &top() const;

    void push(const T &element);
    void pop();
    void clear();

    bool is_empty();
};

#include "../templates/stack.tpp"