#include <stdexcept>
#include "../headers/array_sequence.hpp"

template <typename T>
array_sequence<T>::as_iterator::as_iterator(typename dynamic_array<T>::array_iterator it) : it(it) {}

template <typename T>
array_sequence<T>::as_iterator::as_iterator(const as_iterator &other) : it(other.it) {}

template <typename T>
typename array_sequence<T>::as_iterator &array_sequence<T>::as_iterator::operator++()
{
    ++it;
    return *this;
}

template <typename T>
typename array_sequence<T>::as_iterator *array_sequence<T>::as_iterator::operator++(int)
{
    as_iterator *tmp = new as_iterator(*this);
    ++it;
    return tmp;
}

template <typename T>
typename array_sequence<T>::as_iterator &array_sequence<T>::as_iterator::operator--()
{
    --it;
    return *this;
}

template <typename T>
typename array_sequence<T>::as_iterator *array_sequence<T>::as_iterator::operator--(int)
{
    as_iterator *tmp = new as_iterator(*this);
    --it;
    return tmp;
}

template <typename T>
typename array_sequence<T>::as_iterator &array_sequence<T>::as_iterator::operator=(const typename sequence<T>::iterator_impl &other)
{
    const as_iterator &derived = dynamic_cast<const as_iterator &>(other);
    if (this == &derived)
    {
        return *this;
    }
    it = derived.it;
    return *this;
}

template <typename T>
typename array_sequence<T>::as_iterator *array_sequence<T>::as_iterator::operator+(const int n) const
{
    return new as_iterator(it + n);
}

template <typename T>
typename array_sequence<T>::as_iterator *array_sequence<T>::as_iterator::operator-(const int n) const
{
    return new as_iterator(it - n);
}

template <typename T>
typename array_sequence<T>::as_iterator *array_sequence<T>::as_iterator::clone() const
{
    return new as_iterator(it);
}

template <typename T>
T &array_sequence<T>::as_iterator::operator*()
{
    return *it;
}

template <typename T>
const T &array_sequence<T>::as_iterator::operator*() const
{
    return const_cast<as_iterator *>(this)->operator*();
}

template <typename T>
bool array_sequence<T>::as_iterator::operator==(const typename sequence<T>::iterator_impl &other) const // сделать тест на сравнение итераторов array_sequence и list_sequence
{
    const as_iterator *derived = dynamic_cast<const as_iterator *>(&other);
    if (derived == nullptr)
    {
        return false;
    }
    return it == derived->it;
}

template <typename T>
bool array_sequence<T>::as_iterator::operator!=(const typename sequence<T>::iterator_impl &other) const
{
    const as_iterator *derived = dynamic_cast<const as_iterator *>(&other);
    if (derived == nullptr)
    {
        return false;
    }
    return it != derived->it;
}

template <typename T>
void array_sequence<T>::as_iterator::set(const T &value)
{
    it.set(value);
}

template <typename T>
void array_sequence<T>::as_iterator::erase()
{
    it.erase();
}

template <typename T>
typename array_sequence<T>::as_iterator *array_sequence<T>::begin_impl()
{
    return new as_iterator(a_sequence.begin());
}

template <typename T>
typename array_sequence<T>::as_iterator *array_sequence<T>::end_impl()
{
    return new as_iterator(a_sequence.end());
}

template <typename T>
array_sequence<T>::const_as_iterator::const_as_iterator(typename dynamic_array<T>::const_array_iterator it) : it(it) {}

template <typename T>
array_sequence<T>::const_as_iterator::const_as_iterator(const const_as_iterator &other) : it(other.it) {}

template <typename T>
typename array_sequence<T>::const_as_iterator &array_sequence<T>::const_as_iterator::operator++()
{
    ++it;
    return *this;
}

template <typename T>
typename array_sequence<T>::const_as_iterator *array_sequence<T>::const_as_iterator::operator++(int)
{
    const_as_iterator *tmp = new const_as_iterator(*this);
    ++it;
    return tmp;
}

template <typename T>
typename array_sequence<T>::const_as_iterator &array_sequence<T>::const_as_iterator::operator--()
{
    --it;
    return *this;
}

template <typename T>
typename array_sequence<T>::const_as_iterator *array_sequence<T>::const_as_iterator::operator--(int)
{
    const_as_iterator *tmp = new const_as_iterator(*this);
    --it;
    return tmp;
}

template <typename T>
typename array_sequence<T>::const_as_iterator &array_sequence<T>::const_as_iterator::operator=(const typename sequence<T>::iterator_impl &other)
{
    const const_as_iterator &derived = dynamic_cast<const const_as_iterator &>(other);
    if (this == &derived)
    {
        return *this;
    }
    it = derived.it;
    return *this;
}

template <typename T>
typename array_sequence<T>::const_as_iterator *array_sequence<T>::const_as_iterator::operator+(const int n) const
{
    return new const_as_iterator(it + n);
}

template <typename T>
typename array_sequence<T>::const_as_iterator *array_sequence<T>::const_as_iterator::operator-(const int n) const
{
    return new const_as_iterator(it - n);
}

template <typename T>
typename array_sequence<T>::const_as_iterator *array_sequence<T>::const_as_iterator::clone() const
{
    return new const_as_iterator(it);
}

template <typename T>
T &array_sequence<T>::const_as_iterator::operator*()
{
    throw std::runtime_error("Cannot modify const iterator");
}

template <typename T>
const T &array_sequence<T>::const_as_iterator::operator*() const
{
    return *it;
}

