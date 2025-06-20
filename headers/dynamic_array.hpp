#pragma once

template <typename T>
class dynamic_array
{
private:
    T *data;
    size_t size;
    size_t capacity;

public:
    class array_iterator
    {
    private:
        T *ptr;

    public:
        array_iterator(T *ptr);
        array_iterator &operator++();
        array_iterator operator++(int);
        array_iterator &operator--();
        array_iterator operator--(int);
        array_iterator operator+(size_t n);
        array_iterator operator-(size_t n);
        T &operator*();
        T &operator[](size_t index);
        bool operator==(const array_iterator &other);
        bool operator!=(const array_iterator &other);
    };
    class const_array_iterator
    {
    private:
        const T *ptr;

    public:
        const_array_iterator(const T *ptr);
        const_array_iterator &operator++();
        const_array_iterator operator++(int);
        const_array_iterator &operator--();
        const_array_iterator operator--(int);
        const_array_iterator operator-(size_t n);
        const_array_iterator operator+(size_t n);
        const T &operator*();
        const T &operator[](size_t index);
        bool operator==(const const_array_iterator &other);
        bool operator!=(const const_array_iterator &other);
    };
    dynamic_array();
    dynamic_array(size_t capacity);
    dynamic_array(const T *data, const size_t size);
    dynamic_array(const dynamic_array &other);
    ~dynamic_array();
    T &get(const int index);
    T &get_first();
    T &get_last();
    int get_length();
    void append_element(const T &element);
    void prepend_element(const T &element);
    void insert_element(const T &element, const int index);
    void print();
    void clear();
    array_iterator begin();
    array_iterator end();
    array_iterator erase(const int index);
    const_array_iterator cbegin();
    const_array_iterator cend();
    const_array_iterator erase(const int index) const;
};