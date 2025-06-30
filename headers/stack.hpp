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
        node(const T &item);
    };
    node *head;
    int length;

public:
    class st_iterator : public sequence<T>::iterator
    {
    private:
        node **current;

    public:
        st_iterator(node *point);
        st_iterator(node **point);
        st_iterator(const st_iterator &other);
        st_iterator &operator++();
        st_iterator operator++(int);
        st_iterator &operator=(const st_iterator &other);
        st_iterator operator+(const int n);
        node *operator*() const;
        T &operator*() override;
        bool operator==(const typename sequence<T>::iterator &other) const override;
        bool operator!=(const typename sequence<T>::iterator &other) const override;
        void set(const T &element) override;
        void erase() override;
    };
    class const_st_iterator : public sequence<T>::const_iterator
    {
    private:
        node **current;

    public:
        const_st_iterator(node *point);
        const_st_iterator(node **point);
        const_st_iterator(const const_st_iterator &other);
        const_st_iterator &operator++();
        const_st_iterator operator++(int);
        const_st_iterator &operator=(const const_st_iterator &other);
        const_st_iterator operator+(const int n);
        const node *operator*() const;
        const T &operator*() override;
        bool operator==(const typename sequence<T>::const_iterator &other) const override;
        bool operator!=(const typename sequence<T>::const_iterator &other) const override;
    };
    st_iterator begin();
    st_iterator end();
    const_st_iterator cbegin() const;
    const_st_iterator cend() const;
    stack();
    stack(const int &size);
    stack(const T *items, const int &size);
    stack(const std::initializer_list<T> &items);
    stack(const sequence<T> &other);
    ~stack();
    T &get(const int index) const override;
    T &get_first() const override;
    T &get_last() const override;
    int get_length() const override;
    sequence<T> *get_subsequence(const int start_index, const int end_index) const override;
    sequence<T> *append_element(const T &element) override;
    sequence<T> *prepend_element(const T &element) override;
    sequence<T> *insert_element(const T &element, const int index) override;
    sequence<T> *concat(const sequence<T> &other) override;
    sequence<T> *immutable_append_element(const T &element) const override;
    sequence<T> *immutable_prepend_element(const T &element) const override;
    sequence<T> *immutable_insert_element(const T &element, const int index) const override;
    sequence<T> *immutable_concat(const sequence<T> &other) const override;
    void print() const override;
    void clear() override;
};

#include "../templates/stack.tpp"