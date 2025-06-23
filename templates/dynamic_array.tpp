#include <iostream>
#include "../headers/dynamic_array.hpp"

template <typename T>
dynamic_array<T>::array_iterator::array_iterator(T *ptr) : current(ptr) {}

template <typename T>
dynamic_array<T>::array_iterator::array_iterator(const array_iterator &other) : current(other.current) {}

template <typename T>
typename dynamic_array<T>::array_iterator &dynamic_array<T>::array_iterator::operator++()
{
    current++;
    return *this;
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator++(int)
{
    array_iterator temp = *this;
    current++;
    return temp;
}

template <typename T>
typename dynamic_array<T>::array_iterator &dynamic_array<T>::array_iterator::operator--()
{
    current--;
    return *this;
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator--(int)
{
    array_iterator temp = *this;
    current--;
    return temp;
}

template <typename T>
typename dynamic_array<T>::array_iterator &dynamic_array<T>::array_iterator::operator=(const array_iterator &other)
{
    if (this != &other)
    {
        current = other.current;
    }
    return *this;
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator+(size_t n)
{
    current += n;
    return *this;
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator-(size_t n)
{
    current -= n;
    return *this;
}

template <typename T>
T &dynamic_array<T>::array_iterator::operator*()
{
    return *current;
}

template <typename T>
T &dynamic_array<T>::array_iterator::operator[](size_t index)
{
    return *(current + index);
}

template <typename T>
bool dynamic_array<T>::array_iterator::operator==(const array_iterator &other) const
{
    return current == other.current;
}

template <typename T>
bool dynamic_array<T>::array_iterator::operator!=(const array_iterator &other) const
{
    return current != other.current;
}

template <typename T>
void dynamic_array<T>::array_iterator::set(const T &element)
{
    *current = element;
}

template <typename T>
void dynamic_array<T>::array_iterator::erase()
{
    *current = T();
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::begin()
{
    return array_iterator(data);
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::end()
{
    return array_iterator(data + length);
}

template <typename T>
dynamic_array<T>::const_array_iterator::const_array_iterator(const T *ptr) : current(ptr) {}

template <typename T>
dynamic_array<T>::const_array_iterator::const_array_iterator(const const_array_iterator &other) : current(other.current) {}

template <typename T>
typename dynamic_array<T>::const_array_iterator &dynamic_array<T>::const_array_iterator::operator++()
{
    current++;
    return *this;
}

template <typename T>
typename dynamic_array<T>::const_array_iterator dynamic_array<T>::const_array_iterator::operator++(int)
{
    const_array_iterator temp = *this;
    current++;
    return temp;
}

template <typename T>
typename dynamic_array<T>::const_array_iterator &dynamic_array<T>::const_array_iterator::operator--()
{
    current--;
    return *this;
}

template <typename T>
typename dynamic_array<T>::const_array_iterator dynamic_array<T>::const_array_iterator::operator--(int)
{
    const_array_iterator temp = *this;
    current--;
    return temp;
}

template <typename T>
typename dynamic_array<T>::const_array_iterator &dynamic_array<T>::const_array_iterator::operator=(const const_array_iterator &other)
{
    if (this != &other)
    {
        current = other.current;
    }
    return *this;
}

template <typename T>
typename dynamic_array<T>::const_array_iterator dynamic_array<T>::const_array_iterator::operator+(size_t n)
{
    current += n;
    return *this;
}

template <typename T>
typename dynamic_array<T>::const_array_iterator dynamic_array<T>::const_array_iterator::operator-(size_t n)
{
    current -= n;
    return *this;
}

template <typename T>
const T &dynamic_array<T>::const_array_iterator::operator*()
{
    return *current;
}

template <typename T>
const T &dynamic_array<T>::const_array_iterator::operator[](size_t index)
{
    return *(current + index);
}

template <typename T>
bool dynamic_array<T>::const_array_iterator::operator==(const const_array_iterator &other) const
{
    return current == other.current;
}

template <typename T>
bool dynamic_array<T>::const_array_iterator::operator!=(const const_array_iterator &other) const
{
    return current != other.current;
}

template <typename T>
typename dynamic_array<T>::const_array_iterator dynamic_array<T>::cbegin() const
{
    return const_array_iterator(data);
}

template <typename T>
typename dynamic_array<T>::const_array_iterator dynamic_array<T>::cend() const
{
    return const_array_iterator(data + length);
}

template <typename T>
dynamic_array<T>::dynamic_array() : data(new T[1]()), length(0), capacity(1) {}

template <typename T>
dynamic_array<T>::dynamic_array(const size_t &size) : data(new T[2 * size]()), length(size), capacity(2 * size) {}

template <typename T>
dynamic_array<T>::dynamic_array(const T *data, const size_t &size) : data(new T[2 * size]()), length(size), capacity(2 * size)
{
    for (size_t i = 0; i < size; i++)
    {
        this->data[i] = data[i];
    }
}

template <typename T>
dynamic_array<T>::dynamic_array(const std::initializer_list<T> &list) : data(new T[2 * list.size()]), length(list.size()), capacity(2 * list.size())
{
    array_iterator it = begin();
    auto list_it = list.begin();
    for (int i = 0; i < length; i++)
    {
        it[i] = *(list.begin() + i);
    }
}

template <typename T>
dynamic_array<T>::dynamic_array(const dynamic_array<T> &other) : data(new T[other.capacity]), length(other.length), capacity(other.capacity)
{
    array_iterator it = begin();
    const_array_iterator other_it = other.cbegin();
    for (; it != end(); ++it, ++other_it)
    {
        *it = *other_it;
    }
}

template <typename T>
dynamic_array<T>::~dynamic_array()
{
    delete[] data;
}

template <typename T>
T &dynamic_array<T>::get(int index)
{
    if (index >= 0)
    {
        return data[index];
    }
    else
    {
        return data[length + index];
    }
}

template <typename T>
T &dynamic_array<T>::get_first()
{
    return data[0];
}

template <typename T>
T &dynamic_array<T>::get_last()
{
    return data[length - 1];
}

template <typename T>
size_t dynamic_array<T>::get_length() const
{
    return length;
}

template <typename T>
void dynamic_array<T>::resize(const size_t &new_size)
{
    size_t old_length = length;
    length = new_size;
    if (new_size < capacity && new_size > old_length)
    {
        return;
    }
    capacity = 2 * new_size;
    T *new_data = new T[capacity];
    for (size_t i = 0; i < new_size; i++)
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
}

template <typename T>
void dynamic_array<T>::append_element(const T &element)
{
    if (length == capacity)
    {
        resize(capacity);
    }
    else
    {
        length++;
    }
    *(end() - 1) = element;
}

template <typename T>
void dynamic_array<T>::prepend_element(const T &element)
{
    if (length == capacity)
    {
        resize(capacity);
    }
    else
    {
        length++;
    }
    array_iterator dest = end() - 1;
    array_iterator src = end() - 2;
    while (dest != begin())
    {
        *dest = *src;
        --dest;
        --src;
    }
    *begin() = element;
}

template <typename T>
void dynamic_array<T>::insert_element(const T &element, int index)
{
    int old_length = length;
    if (index < 0)
    {
        if ((-index) >= capacity)
        {
            length = (-index);
            capacity = 2 * length;
            T *new_data = new T[capacity];
            for (int i = 0; i < old_length; i++)
            {
                new_data[i + (length - old_length)] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        index = index + length;
    }
    else
    {
        if (index >= capacity)
        {
            resize(index);
        }
    }
    for (size_t i = length; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = element;
    if (old_length == length)
    {
        length++;
    }
}

template <typename T>
void dynamic_array<T>::print() const
{
    std::cout << "[";
    for (const_array_iterator it = cbegin(); it != cend(); ++it)
    {
        if (it != cbegin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void dynamic_array<T>::clear()
{
    delete[] data;
    data = new T[1]();
    length = 0;
    capacity = 1;
}

template class dynamic_array<int>;
template class dynamic_array<int>::array_iterator;