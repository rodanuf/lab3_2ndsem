#pragma once
#include <initializer_list>

template <typename T>
class dynamic_array
{
private:
    T *data;
    int length;
    int capacity;

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
        array_iterator operator+(const int n);
        array_iterator operator-(const int n);
        T &operator*();
        bool operator==(const array_iterator &other) const;
        bool operator!=(const array_iterator &other) const;
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
        const_array_iterator operator-(const int n);
        const_array_iterator operator+(const int n);
        const T &operator*();
        bool operator==(const const_array_iterator &other) const;
        bool operator!=(const const_array_iterator &other) const;
    };
    array_iterator begin();
    array_iterator end();
    const_array_iterator cbegin() const;
    const_array_iterator cend() const;
    dynamic_array();
    dynamic_array(const int &size);
    dynamic_array(const T *data, const int &size);
    dynamic_array(const std::initializer_list<T> &list);
    dynamic_array(const dynamic_array &other);
    ~dynamic_array();
    T &operator[](const int index);
    const T &operator[](const int index) const;
    T &get(const int index) const;
    T &get_first() const;
    T &get_last() const;
    int get_length() const;
    void resize(const int &new_size);
    void append_element(const T &element);
    void prepend_element(const T &element);
    void insert_element(const T &element, int index);
    void remove_at(const int index);
    void clear();
};

#include "../templates/dynamic_array.tpp"