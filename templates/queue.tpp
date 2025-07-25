#include "../headers/queue.hpp"

template <typename T>
queue<T>::queue(sequence<T> *q) : container(q) {}

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
queue<T>::~queue()
{
    delete container;
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