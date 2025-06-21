#pragma once
#include "linked_list.hpp"
#include "sequence.hpp"

template <typename T>
class list_sequence : public sequence<T>
{
private:
    linked_list<T> l_sequence;

public:
    class ls_iterator : public sequence<T>::iterator
    {
    private:
        typename linked_list<T>::list_iterator it;

    public:
        ls_iterator(typename linked_list<T>::list_iterator it);
        ls_iterator &operator++() override;
        ls_iterator operator++(int) override;
        ls_iterator &operator--() override;
        ls_iterator operator--(int) override;
        ls_iterator operator=(const ls_iterator &other) override;
        ls_iterator operator+(const size_t n) override;
        ls_iterator operator-(const size_t n) override;
        T &operator*() override;
        T &operator[](const int &index) override;
        bool operator==(const ls_iterator &other) const override;
        bool operator!=(const ls_iterator &other) const override;
        void set(const T &element) override;
        void erase() override;
    };
    class const_ls_iterator : public sequence<T>::const_iterator
    {
    private:
        typename linked_list<T>::const_list_iterator it;

    public:
        const_ls_iterator(typename linked_list<T>::const_list_iterator it);
        const_ls_iterator &operator++() override;
        const_ls_iterator operator++(int) override;
        const_ls_iterator &operator--() override;
        const_ls_iterator operator--(int) override;
        const_ls_iterator operator=(const const_ls_iterator &other) override;
        const_ls_iterator operator+(const size_t n) override;
        const_ls_iterator operator-(const size_t n) override;
        T &operator*() override;
        T &operator[](const int index) override;
        bool operator==(const const_ls_iterator &other) const override;
        bool operator!=(const const_ls_iterator &other) const override;
    };
    list_sequence();
    list_sequence(const size_t &size);
    list_sequence(const T *items, const size_t &size);
    list_sequence(const sequence<T> &other);
    ~list_sequence();
    T &get(const int index) const override;
    T &get_first() const override;
    T &get_last() const override;
    int get_length() const override;
    sequence<T> *get_subsequence(const int start_index, const int end_index) const override;
    sequence<T> *append_element(const T &item) override;
    sequence<T> *prepend_element(const T &item) override;
    sequence<T> *insert_element(const T &element, const int index) override;
    sequence<T> *concat(const sequence<T> &other) override;
    sequence<T> immutable_append_element(const T &item) const override;
    sequence<T> immutable_prepend_element(const T &item) const override;
    sequence<T> immutable_insert_element(const T &element, const int index) const override;
    sequence<T> immutable_concat(const sequence<T> &other) const override;
    void print() const override;
    void clear() override;
    iterator begin() override;
    iterator end() override;
    const_iterator cbegin() const override;
    const_iterator cend() const override;
};
