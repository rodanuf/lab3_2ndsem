#pragma once
#include <string>
#include <initializer_list>
#include "array_sequence.hpp"
#include "list_sequence.hpp"
#include "sequence.hpp"

template <typename T>
class queue
{
public:
    using value_type = T;

private:
    sequence<T> *container;

public:
    sequence<T>::iterator begin();
    sequence<T>::iterator end();
    sequence<T>::const_iterator cbegin() const;
    sequence<T>::const_iterator cend() const;

    queue(sequence<T> *q = new list_sequence<T>());
    queue(const std::initializer_list<T> &list, sequence<T> *s = new list_sequence<T>());
    queue(const sequence<T> &other);
    queue(const queue<T> &other);
    ~queue();

    queue<T> &operator=(const queue<T> &other);
    queue<T> &operator=(const sequence<T> &other);
    queue<T> operator+(const T &value);
    queue<T> &operator+=(const T &value);

    int size() const;

    T &front();
    const T &front() const;

    T &back();
    const T &back() const;

    void push(const T &element);
    void pop();
    void clear();

    bool is_empty();
};

#include "../templates/queue.tpp"