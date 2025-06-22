#pragma once

template <typename T>
class dynamic_array
{
private:
    T *data;
    size_t length;
    size_t capacity;

public:
    class array_iterator
    {
    private:
        T *current;

    public:
        array_iterator(T *ptr);
        array_iterator(const array_iterator &other);
        array_iterator &operator++();
        array_iterator operator++(int);
        array_iterator &operator--();
        array_iterator operator--(int);
        array_iterator &operator=(const array_iterator &other);
        array_iterator operator+(size_t n);
        array_iterator operator-(size_t n);
        T &operator*();
        T &operator[](size_t index);
        bool operator==(const array_iterator &other);
        bool operator!=(const array_iterator &other);
        void set(const T &element);
        void erase();
    };
    class const_array_iterator
    {
    private:
        const T *current;

    public:
        const_array_iterator(const T *ptr);
        const_array_iterator(const const_array_iterator &other);
        const_array_iterator &operator++();
        const_array_iterator operator++(int);
        const_array_iterator &operator--();
        const_array_iterator operator--(int);
        const_array_iterator &operator=(const const_array_iterator &other);
        const_array_iterator operator-(size_t n);
        const_array_iterator operator+(size_t n);
        const T &operator*();
        const T &operator[](size_t index);
        bool operator==(const const_array_iterator &other);
        bool operator!=(const const_array_iterator &other);
    };
    array_iterator begin();
    array_iterator end();
    const_array_iterator cbegin() const;
    const_array_iterator cend() const;
    dynamic_array();
    dynamic_array(const size_t &size);
    dynamic_array(const T *data, const size_t &size);
    dynamic_array(const std::initializer_list<T> &list);
    dynamic_array(const dynamic_array &other);
    ~dynamic_array();
    T &get(const int &index);
    T &get_first();
    T &get_last();
    size_t get_length() const;
    void resize(const size_t &new_size);
    void append_element(const T &element);
    void prepend_element(const T &element);
    void insert_element(const T &element, int &index);
    void print() const;
    void clear();
};

#include "../templates/dynamic_array.tpp"