#pragma once

template <typename T>
class sequence
{
protected:
    template <typename T>
    class iterator_impl
    {
    public:
        virtual ~iterator_impl() = default;

        virtual iterator_impl &operator++() = 0;
        virtual iterator_impl operator++(int) = 0;
        virtual iterator_impl &operator=(const iterator_impl &other) = 0;
        virtual T &operator*() = 0;
    };

    virtual iterator_impl<T> *begin_impl() = 0;
    virtual iterator_impl<T> *end_impl() = 0;

public:
    class iterator
    {
    private:
        iterator_impl<T> *it;

    public:
        iterator();
        iterator(iterator_impl<T> *it);
        iterator(const iterator &other);
        ~iterator();

        iterator &operator++();
        iterator operator++(int);
        iterator &operator=(const iterator &other);
        T &operator*();
    };
    class const_iterator
    {
    private:
        const iterator_impl<T> *it;

    public:
        const_iterator();
        const_iterator(const iterator_impl<T> *it);
        const_iterator(const const_iterator &other);
        ~const_iterator() = default;

        const_iterator &operator++();
        const_iterator operator++(int);
        const_iterator &operator=(const const_iterator &other);
        const T &operator*() const;
    };
    iterator begin();
    iterator end();
    const_iterator cbegin();
    const_iterator cend();

    virtual ~sequence() = default;

    virtual T &get(const int index) = 0;
    virtual T &get_first() = 0;
    virtual T &get_last() = 0;
    virtual int get_length() const = 0;

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