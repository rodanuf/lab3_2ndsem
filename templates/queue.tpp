#include "../headers/queue.hpp"

template <typename T>
typename sequence<T>::iterator queue<T>::begin()
{
    return container->begin();
}

template <typename T>
typename sequence<T>::iterator queue<T>::end()
{
    return container->end();
}

template <typename T>
typename sequence<T>::const_iterator queue<T>::cbegin() const
{
    return container->cbegin();
}

template <typename T>
typename sequence<T>::const_iterator queue<T>::cend() const
{
    return container->cend();
}

template <typename T>
queue<T>::queue(sequence<T> *q) : container(q) {}

template <typename T>
queue<T>::queue(const std::initializer_list<T> &list, sequence<T> *s) : container(s)
{
    for (int i = 0; i < list.size(); i++)
    {
        container = container->append_element(*(list.begin() + i));
    }
}

template <typename T>
queue<T>::queue(const sequence<T> &other) : container(nullptr)
{
    container = other.clone();
}

template <typename T>
queue<T>::queue(const queue<T> &queue) : container(nullptr)
{
    container = queue.container->clone();
}

template <typename T>
queue<T>::queue(queue<T> &&other) : container(other.container)
{
    other.container = nullptr;
}

template <typename T>
queue<T>::~queue()
{
    delete container;
}

template <typename T>
queue<T> &queue<T>::operator=(const queue<T> &queue)
{
    if (this != &queue)
    {
        delete container;
        container = queue.container->clone();
    }
    return *this;
}

template <typename T>
queue<T> &queue<T>::operator=(const sequence<T> &other)
{
    delete container;
    container = other.clone();
    return *this;
}

template <typename T>
queue<T> queue<T>::operator+(const T &value)
{
    queue<T> new_queue = *this;
    new_queue.container = new_queue.container->append_element(value);
    return new_queue;
}

template <typename T>
queue<T> &queue<T>::operator+=(const T &value)
{
    container = container->append_element(value);
    return *this;
}

template <typename T>
int queue<T>::size() const
{
    return container->get_length();
}

template <typename T>
T &queue<T>::front()
{
    return container->get_first();
}

template <typename T>
const T &queue<T>::front() const
{
    return container->get_first();
}

template <typename T>
T &queue<T>::back()
{
    return container->get_last();
}

template <typename T>
const T &queue<T>::back() const
{
    return container->get_last();
}

template <typename T>
void queue<T>::push(const T &element)
{
    container = container->append_element(element);
}

template <typename T>
void queue<T>::pop()
{
    container = container->remove_at(0);
}

template <typename T>
void queue<T>::clear()
{
    container->clear();
}

template <typename T>
bool queue<T>::is_empty()
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