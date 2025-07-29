#pragma once
#include <initializer_list>

template <typename T>
class linked_list
{
private:
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
    int length;

public:
    class list_iterator
    {
    private:
        node **current;

    public:
        list_iterator(node *point);
        list_iterator(node **point);
        list_iterator(const list_iterator &other);
        list_iterator(const T &other);

        list_iterator &operator++();
        list_iterator operator++(int);
        list_iterator &operator--();
        list_iterator operator--(int);
        list_iterator &operator=(const list_iterator &other);
        list_iterator operator+(const int n);
        list_iterator operator-(const int n);

        node *operator*();
        const node *operator*() const;

        bool operator==(const list_iterator &other) const;
        bool operator!=(const list_iterator &other) const;

        void set(const T &element);
        void erase();
    };
    class const_list_iterator
    {
    private:
        node **current;

    public:
        const_list_iterator(node *point);
        const_list_iterator(node **point);
        const_list_iterator(const const_list_iterator &other);
        const_list_iterator(const T &other);

        const_list_iterator &operator++();
        const_list_iterator operator++(int);
        const_list_iterator &operator--();
        const_list_iterator operator--(int);
        const_list_iterator &operator=(const const_list_iterator &other);
        const_list_iterator operator+(const int n);
        const_list_iterator operator-(const int n);

        const node *operator*() const;

        bool operator==(const const_list_iterator &other) const;
        bool operator!=(const const_list_iterator &other) const;
    };

    list_iterator begin();
    list_iterator end();
    const_list_iterator cbegin() const;
    const_list_iterator cend() const;

    linked_list();
    linked_list(const int &size);
    linked_list(const T *data, const int &size);
    linked_list(const std::initializer_list<T> &ini_list);
    linked_list(const linked_list &other);
    ~linked_list();

    T &get(const int index);
    T &get_first();
    T &get_last();
    const T &get(const int index) const;
    const T &get_first() const;
    const T &get_last() const;

    int get_length() const;

    void append_element(const T &element);
    void prepend_element(const T &element);
    void insert_element(const T &element, int index);
    void remove_at(const int index);
    void clear();
};

#include "../templates/linked_list.tpp"