#pragma once
#include "dynamic_array.hpp"
#include "sequence.hpp"

template <typename T>
class array_sequence : public sequence<T>
{
private:
    dynamic_array<T> *a_sequence;

public:
    class as_iterator : public sequence<T>::iterator
    {
    private:
        typename dynamic_array<T>::array_iterator it;

    public:
        as_iterator(typename dynamic_array<T>::array_iterator it);
        as_iterator &operator++() override;
        as_iterator operator++(int) override;
        as_iterator &operator--() override;
        as_iterator operator--(int) override;
        as_iterator &operator=(const as_iterator &other);
        as_iterator operator+(const size_t n) override;
        as_iterator operator-(const size_t n) override;
        T &operator*() override;
        T &operator[](const int index) override;
        bool operator==(const as_iterator &other) override;
        bool operator!=(const as_iterator &other) override;
        void set(const T &value);
        void erase();
    };
    class const_as_iterator : public sequence<T>::const_iterator
    {
    private:
        typename dynamic_array<T>::const_array_iterator it;

    public:
        const_as_iterator(typename dynamic_array<T>::const_array_iterator it);
        const_as_iterator &operator++() override;
        const_as_iterator operator++(int) override;
        const_as_iterator &operator--() override;
        const_as_iterator operator--(int) override;
        const_as_iterator operator+(const size_t n) override;
        const_as_iterator operator-(const size_t n) override;
        T &operator*() override;
        T &operator[](const int index) override;
        bool operator==(const const_as_iterator &other) override;
        bool operator!=(const const_as_iterator &other) override;
    };
    arrray_sequence();
    array_sequence(const size_t &size);
    array_sequence(T *items, const size_t &size);
    array_sequence(const dynamic_array<T> &array);
    ~array_sequence();
    T &get(int index) override;
    T &get_first() override;
    T &get_last() override;
    size_t get_length() override;
    sequence<T> *get_subsequence(int start_index, int end_index) override;
    sequence<T> *append_element(const T &element) override;
    sequence<T> *prepend_element(const T &element) override;
    sequence<T> *insert_element(const T &element, const int index) override;
    sequence<T> *concat(sequence<T> *other) override;
    sequence<T> *immutable_append_element(const T &element) override;
    sequence<T> *immutable_prepend_element(const T &element) override;
    sequence<T> *immutable_insert_element(const T &element, const int index) override;
    sequence<T> *immutable_concat(sequence<T> *other) override;
    void print() override;
    void clear() override;
    iterator begin() override;
    iterator end() override;
    const_iterator cbegin() const override;
    const_iterator cend() const override;
};