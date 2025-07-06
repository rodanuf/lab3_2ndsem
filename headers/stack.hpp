#pragma once
#include <string>
#include <initializer_list>
#include "sequence.hpp"

template <typename T>
class stack : public sequence<T>
{
private:
    sequence<T> *container;

public:
    stack(std::string type = "list_sequence");
    stack(std::string type = "list_sequence", const int &size);
    stack(std::string type = "list_sequence", const T *items, const int &size);
    stack(std::string type = "list_sequence", const std::initializer_list<T> &items);
    stack(const sequence<T> &other);
    stack(const stack<T> &other);
    ~stack();
    T &get(const int index) const override;
    T &get_first() const override;
    T &get_last() const override;
    int get_length() const override;
    sequence<T> *get_subsequence(const int start_index, const int end_index) const override;
    sequence<T> *append_element(const T &element) override;
    sequence<T> *prepend_element(const T &element) override;
    sequence<T> *insert_element(const T &element, const int index) override;
    sequence<T> *remove_at(const int index);
    sequence<T> *concat(const sequence<T> &other) override;
    sequence<T> *clone();
    sequence<T> *immutable_append_element(const T &element) const override;
    sequence<T> *immutable_prepend_element(const T &element) const override;
    sequence<T> *immutable_insert_element(const T &element, const int index) const override;
    sequence<T> *immutable_concat(const sequence<T> &other) const override;
    void clear() override;

    template <typename map_func>
    sequence<T> *map(const map_func &func);

    template <typename predicate>
    sequence<T> *where(const predicate &pred);

    template <typename R, typename bin_op>
    R reduce(const bin_op &op, R init);

    template <typename map_func>
    sequence<T> *immutable_map(const map_func &func) const;
};

#include "../templates/stack.tpp"