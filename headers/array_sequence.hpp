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
        as_iterator(const as_iterator &other);
        typename sequence<T>::iterator &operator++() override;
        typename sequence<T>::iterator operator++(int) override;
        typename sequence<T>::iterator &operator--() override;
        typename sequence<T>::iterator operator--(int) override;
        typename sequence<T>::iterator &operator=(const typename sequence<T>::iterator &other) override;
        typename sequence<T>::iterator operator+(const size_t n) override;
        typename sequence<T>::iterator operator-(const size_t n) override;
        T &operator*() override;
        T &operator[](const size_t index) override;
        bool operator==(const typename sequence<T>::iterator &other) const override;
        bool operator!=(const typename sequence<T>::iterator &other) const override;
        void set(const T &value) override;
        void erase() override;
    };
    class const_as_iterator : public sequence<T>::const_iterator
    {
    private:
        typename dynamic_array<T>::const_array_iterator it;

    public:
        const_as_iterator(typename dynamic_array<T>::const_array_iterator it);
        const_as_iterator(const const_as_iterator &other);
        typename sequence<T>::const_iterator &operator++() override;
        typename sequence<T>::const_iterator operator++(int) override;
        typename sequence<T>::const_iterator &operator--() override;
        typename sequence<T>::const_iterator operator--(int) override;
        typename sequence<T>::const_iterator &operator=(const typename sequence<T>::const_iterator &other) override;
        typename sequence<T>::const_iterator operator+(const size_t n) override;
        typename sequence<T>::const_iterator operator-(const size_t n) override;
        T &operator*() override;
        T &operator[](const size_t index) override;
        bool operator==(const typename sequence<T>::const_iterator &other) const override;
        bool operator!=(const typename sequence<T>::const_iterator &other) const override;
    };
    typename sequence<T>::iterator begin() override;
    typename sequence<T>::iterator end() override;
    typename sequence<T>::const_iterator cbegin() const override;
    typename sequence<T>::const_iterator cend() const override;
    array_sequence();
    array_sequence(const size_t &size);
    array_sequence(T *items, const size_t &size);
    array_sequence(std::initializer_list<T> items);
    array_sequence(const sequence<T> &other);
    ~array_sequence();
    T &get(int index) const override;
    T &get_first() const override;
    T &get_last() const override;
    size_t get_length() const override;
    sequence<T> *get_subsequence(int start_index, int end_index) const override;
    sequence<T> *append_element(const T &element) override;
    sequence<T> *prepend_element(const T &element) override;
    sequence<T> *insert_element(const T &element, int index) override;
    sequence<T> *concat(const sequence<T> &container) override;
    sequence<T> *immutable_append_element(const T &element) const override;
    sequence<T> *immutable_prepend_element(const T &element) const override;
    sequence<T> *immutable_insert_element(const T &element, int index) const override;
    sequence<T> *immutable_concat(const sequence<T> &container) const override;
    void print() const override;
    void clear() override;
};

#include "../templates/array_sequence.tpp"