template <typename T>
bool array_sequence<T>::const_as_iterator::operator==(const typename sequence<T>::iterator_impl &other) const
{
    const const_as_iterator &derived = dynamic_cast<const const_as_iterator &>(other);
    return it == derived.it;
}

template <typename T>
bool array_sequence<T>::const_as_iterator::operator!=(const typename sequence<T>::iterator_impl &other) const
{
    const const_as_iterator &derived = dynamic_cast<const const_as_iterator &>(other);
    return it != derived.it;
}

template <typename T>
typename array_sequence<T>::const_as_iterator *array_sequence<T>::cbegin_impl() const
{
    return new const_as_iterator(a_sequence.cbegin());
}

template <typename T>
typename array_sequence<T>::const_as_iterator *array_sequence<T>::cend_impl() const
{
    return new const_as_iterator(a_sequence.cend());
}

template <typename T>
array_sequence<T>::array_sequence() : a_sequence() {}

template <typename T>
array_sequence<T>::array_sequence(const int &size) : a_sequence(size) {}

template <typename T>
array_sequence<T>::array_sequence(const T *items, const int &size) : a_sequence(items, size) {}

template <typename T>
array_sequence<T>::array_sequence(const std::initializer_list<T> &items) : a_sequence(items) {}

template <typename T>
array_sequence<T>::array_sequence(const array_sequence<T> &other) : a_sequence(other.a_sequence) {}

template <typename T>
array_sequence<T>::array_sequence(const sequence<T> &other)
{
    a_sequence = new dynamic_array<T>();
    for (int i = 0; i < other.get_length(); i++)
    {
        a_sequence.append_element(other.get(i));
    }
}

template <typename T>
array_sequence<T>::~array_sequence() {}

template <typename T>
array_sequence<T> &array_sequence<T>::operator=(const array_sequence<T> &other)
{
    if (this != &other)
    {
        a_sequence = other.a_sequence;
    }
    return *this;
}

template <typename T>
array_sequence<T> array_sequence<T>::operator+(const T &value)
{
    array_sequence<T> new_a_sequence(*this);
    new_a_sequence = new_a_sequence.append_element(value);
    return new_a_sequence;
}

template <typename T>
T &array_sequence<T>::operator[](const int index)
{
    if (index > a_sequence.get_length() || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    return a_sequence[index];
}

template <typename T>
const T &array_sequence<T>::operator[](const int index) const
{
    if (index > a_sequence.get_length() || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    return a_sequence[index];
}

template <typename T>
T &array_sequence<T>::get(const int index)
{
    if (index >= a_sequence.get_length() || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    return a_sequence.get(index);
}

template <typename T>
T &array_sequence<T>::get_first()
{
    if (a_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return a_sequence.get_first();
}

template <typename T>
T &array_sequence<T>::get_last()
{
    if (a_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return a_sequence.get_last();
}

template <typename T>
const T &array_sequence<T>::get(const int index) const
{
    if (index >= a_sequence.get_length() || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    return a_sequence.get(index);
}

template <typename T>
const T &array_sequence<T>::get_first() const
{
    if (a_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return a_sequence.get_first();
}

template <typename T>
const T &array_sequence<T>::get_last() const
{
    if (a_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return a_sequence.get_last();
}

template <typename T>
int array_sequence<T>::get_length() const
{
    return a_sequence.get_length();
}

template <typename T>
sequence<T> &array_sequence<T>::operator+=(const T &element)
{
    a_sequence.append_element(element);
    return *this;
}

template <typename T>
sequence<T> *array_sequence<T>::get_subsequence(int start_index, int end_index) const
{
    if (start_index < 0 || end_index >= a_sequence.get_length())
    {
        throw std::out_of_range("Index out of range");
    }
    if (start_index > end_index)
    {
        throw std::invalid_argument("start_index cannot be greater than end_index");
    }
    array_sequence<T> *result = new array_sequence<T>();
    auto begin_it = sequence<T>::cbegin();
    for (auto it = begin_it + start_index; it != begin_it + end_index + 1; it++)
    {
        result->append_element(*it);
    }
    return result;
}

template <typename T>
sequence<T> *array_sequence<T>::append_element(const T &element)
{
    a_sequence.append_element(element);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::prepend_element(const T &element)
{
    a_sequence.prepend_element(element);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::insert_element(const T &element, const int index)
{
    a_sequence.insert_element(element, index);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::remove_at(const int index)
{
    if (index > get_length() || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    a_sequence.remove_at(index);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::concat(const sequence<T> &container)
{
    for (int i = 0; i < container.get_length(); i++)
    {
        a_sequence.append_element(container.get(i));
    }
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::clone() const
{
    return new array_sequence<T>(*this);
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_append_element(const T &element) const
{
    array_sequence<T> *result = new array_sequence<T>(*this);
    result->append_element(element);
    return result;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_prepend_element(const T &element) const
{
    array_sequence<T> *result = new array_sequence<T>(*this);
    result->prepend_element(element);
    return result;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_insert_element(const T &element, int index) const
{
    array_sequence<T> *result = new array_sequence<T>(*this);
    result->insert_element(element, index);
    return result;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_remove_at(const int index) const
{
    if (index > get_length() || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    sequence<T> *result = new array_sequence(*this);
    result->remove_at(index);
    return result;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_concat(const sequence<T> &container) const
{
    array_sequence<T> *result = new array_sequence<T>(*this);
    result->concat(container);
    return result;
}

template <typename T>
void array_sequence<T>::clear()
{
    a_sequence.clear();
}