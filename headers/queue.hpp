#pragma once
#include <string>
#include <initializer_list>
#include "array_sequence.hpp"
#include "list_sequence.hpp"
#include "sequence.hpp"

template <typename T>
class queue
{
private:
    sequence<T> *container;

public:
    queue(sequence<T> *q = new list_sequence<T>());
    queue(const sequence<T> &other);
    queue(const queue<T> &other);
    ~queue();
    int size() const;
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    void push(const T &element);
    void pop();
    bool is_empty();
};

#include "../templates/queue.tpp"