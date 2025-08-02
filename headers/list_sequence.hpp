#pragma once
#include "linked_list.hpp"
#include "sequence.hpp"

template <typename T>
class list_sequence : public sequence<T>
{
protected:
    typename list_sequence<T>::ls_iterator *begin_impl() override;
    typename list_sequence<T>::ls_iterator *end_impl() override;
    typename list_sequence<T>::const_ls_iterator *cbegin_impl() const override;
    typename list_sequence<T>::const_ls_iterator *cend_impl() const override;

public:
    using value_type = T;

private:
    linked_list<T> l_sequence;

public:
    class ls_iterator : public sequence<T>::iterator_impl
    {
    private:
        typename linked_list<T>::list_iterator it;

    public:
        ls_iterator(const typename linked_list<T>::list_iterator &it);
        ls_iterator(const ls_iterator &other);

        ls_iterator &operator++() override;
        ls_iterator *operator++(int) override;
        ls_iterator &operator--() override;
        ls_iterator *operator--(int) override;
        ls_iterator &operator=(const typename sequence<T>::iterator_impl &other) override;
        ls_iterator *operator+(const int n) const override;
        ls_iterator *operator-(const int n) const override;

        ls_iterator *clone() const override;

        T &operator*() override;
        const T &operator*() const override;

        bool operator==(const typename sequence<T>::iterator_impl &other) const override;
        bool operator!=(const typename sequence<T>::iterator_impl &other) const override;

        void set(const T &element);
        void erase();
    };
    class const_ls_iterator : public sequence<T>::iterator_impl
    {
    private:
        typename linked_list<T>::const_list_iterator it;

    public:
        const_ls_iterator(const typename linked_list<T>::const_list_iterator &it);
        const_ls_iterator(const const_ls_iterator &other);

        const_ls_iterator &operator++() override;
        const_ls_iterator *operator++(int) override;
        const_ls_iterator &operator--() override;
        const_ls_iterator *operator--(int) override;
        const_ls_iterator &operator=(const typename sequence<T>::iterator_impl &other) override;
        const_ls_iterator *operator+(const int n) const override;
        const_ls_iterator *operator-(const int n) const override;

        const_ls_iterator *clone() const override;

        T &operator*() override;
        const T &operator*() const override;

        bool operator==(const typename sequence<T>::iterator_impl &other) const override;
        bool operator!=(const typename sequence<T>::iterator_impl &other) const override;
    };

    list_sequence();
    list_sequence(const int &size);
    list_sequence(const T *items, const int &size);
    list_sequence(const std::initializer_list<T> &items);
    list_sequence(const sequence<T> &other);
    ~list_sequence();

    list_sequence &operator=(const list_sequence<T> &other);
    list_sequence<T> operator+(const T &value);

    T &get(const int index) override;
    T &get_first() override;
    T &get_last() override;
    const T &get(const int index) const override;
    const T &get_first() const override;
    const T &get_last() const override;

    int get_length() const override;

    sequence<T> &operator+=(const T &value) override;

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