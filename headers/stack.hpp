#pragma once
#include <string>
#include <initializer_list>
#include "array_sequence.hpp"
#include "list_sequence.hpp"
#include "sequence.hpp"

template <typename T>
class stack
{
private:
    sequence<T> *container;

public:
    stack(sequence<T> *s = new list_sequence<T>());
    stack(const sequence<T> &other);
    stack(const stack<T> &other);
    ~stack();
    int size() const;
    T &top();
    const T &top() const;
    void push(const T &element);
    void pop();
    bool is_empty();
    template <typename map_func>
    stack<T> *map(const map_func &func);

    template <typename predicate>
    stack<T> *where(const predicate &pred);

    template <typename R, typename bin_op>
    R reduce(const bin_op &op, R init);

    template <typename map_func>
    stack<T> *immutable_map(const map_func &func) const;
};

#include "../templates/stack.tpp"