#pragma once

template <typename T>
class linked_list
{
    struct node
    {
        T element;
        node *next;
        node *prev;
        node(const T &item);
        ~node();
    };

    node *head;
    node *tail;
    size_t length;

public:
    class list_iterator
    {
    private:
        node **current;

    public:
        list_iterator(node *point);
        list_iterator(const list_iterator &other);
        list_iterator &operator++();
        list_iterator operator++(int);
        list_iterator &operator--();
        list_iterator operator--(int);
        list_iterator &operator=(const list_iterator &other);
        list_iterator operator+(const size_t n);
        list_iterator operator-(const size_t n);
        T &operator*();
        T &operator[](const size_t index);
        bool operator==(const list_iterator &other) const;
        bool operator!=(const list_iterator &other) const;
        void set(const T &element);
        void erase();
    };
    class const_list_iterator
    {
    private:
        const node **current;

    public:
        const_list_iterator(const node *point);
        const_list_iterator(const const_list_iterator &other);
        const_list_iterator &operator++();
        const_list_iterator operator++(int);
        const_list_iterator &operator--();
        const_list_iterator operator--(int);
        const_list_iterator &operator=(const const_list_iterator &other);
        const_list_iterator operator+(const size_t n);
        const_list_iterator operator-(const size_t n);
        const T &operator*();
        const T &operator[](const size_t index);
        bool operator==(const const_list_iterator &other) const;
        bool operator!=(const const_list_iterator &other) const;
    };
    list_iterator begin();
    list_iterator end();
    const_list_iterator cbegin() const;
    const_list_iterator cend() const;
    linked_list();
    linked_list(const size_t &size);
    linked_list(const T *data, const size_t &size);
    linked_list(const std::initializer_list<T> &ini_list);
    linked_list(const linked_list &other);
    ~linked_list();
    T &get(int index) const;
    T &get_first() const;
    T &get_last() const;
    size_t get_length() const;
    void append_element(const T &element);
    void prepend_element(const T &element);
    void insert_element(const T &element, int index);
    void print() const;
    void clear();
};

#include "../templates/linked_list.tpp"