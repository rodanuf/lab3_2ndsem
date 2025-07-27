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
        ls_iterator(const typename linked_list<T>::list_iterator &it);
        ls_iterator(const ls_iterator &other);
        ls_iterator &operator++();
        ls_iterator operator++(int);
        ls_iterator &operator--();
        ls_iterator operator--(int);
        ls_iterator &operator=(const ls_iterator &other);
        ls_iterator operator+(const int n);
        ls_iterator operator-(const int n);
        T &operator*() override;
        bool operator==(const typename sequence<T>::iterator &other) const override;
        bool operator!=(const typename sequence<T>::iterator &other) const override;
        void set(const T &element) override;
        void erase() override;
    };
    class const_ls_iterator : public sequence<T>::const_iterator
    {
    private:
        typename linked_list<T>::const_list_iterator it;

    public:
        const_ls_iterator(const typename linked_list<T>::const_list_iterator &it);
        const_ls_iterator(const const_ls_iterator &other);
        const_ls_iterator &operator++();
        const_ls_iterator operator++(int);
        const_ls_iterator &operator--();
        const_ls_iterator operator--(int);
        const_ls_iterator &operator=(const const_ls_iterator &other);
        const_ls_iterator operator+(const int n);
        const_ls_iterator operator-(const int n);
        const T &operator*() override;
        bool operator==(const typename sequence<T>::const_iterator &other) const override;
        bool operator!=(const typename sequence<T>::const_iterator &other) const override;
    };
    ls_iterator *begin();
    ls_iterator *end();
    const_ls_iterator *cbegin() const;
    const_ls_iterator *cend() const;
    list_sequence();
    list_sequence(const int &size);
    list_sequence(const T *items, const int &size);
    list_sequence(const std::initializer_list<T> &items);
    list_sequence(const sequence<T> &other);
    ~list_sequence();
    T &get(const int index) override;
    T &get_first() override;
    T &get_last() override;
    int get_length() const override;
    sequence<T> *get_subsequence(const int start_index, const int end_index) const override;
    sequence<T> *append_element(const T &element) override;
    sequence<T> *prepend_element(const T &element) override;
    sequence<T> *insert_element(const T &element, const int index) override;
    sequence<T> *remove_at(const int index) override;
    sequence<T> *concat(const sequence<T> &other) override;
    sequence<T> *clone() const override;
    sequence<T> *immutable_append_element(const T &element) const override;
    sequence<T> *immutable_prepend_element(const T &element) const override;
    sequence<T> *immutable_insert_element(const T &element, const int index) const override;
    sequence<T> *immutable_remove_at(const int index) const override;
    sequence<T> *immutable_concat(const sequence<T> &other) const override;
    void clear() override;
};

#include "../templates/list_sequence.tpp"