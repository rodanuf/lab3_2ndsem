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
        T &operator*() override;
        T &operator[](const int index) override;
        bool operator==(const ls_iterator &other) const override;
        bool operator!=(const ls_iterator &other) const override;
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
        T &operator*() override;
        T &operator[](const int index) override;
        bool operator==(const const_ls_iterator &other) const override;
        bool operator!=(const const_ls_iterator &other) const override;
    };
    list_sequence();
    list_sequence(const T *items, size_t length);
    list_sequence(const list_sequence<T> &other);
};
