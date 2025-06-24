#pragma once
#include "dynamic_array.hpp"
#include "sequence.hpp"

template <typename T>
class array_sequence : public sequence<T>
{
private:
    dynamic_array<T> a_sequence;

public:
    class as_iterator : public sequence<T>::iterator
    {
    private:
        typename dynamic_array<T>::array_iterator it;

    public:
        as_iterator(typename dynamic_array<T>::array_iterator it);
        as_iterator(const as_iterator &other);
        as_iterator &operator++();
        as_iterator operator++(int);
        as_iterator &operator--();
        as_iterator operator--(int);
        as_iterator &operator=(const as_iterator &other);
        as_iterator operator+(const size_t n);
        as_iterator operator-(const size_t n);
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
        const_as_iterator &operator++();
        const_as_iterator operator++(int);
        const_as_iterator &operator--();
        const_as_iterator operator--(int);
        const_as_iterator &operator=(const const_as_iterator &other);
        const_as_iterator operator+(const size_t n);
        const_as_iterator operator-(const size_t n);
        const T &operator*() override;
        const T &operator[](const size_t index) override;
        bool operator==(const typename sequence<T>::const_iterator &other) const override;
        bool operator!=(const typename sequence<T>::const_iterator &other) const override;
    };
    as_iterator begin();
    as_iterator end();
    const_as_iterator cbegin() const;
    const_as_iterator cend() const;
    array_sequence();
    array_sequence(const size_t &size);
    array_sequence(T *items, const size_t size);
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