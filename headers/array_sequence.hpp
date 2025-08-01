#pragma once
#include "dynamic_array.hpp"
#include "sequence.hpp"

template <typename T>
class array_sequence : public sequence<T>
{
protected:
    typename array_sequence<T>::as_iterator *begin_impl() override;
    typename array_sequence<T>::as_iterator *end_impl() override;
    typename array_sequence<T>::const_as_iterator *cbegin_impl() const override;
    typename array_sequence<T>::const_as_iterator *cend_impl() const override;

private:
    dynamic_array<T> a_sequence;

public:
    class as_iterator : public sequence<T>::iterator_impl
    {
    private:
        typename dynamic_array<T>::array_iterator it;

    public:
        as_iterator(typename dynamic_array<T>::array_iterator it);
        as_iterator(const as_iterator &other);

        as_iterator &operator++() override;
        as_iterator *operator++(int) override;
        as_iterator &operator--() override;
        as_iterator *operator--(int) override;
        as_iterator &operator=(const typename sequence<T>::iterator_impl &other) override;
        as_iterator *operator+(const int n) const override;
        as_iterator *operator-(const int n) const override;

        as_iterator *clone() const override;

        T &operator*() override;
        const T &operator*() const override;

        bool operator==(const typename sequence<T>::iterator_impl &other) const override;
        bool operator!=(const typename sequence<T>::iterator_impl &other) const override;

        void set(const T &value);
        void erase();
    };
    class const_as_iterator : public sequence<T>::iterator_impl
    {
    private:
        typename dynamic_array<T>::const_array_iterator it;

    public:
        const_as_iterator(typename dynamic_array<T>::const_array_iterator it);
        const_as_iterator(const const_as_iterator &other);

        const_as_iterator &operator++() override;
        const_as_iterator *operator++(int) override;
        const_as_iterator &operator--() override;
        const_as_iterator *operator--(int) override;
        const_as_iterator &operator=(const typename sequence<T>::iterator_impl &other) override;
        const_as_iterator *operator+(const int n) const override;
        const_as_iterator *operator-(const int n) const override;

        const_as_iterator *clone() const override;

        T &operator*() override;
        const T &operator*() const override;

        bool operator==(const typename sequence<T>::iterator_impl &other) const override;
        bool operator!=(const typename sequence<T>::iterator_impl &other) const override;
    };

    array_sequence();
    array_sequence(const int &size);
    array_sequence(const T *items, const int &size);
    array_sequence(const std::initializer_list<T> &items);
    array_sequence(const array_sequence<T> &other);
    array_sequence(const sequence<T> &other);
    ~array_sequence();

    array_sequence<T> &operator=(const array_sequence<T> &other);

    T &operator[](const int index);
    const T &operator[](const int index) const;

    T &get(const int index) override;
    T &get_first() override;
    T &get_last() override;
    const T &get(const int index) const override;
    const T &get_first() const override;
    const T &get_last() const override;

    int get_length() const override;

    sequence<T> &operator+(const T &value) override;
    sequence<T> &operator+=(const T &value) override;

    sequence<T> *get_subsequence(const int start_index, const int end_index) const override;
    sequence<T> *append_element(const T &element) override;
    sequence<T> *prepend_element(const T &element) override;
    sequence<T> *insert_element(const T &element, const int index) override;
    sequence<T> *remove_at(const int index) override;
    sequence<T> *concat(const sequence<T> &container) override;
    sequence<T> *clone() const override;

    sequence<T> *immutable_append_element(const T &element) const override;
    sequence<T> *immutable_prepend_element(const T &element) const override;
    sequence<T> *immutable_insert_element(const T &element, int index) const override;
    sequence<T> *immutable_remove_at(const int index) const override;
    sequence<T> *immutable_concat(const sequence<T> &container) const override;
    void clear() override;
};

#include "../templates/array_sequence.tpp"