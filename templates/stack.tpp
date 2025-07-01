#include <iostream>
#include "../headers/stack.hpp"

template <typename T>
stack<T>::node::node(const T &item) : element(item), next(nullptr) {}

template <typename T>
stack<T>::st_iterator::st_iterator(node *point) : current(&point) {}

template <typename T>
stack<T>::st_iterator::st_iterator(node **point) : current(point) {}

template <typename T>
stack<T>::st_iterator::st_iterator(const st_iterator &other) : current(other.current) {}

template <typename T>
typename stack<T>::st_iterator &stack<T>::st_iterator::operator++()
{
    *current = (*current)->next;
    return *this;
}

template <typename T>
typename stack<T>::st_iterator stack<T>::st_iterator::operator++(int)
{
    st_iterator temp(*this);
    current = &((*current)->next);
    return temp;
}

template <typename T>
typename stack<T>::st_iterator &stack<T>::st_iterator::operator=(const st_iterator &other)
{
    current = other.current;
    return *this;
}

template <typename T>
typename stack<T>::st_iterator stack<T>::st_iterator::operator+(const int n)
{
    for (int i = 0; i < n; ++i)
    {
        ++(*this);
    }
    return *this;
}

template <typename T>
typename stack<T>::node *stack<T>::st_iterator::operator*() const
{
    return *current;
}

template <typename T>
T &stack<T>::st_iterator::operator*()
{
    return (*current)->element;
}

template <typename T>
bool stack<T>::st_iterator::operator==(const typename sequence<T>::iterator &other) const
{
    const st_iterator &derived = dynamic_cast<const st_iterator &>(other);
    return current == derived.current;
}

template <typename T>
bool stack<T>::st_iterator::operator!=(const typename sequence<T>::iterator &other) const
{
    const st_iterator &derived = dynamic_cast<const st_iterator &>(other);
    return current != derived.current;
}

template <typename T>
void stack<T>::st_iterator::set(const T &element)
{
    (*current)->element = element;
}

template <typename T>
void stack<T>::st_iterator::erase()
{
    (*current)->element = T();
}

template <typename T>
typename stack<T>::st_iterator stack<T>::begin()
{
    return st_iterator(&head);
}

template <typename T>
typename stack<T>::st_iterator stack<T>::end()
{
    return st_iterator(static_cast<node *>(nullptr));
}

template <typename T>
stack<T>::const_st_iterator::const_st_iterator(node *point) : current(&point) {}

template <typename T>
stack<T>::const_st_iterator::const_st_iterator(node **point) : current(point) {}

template <typename T>
stack<T>::const_st_iterator::const_st_iterator(const const_st_iterator &other) : current(other.current) {}

template <typename T>
typename stack<T>::const_st_iterator &stack<T>::const_st_iterator::operator++()
{
    *current = (*current)->next;
    return *this;
}

template <typename T>
typename stack<T>::const_st_iterator stack<T>::const_st_iterator::operator++(int)
{
    const_st_iterator temp(*this);
    current = &((*current)->next);
    return temp;
}

template <typename T>
typename stack<T>::const_st_iterator &stack<T>::const_st_iterator::operator=(const const_st_iterator &other)
{
    current = other.current;
    return *this;
}

template <typename T>
typename stack<T>::const_st_iterator stack<T>::const_st_iterator::operator+(const int n)
{
    for (int i = 0; i < n; ++i)
    {
        ++(*this);
    }
    return *this;
}

template <typename T>
const typename stack<T>::node *stack<T>::const_st_iterator::operator*() const
{
    return *current;
}

template <typename T>
const T &stack<T>::const_st_iterator::operator*()
{
    return (*current)->element;
}

template <typename T>
bool stack<T>::const_st_iterator::operator==(const typename sequence<T>::const_iterator &other) const
{
    const const_st_iterator &derived = dynamic_cast<const const_st_iterator &>(other);
    return current == derived.current;
}

template <typename T>
bool stack<T>::const_st_iterator::operator!=(const typename sequence<T>::const_iterator &other) const
{
    const const_st_iterator &derived = dynamic_cast<const const_st_iterator &>(other);
    return current != derived.current;
}

template <typename T>
typename stack<T>::const_st_iterator stack<T>::cbegin() const
{
    return const_st_iterator(const_cast<node **>(&head));
}

template <typename T>
typename stack<T>::const_st_iterator stack<T>::cend() const
{
    return const_st_iterator(static_cast<node *>(nullptr));
}

template <typename T>
stack<T>::stack() : head(nullptr), length(0) {}

template <typename T>
stack<T>::stack(const int &size)
{
    if (size < 0)
    {
        throw std::invalid_argument("Size cannot be negative");
    }
    head = nullptr;
    length = 0;
    for (int i = 0; i < size; ++i)
    {
        prepend_element(T());
    }
}

