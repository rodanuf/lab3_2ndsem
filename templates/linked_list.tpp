#include "../headers/linked_list.hpp"

template <typename T>
linked_list<T>::node::node(const T &item) : element(item), next(nullptr), prev(nullptr) {}

template <typename T>
linked_list<T>::node::~node()
{
    next->prev = prev;
    prev->next = next;
}

template <typename T>
linked_list<T>::list_iterator::list_iterator(node *point) : current(point) {}

template <typename T>
linked_list<T>::list_iterator::list_iterator(const list_iterator &other) : current(other.current) {}

template <typename T>
typename linked_list<T>::list_iterator &linked_list<T>::list_iterator::operator++()
{
    current = &(*(current)->next);
    return *this;
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::list_iterator::operator++(int)
{
    list_iterator temp = *this;
    current = &(*(current)->next);
    return temp;
}

template <typename T>
typename linked_list<T>::list_iterator &linked_list<T>::list_iterator::operator--()
{
    current = &(*(current)->prev);
    return *this;
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::list_iterator::operator--(int)
{
    list_iterator temp = *this;
    current = &(*(current)->next);
    return temp;
}

template <typename T>
typename linked_list<T>::list_iterator &linked_list<T>::list_iterator::operator=(const list_iterator &other)
{
    current = other.current;
    return *this;
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::list_iterator::operator+(const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        current = &(*(current)->next);
    }
    return current;
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::list_iterator::operator-(const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        current = &(*(current)->prev);
    }
    return current;
}

template <typename T>
T &linked_list<T>::list_iterator::operator*()
{
    return (*current)->element;
}

template <typename T>
T &linked_list<T>::list_iterator::operator[](const size_t &index)
{
    for (size_t i = 0; i < index; i++)
    {
        current = &(*(current)->next);
    }
    return (*current)->element;
}

template <typename T>
bool linked_list<T>::list_iterator::operator==(const list_iterator &other) const
{
    return current == other.current;
}

template <typename T>
bool linked_list<T>::list_iterator::operator!=(const list_iterator &other) const
{
    return current != other.current;
}

template <typename T>
void linked_list<T>::list_iterator::set(const T &elenent)
{
    (*current)->element = elenent;
}

template <typename T>
void linked_list<T>::list_iterator::erase()
{
    (*current)->element = T();
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::begin()
{
    return list_iterator(head);
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::end()
{
    return list_iterator(tail);
}

template <typename T>
linked_list<T>::const_linst_iterator::const_list_iterator(const node *point) : current(point) {}

template <typename T>
linked_list<T>::const_linst_iterator::const_list_iterator(const const_list_iterator &other) : current(other.current) {}

template <typename T>
typename linked_list<T>::const_linst_iterator &linked_list<T>::const_linst_iterator::operator++()
{
    current = &(*(current)->next);
    return *this;
}

template <typename T>
typename linked_list<T>::const_linst_iterator linked_list<T>::const_linst_iterator::operator++(int)
{
    const_list_iterator temp = *this;
    current = &(*(current)->next);
    return temp;
}

template <typename T>
typename linked_list<T>::const_linst_iterator &linked_list<T>::const_linst_iterator::operator--()
{
    current = &(*(current)->prev);
    return *this;
}

template <typename T>
typename linked_list<T>::const_linst_iterator linked_list<T>::const_linst_iterator::operator--(int)
{
    const_list_iterator temp = *this;
    current = &(*(current)->next);
    return temp;
}

template <typename T>
typename linked_list<T>::const_linst_iterator &linked_list<T>::const_linst_iterator::operator=(const const_list_iterator &other)
{
    current = other.current;
    return *this;
}

template <typename T>
typename linked_list<T>::const_linst_iterator linked_list<T>::const_linst_iterator::operator+(const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        current = &(*(current)->next);
    }
    return current;
}

template <typename T>
typename linked_list<T>::const_linst_iterator linked_list<T>::const_linst_iterator::operator-(const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        current = &(*(current)->prev);
    }
    return current;
}

template <typename T>
const T &linked_list<T>::const_linst_iterator::operator*()
{
    return (*current)->element;
}

template <typename T>
const T &linked_list<T>::const_linst_iterator::operator[](const size_t &index)
{
    for (size_t i = 0; i < index; i++)
    {
        current = &(*(current)->next);
    }
    return (*current)->element;
}

template <typename T>
bool linked_list<T>::const_linst_iterator::operator==(const const_list_iterator &other) const
{
    return current == other.current;
}

template <typename T>
bool linked_list<T>::const_linst_iterator::operator!=(const const_list_iterator &other) const
{
    return current != other.current;
}

template <typename T>
typename linked_list<T>::const_linst_iterator linked_list<T>::cbegin() const
{
    return const_list_iterator(head);
}

template <typename T>
typename linked_list<T>::const_linst_iterator linked_list<T>::cend() const
{
    return const_list_iterator(tail);
}

template <typename T>
linked_list<T>::linked_list() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
linked_list<T>::linked_list(const size_t &size)
{
    length = size;
    head = new node(T());
    tail = head;
    for (size_t i = 0; i < size; i++)
    {
        node new_node = node(T());
        new_node.next = (*(head)->next);
        (*(head)->next) = &new_node;
        new_node.prev = head;
    }
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
}
