#pragma once

template <typename T>
class linked_list
{
    struct node
    {
        T element;
        node *next;
        node *prev;
        node(const T &element);
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
        list_iterator(node *current);
        list_iterator &operator++();
        list_iterator operator++(int);
        list_iterator &operator--();
        list_iterator operator--(int);
        T &operator*();
        T &operator[](const int &index);
        bool operator==(const list_iterator &other) const;
        bool operator!=(const list_iterator &other) const;
        list_iterator operator=(const list_iterator &other);
        list_iterator operator+(const int &index);
        list_iterator operator-(const int &index);
    };
    class const_list_iterator
    {
    private:
        const node **current;

    public:
        const_list_iterator(const node *current);
        const_list_iterator &operator++();
        const_list_iterator operator++(int);
        const_list_iterator &operator--();
        const_list_iterator operator--(int);
        const T &operator*();
        const T &operator[](const int &index);
        bool operator==(const const_list_iterator &other) const;
        bool operator!=(const const_list_iterator &other) const;
        const_list_iterator operator=(const const_list_iterator &other);
        const_list_iterator operator+(const int &index);
        const_list_iterator operator-(const int &index);
    };
    linked_list();
    linked_list(const size_t length);
    linked_list(const T *data, const size_t length);
    linked_list(const linked_list &other);
    ~linked_list();
    T &get(const int &index) const;
    T &get_first() const;
    T &get_last() const;
    int get_length() const;
    void append_element(const T &element);
    void prepend_element(const T &element);
    void insert_element(const T &element, const int &index);
    void print();
    void clear();
    list_iterator begin();
    list_iterator end();
    list_iterator erase(const int &index);
    const_list_iterator cbegin() const;
    const_list_iterator cend() const;
    const_list_iterator erase(const T &element) const;
};