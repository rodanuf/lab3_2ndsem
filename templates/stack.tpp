#include <stdexcept>
#include "../headers/stack.hpp"

template <typename T>
typename sequence<T>::iterator stack<T>::begin()
{
    return container->begin();
}

template <typename T>
typename sequence<T>::iterator stack<T>::end()
{
    return container->end();
}

template <typename T>
typename sequence<T>::const_iterator stack<T>::cbegin() const
{
    return container->cbegin();
}

template <typename T>
typename sequence<T>::const_iterator stack<T>::cend() const
{
    return container->cend();
}

template <typename T>
stack<T>::stack(sequence<T> *s) : container(s) {}

template <typename T>
stack<T>::stack(const std::initializer_list<T> &list, sequence<T> *s) : container(s)
{
    for (int i = 0; i < list.size(); i++)
    {
        container->append_element(*(list.begin() + i));
    }
}

template <typename T>
stack<T>::stack(const sequence<T> &sequence) : container(nullptr)
{
    container = sequence.clone();
}

template <typename T>
stack<T>::stack(const stack<T> &stack) : container(nullptr)
{
    container = stack.container->clone();
}

template <typename T>
stack<T>::~stack()
{
    delete container;
}

template <typename T>
stack<T> &stack<T>::operator=(const stack<T> &stack)
{
    if (this != &stack)
    {
        delete container;
        container = stack.container->clone();
    }
    return *this;
}

template <typename T>
stack<T> &stack<T>::operator=(const sequence<T> &sequence)
{
    delete container;
    container = sequence.clone();
    return *this;
}

template <typename T>
stack<T> stack<T>::operator+(const T &value)
{
    stack<T> new_stack = *this;
    new_stack.container = new_stack.container->append_element(value);
    return new_stack;
}

template <typename T>
stack<T> &stack<T>::operator+=(const T &value)
{
    container = container->append_element(value);
    return *this;
}

template <typename T>
int stack<T>::size() const
{
    return container->get_length();
}

template <typename T>
T &stack<T>::top()
{
    return container->get_last();
}

template <typename T>
const T &stack<T>::top() const
{
    return container->get_last();
}

template <typename T>
void stack<T>::push(const T &element)
{
    container = container->append_element(element);
}

template <typename T>
void stack<T>::pop()
{
    container = container->remove_at(size() - 1);
}
template <typename T>
void stack<T>::clear()
{
    container->clear();
}

template <typename T>
bool stack<T>::is_empty()
{
    if (container->get_length() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
