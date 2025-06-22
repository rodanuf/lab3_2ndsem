#pragma once
#include "sequence.hpp"

template <typename T>
class stack : public sequence<T>
{
private:
    struct node
    {
        T element;
        node *next;
        node(const T &e);
    };
    node *head;
    size_t length;

public:
    class st_iterator : public sequence<T>::iterator
    {
    private:
        node **current;

    public:
        st_iterator(node *point);
        st_iterator &operator++();
        st_iterator operator++(int);
        st_iterator &operator--();
        st_iterator operator--(int);
        st_iterator operator=(const st_iterator &other);
        st_iterator operator+(const int &n);
        st_iterator operator-(const int &n);
        T &operator*();
        T &operator[](const int &n);
        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;
        void set(const T &element) override;
        void erase() override;
    };
    class const_st_iterator : public sequence<T>::const_iterator
    {
    private:
        const node **current;

    public:
        const_st_iterator(const node *point);
        const_st_iterator &operator++();
        const_st_iterator operator++(int);
        const_st_iterator &operator--();
        const_st_iterator operator--(int);
        const_st_iterator operator=(const const_st_iterator &other);
        const_st_iterator operator+(const int &n);
        const_st_iterator operator-(const int &n);
        const T &operator*();
        const T &operator[](const int &n);
        bool operator==(const const_iterator &other) const;
        bool operator!=(const const_iterator &other) const;
    };
    stack();
    stack(const size_t &size);
    stack(T *items, size_t &size);
    stack(const sequence<T> &other);
    ~stack();
    T &get(const int &index) override;
    T &get_first() override;
    T &get_last() override;
    size_t get_length() const override;
    sequence<T> *get_subsequence(const int &start_index, const int &end_index) const override;
    sequence<T> *append_element(const T &element) override;
    sequence<T> *prepend_element(const T &element) override;
    sequence<T> *insert_element(const int &index, const T &element) override;
    sequence<T> *concat(const sequence<T> &other) override;
    sequence<T> *immutable_append_element(const T &element) override;
    sequence<T> *immutable_prepend_element(const T &element) override;
    sequence<T> *immutable_insert_element(const int &index, const T &element) override;
    sequence<T> *immutable_concat(const sequence<T> &other) override;
    void clear() override;
    void print() override;
    iterator begin() override;
    iterator end() override;
    const_iterator cbegin() override;
    const_iterator cend() override;
};