template <typename T>
stack<T>::stack(const T *items, const int &size)
{
    if (size < 0)
    {
        throw std::invalid_argument("Size cannot be negative");
    }
    head = nullptr;
    length = 0;
    for (int i = 0; i < size; ++i)
    {
        prepend_element(items[i]);
    }
}

template <typename T>
stack<T>::stack(const std::initializer_list<T> &items)
{
    head = nullptr;
    length = 0;
    for (const T &item : items)
    {
        prepend_element(item);
    }
}

template <typename T>
stack<T>::stack(const sequence<T> &sequence)
{
    head = nullptr;
    length = 0;
    for (int i = 0; i < sequence.get_length(); ++i)
    {
        prepend_element(sequence.get(i));
    }
}

template <typename T>
stack<T>::stack(const stack<T> &other)
{
    head = nullptr;
    length = 0;
    for (int i = other.get_length() - 1; i > -1; --i)
    {
        prepend_element(other.get(i));
    }
}

template <typename T>
stack<T>::~stack()
{
    while (head)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
T &stack<T>::get(const int index) const
{
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("Index out of range");
    }
    node *current = head;
    for (int i = 0; i < index; ++i)
    {
        current = current->next;
    }
    return current->element;
}

template <typename T>
T &stack<T>::get_first() const
{
    if (!head)
    {
        throw std::out_of_range("Stack is empty");
    }
    return head->element;
}

template <typename T>
T &stack<T>::get_last() const
{
    if (!head)
    {
        throw std::out_of_range("Stack is empty");
    }
    node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return current->element;
}

template <typename T>
int stack<T>::get_length() const
{
    return length;
}

template <typename T>
sequence<T> *stack<T>::get_subsequence(const int start_index, const int end_index) const
{
    if (start_index < 0 || end_index >= length || start_index > end_index)
    {
        throw std::out_of_range("Invalid range");
    }
    stack<T> *subsequence = new stack<T>();
    node *current = head;
    for (int i = 0; i < start_index; ++i)
    {
        current = current->next;
    }
    for (int i = start_index; i <= end_index; ++i)
    {
        subsequence->append_element(current->element);
        current = current->next;
    }
    return subsequence;
}

template <typename T>
sequence<T> *stack<T>::append_element(const T &element)
{
    if (!head)
    {
        return prepend_element(element);
    }
    stack<T> *new_stack = new stack<T>(*this);
    node *new_node = new node(element);
    clear();
    head = new_node;
    for (int i = new_stack->get_length() - 1; i > -1; i--)
    {
        prepend_element(new_stack->get(i));
    }
    delete new_stack;
    length++;
    return this;
}

template <typename T>
sequence<T> *stack<T>::prepend_element(const T &element)
{
    node *new_node = new node(element);
    new_node->next = head;
    head = new_node;
    length++;
    return this;
}

template <typename T>
sequence<T> *stack<T>::insert_element(const T &element, const int index)
{
    if (!head)
    {
        return append_element(element);
    }
    stack<T> *new_stack = new stack<T>();
    for (int i = 0; i < index; i++)
    {
        new_stack->prepend_element(get(i));
        node *current = head;
        head = head->next;
        delete current;
        length--;
    }
    prepend_element(element);
    for (int i = 0; i < new_stack->get_length(); i++)
    {
        prepend_element(new_stack->get(i));
    }
    delete new_stack;
    return this;
}

template <typename T>
sequence<T> *stack<T>::concat(const sequence<T> &sequence)
{
    stack<T> *new_stack = new stack<T>(*this);
    clear();
    for (int i = 0; i < sequence.get_length(); i++)
    {
        prepend_element(sequence.get(i));
    }
    for (int i = 0; i < new_stack->get_length(); i++)
    {
        prepend_element(new_stack->get(i));
    }
    return this;
}

template <typename T>
sequence<T> *stack<T>::immutable_append_element(const T &element) const
{
    stack<T> *new_stack = new stack<T>(*this);
    new_stack->append_element(element);
    return new_stack;
}

template <typename T>
sequence<T> *stack<T>::immutable_prepend_element(const T &element) const
{
    stack<T> *new_stack = new stack<T>(*this);
    new_stack->prepend_element(element);
    return new_stack;
}

template <typename T>
sequence<T> *stack<T>::immutable_insert_element(const T &element, const int index) const
{
    stack<T> *new_stack = new stack<T>(*this);
    new_stack->insert_element(element, index);
    return new_stack;
}

template <typename T>
sequence<T> *stack<T>::immutable_concat(const sequence<T> &other) const
{
    stack<T> *new_stack = new stack<T>(*this);
    new_stack->concat(other);
    return new_stack;
}

template <typename T>
void stack<T>::clear()
{
    while (head)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}