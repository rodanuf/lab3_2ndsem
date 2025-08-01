#pragma once

template <typename T>
class sequence
{
protected:
    class iterator_impl
    {
    public:
        virtual ~iterator_impl() = default;

        virtual iterator_impl &operator++() = 0;
        virtual iterator_impl *operator++(int) = 0;
        virtual iterator_impl &operator--() = 0;
        virtual iterator_impl *operator--(int) = 0;
        virtual iterator_impl &operator=(const iterator_impl &other) = 0;
        virtual iterator_impl *operator+(const int n) const = 0;
        virtual iterator_impl *operator-(const int n) const = 0;

        virtual iterator_impl *clone() const = 0;

        virtual T &operator*() = 0;
        virtual const T &operator*() const = 0;

        virtual bool operator==(const iterator_impl &other) const = 0;
        virtual bool operator!=(const iterator_impl &other) const = 0;
    };

    virtual sequence<T>::iterator_impl *begin_impl() = 0;
    virtual sequence<T>::iterator_impl *end_impl() = 0;
    virtual sequence<T>::iterator_impl *cbegin_impl() const = 0;
    virtual sequence<T>::iterator_impl *cend_impl() const = 0;

public:
    class iterator
    {
    private:
        typename sequence<T>::iterator_impl *it;

    public:
        iterator();
        iterator(typename sequence<T>::iterator_impl *it);
        iterator(const iterator &other);
        ~iterator();

        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);
        iterator &operator=(const iterator &other);
        iterator operator+(const int n);
        iterator operator-(const int n);

        T &operator*();

        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;

        void set(const T &value);
        void erase();
    };
    class const_iterator
    {
    private:
        typename sequence<T>::iterator_impl *it;

    public:
        const_iterator();
        const_iterator(typename sequence<T>::iterator_impl *it);
        const_iterator(const const_iterator &other);
        ~const_iterator();

        const_iterator &operator++();
        const_iterator operator++(int);
        const_iterator &operator--();
        const_iterator operator--(int);
        const_iterator &operator=(const const_iterator &other);
        const_iterator operator+(const int n);
        const_iterator operator-(const int n);

        const T &operator*() const;

        bool operator==(const const_iterator &other) const;
        bool operator!=(const const_iterator &other) const;
    };
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

    virtual ~sequence() = default;

    virtual T &get(const int index) = 0;
    virtual T &get_first() = 0;
    virtual T &get_last() = 0;
    virtual const T &get(const int index) const = 0;
    virtual const T &get_first() const = 0;
    virtual const T &get_last() const = 0;

    virtual int get_length() const = 0;

    virtual sequence<T> &operator+(const T &value) = 0;
    virtual sequence<T> &operator+=(const T &value) = 0;

    virtual sequence<T> *get_subsequence(const int firs_index, const int last_index) const = 0;
    virtual sequence<T> *append_element(const T &element) = 0;
    virtual sequence<T> *prepend_element(const T &element) = 0;
    virtual sequence<T> *insert_element(const T &element, const int index) = 0;
    virtual sequence<T> *remove_at(const int index) = 0;
    virtual sequence<T> *concat(const sequence<T> &container) = 0;
    virtual sequence<T> *clone() const = 0;

    virtual sequence<T> *immutable_append_element(const T &element) const = 0;
    virtual sequence<T> *immutable_prepend_element(const T &element) const = 0;
    virtual sequence<T> *immutable_insert_element(const T &element, int index) const = 0;
    virtual sequence<T> *immutable_remove_at(const int index) const = 0;
    virtual sequence<T> *immutable_concat(const sequence<T> &container) const = 0;

    virtual void clear() = 0;
};

#include "../templates/sequence.tpp"