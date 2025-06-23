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
typename array_sequence<T>::as_iterator array_sequence<T>::as_iterator::operator++(int)
{
    as_iterator tmp(*this);
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
typename array_sequence<T>::as_iterator array_sequence<T>::as_iterator::operator--(int)
{
    as_iterator tmp(*this);
    --it;
    return tmp;
}

template <typename T>
typename array_sequence<T>::as_iterator &array_sequence<T>::as_iterator::operator=(const as_iterator &other)
{
    const as_iterator &derived = dynamic_cast<const as_iterator &>(other);
    it = derived.it;
    return *this;
}

template <typename T>
typename array_sequence<T>::as_iterator array_sequence<T>::as_iterator::operator+(const size_t n)
{
    it = it + n;
    return *this;
}

template <typename T>
typename array_sequence<T>::as_iterator array_sequence<T>::as_iterator::operator-(const size_t n)
{
    it = it - n;
    return *this;
}

template <typename T>
T &array_sequence<T>::as_iterator::operator*()
{
    return *it;
}

template <typename T>
T &array_sequence<T>::as_iterator::operator[](const size_t n)
{
    return it[n];
}

template <typename T>
bool array_sequence<T>::as_iterator::operator==(const typename sequence<T>::iterator &other) const
{
    const as_iterator &derived = dynamic_cast<const as_iterator &>(other);
    return it == derived.it;
}

template <typename T>
bool array_sequence<T>::as_iterator::operator!=(const typename sequence<T>::iterator &other) const
{
    const as_iterator &derived = dynamic_cast<const as_iterator &>(other);
    return it != derived.it;
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
typename array_sequence<T>::as_iterator array_sequence<T>::begin()
{
    return as_iterator(a_sequence->begin());
}

template <typename T>
typename array_sequence<T>::as_iterator array_sequence<T>::end()
{
    return as_iterator(a_sequence->end());
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
typename array_sequence<T>::const_as_iterator array_sequence<T>::const_as_iterator::operator++(int)
{
    const_as_iterator tmp(*this);
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
typename array_sequence<T>::const_as_iterator array_sequence<T>::const_as_iterator::operator--(int)
{
    const_as_iterator tmp(*this);
    --it;
    return tmp;
}

template <typename T>
typename array_sequence<T>::const_as_iterator &array_sequence<T>::const_as_iterator::operator=(const typename array_sequence<T>::const_as_iterator &other)
{
    if (it != &other)
    {
        it = other.it;
    }
    return *this;
}

template <typename T>
typename array_sequence<T>::const_as_iterator array_sequence<T>::const_as_iterator::operator+(const size_t n) const
{
    auto temp = *this;
    temp.it = temp.it + n;
    return temp;
}

template <typename T>
typename array_sequence<T>::const_as_iterator array_sequence<T>::const_as_iterator::operator-(const size_t n) const
{
    auto temp = *this;
    temp.it = temp.it - n;
    return temp;
}

template <typename T>
const T &array_sequence<T>::const_as_iterator::operator*()
{
    return *it;
}

template <typename T>
const T &array_sequence<T>::const_as_iterator::operator[](const size_t n)
{
    return *(it + n);
}

template <typename T>
bool array_sequence<T>::const_as_iterator::operator==(const typename sequence<T>::const_iterator &other) const
{
    const const_as_iterator &derived = dynamic_cast<const const_as_iterator &>(other);
    return it == derived.it;
}

template <typename T>
bool array_sequence<T>::const_as_iterator::operator!=(const typename sequence<T>::const_iterator &other) const
{
    const const_as_iterator &derived = dynamic_cast<const const_as_iterator &>(other);
    return it != derived.it;
}

template <typename T>
typename array_sequence<T>::const_as_iterator array_sequence<T>::cbegin() const
{
    return const_as_iterator(a_sequence->cbegin());
}

template <typename T>
typename array_sequence<T>::const_as_iterator array_sequence<T>::cend() const
{
    return const_as_iterator(a_sequence->cend());
}

template <typename T>
array_sequence<T>::array_sequence() : a_sequence(new dynamic_array<T>()) {}

template <typename T>
array_sequence<T>::array_sequence(const size_t &size) : a_sequence(new dynamic_array<T>(size)) {}

template <typename T>
array_sequence<T>::array_sequence(T *items, const size_t &size) : a_sequence(new dynamic_array<T>(items, size)) {}

template <typename T>
array_sequence<T>::array_sequence(std::initializer_list<T> items) : a_sequence(new dynamic_array<T>(items)) {}

template <typename T>
array_sequence<T>::array_sequence(const sequence<T> &other)
{
    a_sequence = new dynamic_array<T>();
    for (size_t i = 0; i < other.get_length(); i++)
    {
        a_sequence->append_element(other.get(i));
    }
}

template <typename T>
array_sequence<T>::~array_sequence() {}

template <typename T>
T &array_sequence<T>::get(int index) const
{
    if (index >= a_sequence->get_length())
    {
        throw std::out_of_range("Index out of range");
    }
    return a_sequence->get(index);
}

template <typename T>
T &array_sequence<T>::get_first() const
{
    if (a_sequence->get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return a_sequence->get_first();
}

template <typename T>
T &array_sequence<T>::get_last() const
{
    if (a_sequence->get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return a_sequence->get_last();
}

template <typename T>
size_t array_sequence<T>::get_length() const
{
    return a_sequence->get_length();
}

template <typename T>
sequence<T> *array_sequence<T>::get_subsequence(int start_index, int end_index) const
{
    if (start_index < 0 || end_index >= a_sequence->get_length())
    {
        throw std::out_of_range("Index out of range");
    }
    array_sequence<T> *result = new array_sequence<T>();
    auto begin_it = cbegin();
    for (auto it = begin_it + start_index; it != begin_it + end_index + 1; ++it)
    {
        result->append_element(*it);
    }
    return result;
}

template <typename T>
sequence<T> *array_sequence<T>::append_element(const T &element)
{
    a_sequence->append_element(element);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::prepend_element(const T &element)
{
    a_sequence->prepend_element(element);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::insert_element(const T &element, int index)
{
    a_sequence->insert_element(element, index);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::concat(const sequence<T> &container)
{
    for (size_t i = 0; i < container.get_length(); i++)
    {
        a_sequence->append_element(container.get(i));
    }
    return this;
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
sequence<T> *array_sequence<T>::immutable_concat(const sequence<T> &container) const
{
    array_sequence<T> *result = new array_sequence<T>(*this);
    result->concat(container);
    return result;
}

template <typename T>
void array_sequence<T>::print() const
{
    a_sequence->print();
}

template <typename T>
void array_sequence<T>::clear()
{
    a_sequence->clear();
}