#include <iostream>
#include "../headers/linked_list.hpp"

template <typename T>
linked_list<T>::node::node(const T &item) : element(item), next(nullptr), prev(nullptr) {}

template <typename T>
linked_list<T>::node::~node() {}

template <typename T>
linked_list<T>::list_iterator::list_iterator(node *point) : current(&point)
{
    if (!point)
    {
        current = nullptr;
    }
}

template <typename T>
linked_list<T>::list_iterator::list_iterator(node **point) : current(point)
{
    if (!point || !*point)
    {
        current = nullptr;
    }
}

template <typename T>
linked_list<T>::list_iterator::list_iterator(const list_iterator &other) : current(other.current) {}

template <typename T>
typename linked_list<T>::list_iterator &linked_list<T>::list_iterator::operator++()
{
    *current = (*current)->next;
    return *this;
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::list_iterator::operator++(int)
{
    list_iterator temp(*this);
    current = &((*current)->next);
    return temp;
}

template <typename T>
typename linked_list<T>::list_iterator &linked_list<T>::list_iterator::operator--()
{
    *current = (*current)->prev;
    return *this;
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::list_iterator::operator--(int)
{
    list_iterator temp(*this);
    current = &((*current)->prev);
    return temp;
}

template <typename T>
typename linked_list<T>::list_iterator &linked_list<T>::list_iterator::operator=(const list_iterator &other)
{
    current = other.current;
    return *this;
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::list_iterator::operator+(const int n)
{
    list_iterator temp(*this);
    for (int i = 0; i < n; i++)
    {
        if (!*temp.current)
        {
            break;
        }
        *temp.current = (*temp.current)->next;
    }
    return temp;
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::list_iterator::operator-(const int n)
{
    list_iterator temp(*this);
    for (int i = 0; i < n; i++)
    {
        if (!*temp.current)
        {
            break;
        }
        *temp.current = (*temp.current)->prev;
    }
    return temp;
}

template <typename T>
typename linked_list<T>::node *linked_list<T>::list_iterator::operator*()
{
    if (!current)
    {
        return nullptr;
    }
    return *current;
}

template <typename T>
const typename linked_list<T>::node *linked_list<T>::list_iterator::operator*() const
{
    if (!current)
    {
        return nullptr;
    }
    return *current;
}

template <typename T>
T &linked_list<T>::list_iterator::operator[](const int index)
{
    node **it = current;
    if ((*it)->prev != nullptr)
    {
        while ((*it)->prev != nullptr)
        {
            *it = (*it)->prev;
        }
    }
    for (int i = 0; i < index; i++)
    {
        *it = (*it)->next;
    }
    return (*it)->element;
}

template <typename T>
bool linked_list<T>::list_iterator::operator==(const list_iterator &other) const
{
    return *current == *other.current;
}

template <typename T>
bool linked_list<T>::list_iterator::operator!=(const list_iterator &other) const
{
    return *current != *other.current;
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
    return list_iterator(&head);
}

template <typename T>
typename linked_list<T>::list_iterator linked_list<T>::end()
{
    return list_iterator(&tail->next);
}

template <typename T>
linked_list<T>::const_list_iterator::const_list_iterator(node *point) : current(&point)
{
    if (!point)
    {
        current = nullptr;
    }
}

template <typename T>
linked_list<T>::const_list_iterator::const_list_iterator(node **point) : current(point)
{
    if (!point || !*point)
    {
        current == nullptr;
    }
}

template <typename T>
linked_list<T>::const_list_iterator::const_list_iterator(const const_list_iterator &other) : current(other.current) {}

template <typename T>
typename linked_list<T>::const_list_iterator &linked_list<T>::const_list_iterator::operator++()
{
    *current = (*current)->next;
    return *this;
}

template <typename T>
typename linked_list<T>::const_list_iterator linked_list<T>::const_list_iterator::operator++(int)
{
    const_list_iterator temp(*this);
    current = &((*current)->next);
    return temp;
}

template <typename T>
typename linked_list<T>::const_list_iterator &linked_list<T>::const_list_iterator::operator--()
{
    *current = (*current)->prev;
    return *this;
}

template <typename T>
typename linked_list<T>::const_list_iterator linked_list<T>::const_list_iterator::operator--(int)
{
    const_list_iterator temp(*this);
    current = &((*current)->prev);
    return temp;
}

template <typename T>
typename linked_list<T>::const_list_iterator &linked_list<T>::const_list_iterator::operator=(const const_list_iterator &other)
{
    current = other.current;
    return *this;
}

template <typename T>
typename linked_list<T>::const_list_iterator linked_list<T>::const_list_iterator::operator+(const int n)
{
    const_list_iterator temp(*this);
    for (int i = 0; i < n; i++)
    {
        if (!*temp.current)
        {
            break;
        }
        *temp.current = (*temp.current)->next;
    }
    return temp;
}

template <typename T>
typename linked_list<T>::const_list_iterator linked_list<T>::const_list_iterator::operator-(const int n)
{
    const_list_iterator temp(*this);
    for (int i = 0; i < n; i++)
    {
        if (!*temp.current)
        {
            break;
        }
        *temp.current = (*temp.current)->prev;
    }
    return temp;
}

template <typename T>
const typename linked_list<T>::node *linked_list<T>::const_list_iterator::operator*() const
{
    if (!current)
    {
        return nullptr;
    }
    return *current;
}

template <typename T>
const T &linked_list<T>::const_list_iterator::operator[](const int index)
{
    node **it = current;
    if ((*it)->prev != nullptr)
    {
        while ((*it)->prev != nullptr)
        {
            *it = (*it)->prev;
        }
    }
    for (int i = 0; i < index; i++)
    {
        *it = (*it)->next;
    }
    return (*it)->element;
}

template <typename T>
bool linked_list<T>::const_list_iterator::operator==(const const_list_iterator &other) const
{
    return *current == *other.current;
}

template <typename T>
bool linked_list<T>::const_list_iterator::operator!=(const const_list_iterator &other) const
{
    return *current != *other.current;
}

template <typename T>
typename linked_list<T>::const_list_iterator linked_list<T>::cbegin() const
{
    return const_list_iterator(const_cast<node **>(&head));
}

template <typename T>
typename linked_list<T>::const_list_iterator linked_list<T>::cend() const
{
    return const_list_iterator(tail ? const_cast<node **>(&tail->next) : const_cast<node **>(&head));
}

template <typename T>
linked_list<T>::linked_list() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
linked_list<T>::linked_list(const int &size) : head(nullptr), tail(nullptr), length(0)
{
    for (int i = 0; i < size; i++)
    {
        append_element(T());
    }
}

template <typename T>
linked_list<T>::linked_list(const T *data, const int &size) : head(nullptr), tail(nullptr), length(0)
{
    for (int i = 0; i < size; i++)
    {
        append_element(data[i]);
    }
}

template <typename T>
linked_list<T>::linked_list(const std::initializer_list<T> &list) : head(nullptr), tail(nullptr), length(0)
{
    for (const auto &item : list)
    {
        append_element(item);
    }
}

template <typename T>
linked_list<T>::linked_list(const linked_list &other) : head(nullptr), tail(nullptr), length(other.length)
{
    if (other.head == nullptr)
    {
        return;
    }

    head = new node(other.head->element);
    node *current = head;
    node *src_current = other.head->next;

    while (src_current != nullptr)
    {
        current->next = new node(src_current->element);
        current->next->prev = current;
        current = current->next;
        src_current = src_current->next;
    }

    tail = current;
}

template <typename T>
linked_list<T>::~linked_list()
{
    clear();
}

template <typename T>
T &linked_list<T>::get(const int index) const
{
    const_list_iterator it = cbegin();
    for (int i = 0; i < index; i++)
    {
        it++;
    }
    return const_cast<T &>((*it)->element);
}

template <typename T>
T &linked_list<T>::get_first() const
{
    return head->element;
}

template <typename T>
T &linked_list<T>::get_last() const
{
    return tail->element;
}

template <typename T>
int linked_list<T>::get_length() const
{
    return length;
}

template <typename T>
void linked_list<T>::append_element(const T &element)
{
    node *new_node = new node(element);
    if (!tail)
    {
        head = tail = new_node;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    length++;
}

template <typename T>
void linked_list<T>::prepend_element(const T &element)
{
    node *new_node = new node(element);
    if (!head)
    {
        head = tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    length++;
}

template <typename T>
void linked_list<T>::insert_element(const T &element, int index)
{
    list_iterator it = begin();
    for (int i = 0; i < index; i++)
    {
        it++;
    }
    node *new_node = new node(element);
    new_node->next = *it;
    new_node->prev = (*it)->prev;
    (*it)->prev->next = new_node;
    (*it)->prev = new_node;
    length++;
}

template <typename T>
void linked_list<T>::clear()
{
    node *current = head;
    while (current)
    {
        auto buffer_ptr = current;
        current = current->next;
        delete buffer_ptr;
        length--;
    }
    head = tail = nullptr;
}