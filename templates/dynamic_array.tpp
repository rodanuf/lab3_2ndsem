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
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator+(const int n) const
{
    return array_iterator(current + n);
}

template <typename T>
typename dynamic_array<T>::array_iterator dynamic_array<T>::array_iterator::operator-(const int n) const
{
    return array_iterator(current - n);
}

template <typename T>
T &dynamic_array<T>::array_iterator::operator*()
{
    return *current;
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
typename dynamic_array<T>::const_array_iterator dynamic_array<T>::const_array_iterator::operator+(const int n) const
{
    return const_array_iterator(current + n);
}

template <typename T>
typename dynamic_array<T>::const_array_iterator dynamic_array<T>::const_array_iterator::operator-(const int n) const
{
    return const_array_iterator(current - n);
}

template <typename T>
const T &dynamic_array<T>::const_array_iterator::operator*() const
{
    return *current;
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
dynamic_array<T>::dynamic_array(const int &size) : data(new T[2 * size]()), length(size), capacity(2 * size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = T();
    }
}

template <typename T>
dynamic_array<T>::dynamic_array(const T *data, const int &size) : data(new T[2 * size]()), length(size), capacity(2 * size)
{
    for (int i = 0; i < size; i++)
    {
        this->data[i] = data[i];
    }
}

template <typename T>
dynamic_array<T>::dynamic_array(const std::initializer_list<T> &list) : data(new T[2 * list.size()]), length(list.size()), capacity(2 * list.size())
{
    for (int i = 0; i < length; i++)
    {
        data[i] = *(list.begin() + i);
    }
}

template <typename T>
dynamic_array<T>::dynamic_array(const dynamic_array<T> &other) : data(new T[other.capacity]), length(other.length), capacity(other.capacity)
{
    for (int i = 0; i < length; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
dynamic_array<T>::dynamic_array(dynamic_array<T> &&other) : data(other.data), length(other.length), capacity(other.capacity)
{
    other.data = nullptr;
    other.length = 0;
    other.capacity = 0;
}

template <typename T>
dynamic_array<T>::~dynamic_array()
{
    delete[] data;
}

template <typename T>
typename dynamic_array<T>::dynamic_array &dynamic_array<T>::operator=(const dynamic_array &other)
{
    if (this != &other)
    {
        delete[] data;
        capacity = other.capacity;
        length = other.length;
        data = new T[capacity];
        for (int i = 0; i < length; ++i)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T &dynamic_array<T>::operator[](const int index)
{
    return data[index];
}

template <typename T>
const T &dynamic_array<T>::operator[](const int index) const
{
    return data[index];
}

template <typename T>
T &dynamic_array<T>::get(const int index)
{
    return data[index];
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
const T &dynamic_array<T>::get(const int index) const
{
    return data[index];
}

template <typename T>
const T &dynamic_array<T>::get_first() const
{
    return data[0];
}

template <typename T>
const T &dynamic_array<T>::get_last() const
{
    return data[length - 1];
}

template <typename T>
int dynamic_array<T>::get_length() const
{
    return length;
}

template <typename T>
void dynamic_array<T>::resize(const int &new_size)
{
    int old_length = length;
    length = new_size;
    if (new_size < capacity && new_size > old_length)
    {
        return;
    }
    capacity = 2 * new_size;
    T *new_data = new T[capacity];
    for (int i = 0; i < old_length; i++)
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
    length++;
    *(end() - 1) = element;
}

template <typename T>
void dynamic_array<T>::prepend_element(const T &element)
{
    if (length == capacity)
    {
        resize(capacity);
    }
    length++;
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
    for (int i = length; i > index; i--)
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
void dynamic_array<T>::remove_at(const int index)
{
    for (int i = index; i < get_length() - 1; i++)
    {
        data[i] = data[i + 1];
    }
    length--;
}

template <typename T>
void dynamic_array<T>::clear()
{
    delete[] data;
    data = new T[1]();
    length = 0;
    capacity = 1;
}
