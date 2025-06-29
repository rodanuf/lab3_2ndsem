#include <stdexcept>
#include "../headers/list_sequence.hpp"

template <typename T>
list_sequence<T>::ls_iterator::ls_iterator(typename linked_list<T>::list_iterator &it) : it(it) {}

template <typename T>
list_sequence<T>::ls_iterator::ls_iterator(const ls_iterator &other) : it(other.it) {}

template <typename T>
typename list_sequence<T>::ls_iterator &list_sequence<T>::ls_iterator::operator++()
{
    ++it;
    return *this;
}

template <typename T>
typename list_sequence<T>::ls_iterator list_sequence<T>::ls_iterator::operator++(int)
{
    ls_iterator tmp(*this);
    it++;
    return tmp;
}

template <typename T>
typename list_sequence<T>::ls_iterator &list_sequence<T>::ls_iterator::operator--()
{
    --it;
    return *this;
}

template <typename T>
typename list_sequence<T>::ls_iterator list_sequence<T>::ls_iterator::operator--(int)
{
    ls_iterator tmp(*this);
    it--;
    return tmp;
}

template <typename T>
typename list_sequence<T>::ls_iterator &list_sequence<T>::ls_iterator::operator=(const ls_iterator &other)
{
    if (this == &other)
    {
        return *this;
    }
    it = other.it;
    return *this;
}

template <typename T>
typename list_sequence<T>::ls_iterator list_sequence<T>::ls_iterator::operator+(const size_t n)
{
    ls_iterator tmp(*this);
    for (size_t i = 0; i < n; ++i)
    {
        ++tmp;
    }
    return tmp;
}

template <typename T>
typename list_sequence<T>::ls_iterator list_sequence<T>::ls_iterator::operator-(const size_t n)
{
    ls_iterator tmp(*this);
    for (size_t i = 0; i < n; ++i)
    {
        --tmp;
    }
    return tmp;
}

template <typename T>
T &list_sequence<T>::ls_iterator::operator*()
{
    return (*it)->element;
}

template <typename T>
T &list_sequence<T>::ls_iterator::operator[](const size_t index)
{
    return it[index];
}

template <typename T>
bool list_sequence<T>::ls_iterator::operator==(const typename sequence<T>::iterator &other) const
{
    const ls_iterator &derived = dynamic_cast<const ls_iterator &>(other);
    return it == derived.it;
}

template <typename T>
bool list_sequence<T>::ls_iterator::operator!=(const typename sequence<T>::iterator &other) const
{
    const ls_iterator &derived = dynamic_cast<const ls_iterator &>(other);
    return it != derived.it;
}

template <typename T>
void list_sequence<T>::ls_iterator::set(const T &element)
{
    it.set(element);
}

template <typename T>
void list_sequence<T>::ls_iterator::erase()
{
    it.erase();
}

template <typename T>
typename list_sequence<T>::ls_iterator list_sequence<T>::begin()
{
    return ls_iterator(l_sequence.begin());
}

template <typename T>
typename list_sequence<T>::ls_iterator list_sequence<T>::end()
{
    return ls_iterator(l_sequence.end());
}

template <typename T>
list_sequence<T>::const_ls_iterator::const_ls_iterator(typename linked_list<T>::const_list_iterator &it) : it(it) {}

template <typename T>
list_sequence<T>::const_ls_iterator::const_ls_iterator(const const_ls_iterator &other) : it(other.it) {}

template <typename T>
typename list_sequence<T>::const_ls_iterator &list_sequence<T>::const_ls_iterator::operator++()
{
    ++it;
    return *this;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator list_sequence<T>::const_ls_iterator::operator++(int)
{
    const_ls_iterator tmp(*this);
    it++;
    return tmp;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator &list_sequence<T>::const_ls_iterator::operator--()
{
    --it;
    return *this;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator list_sequence<T>::const_ls_iterator::operator--(int)
{
    const_ls_iterator tmp(*this);
    it--;
    return tmp;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator &list_sequence<T>::const_ls_iterator::operator=(const const_ls_iterator &other)
{
    if (this == &other)
    {
        return *this;
    }
    it = other.it;
    return *this;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator list_sequence<T>::const_ls_iterator::operator+(const size_t n)
{
    const_ls_iterator tmp(*this);
    for (int i = 0; i < n; ++i)
    {
        ++tmp;
    }
    return tmp;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator list_sequence<T>::const_ls_iterator::operator-(const size_t n)
{
    const_ls_iterator tmp(*this);
    for (int i = 0; i < n; ++i)
    {
        --tmp;
    }
    return tmp;
}

template <typename T>
const T &list_sequence<T>::const_ls_iterator::operator*()
{
    return (*it)->element;
}

template <typename T>
const T &list_sequence<T>::const_ls_iterator::operator[](const size_t index)
{
    return it[index];
}

template <typename T>
bool list_sequence<T>::const_ls_iterator::operator==(const typename sequence<T>::const_iterator &other) const
{
    const const_ls_iterator &derived = dynamic_cast<const const_ls_iterator &>(other);
    return it == derived.it;
}

template <typename T>
bool list_sequence<T>::const_ls_iterator::operator!=(const typename sequence<T>::const_iterator &other) const
{
    const const_ls_iterator &derived = dynamic_cast<const const_ls_iterator &>(other);
    return it != derived.it;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator list_sequence<T>::cbegin() const
{
    return const_ls_iterator(l_sequence.cbegin());
}

template <typename T>
typename list_sequence<T>::const_ls_iterator list_sequence<T>::cend() const
{
    return const_ls_iterator(l_sequence.cend());
}

template <typename T>
list_sequence<T>::list_sequence() : l_sequence(linked_list<T>()) {}

template <typename T>
list_sequence<T>::list_sequence(const size_t &size) : l_sequence(linked_list<T>(size)) {}

template <typename T>
list_sequence<T>::list_sequence(const T *items, const size_t &size) : l_sequence(linked_list<T>(items, size)) {}

template <typename T>
list_sequence<T>::list_sequence(const std::initializer_list<T> &items) : l_sequence(linked_list<T>(items)) {}

template <typename T>
list_sequence<T>::list_sequence(const sequence<T> &other)
{
    l_sequence = linked_list<T>(other.get_length());
    for (int i = 0; i < other.get_length(); ++i)
    {
        l_sequence.append(other.get(i));
    }
}

template <typename T>
list_sequence<T>::~list_sequence() {}

template <typename T>
T &list_sequence<T>::get(const int index) const
{
    if (index >= static_cast<int>(l_sequence.get_length()) || (-index) >= static_cast<int>(l_sequence.get_length()))
    {
        throw std::out_of_range("Index out of range");
    }
    if (index < 0)
    {
        return l_sequence.get(l_sequence.get_length() + index);
    }
    return l_sequence.get(index);
}

template <typename T>
T &list_sequence<T>::get_first() const
{
    if (l_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return l_sequence.get_first();
}

template <typename T>
T &list_sequence<T>::get_last() const
{
    if (l_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return l_sequence.get_last();
}

template <typename T>
size_t list_sequence<T>::get_length() const
{
    return l_sequence.get_length();
}

template <typename T>
sequence<T> *list_sequence<T>::get_subsequence(const int start_index, const int end_index) const
{
    if (start_index < 0 || end_index >= l_sequence.get_length() || start_index > end_index)
    {
        throw std::out_of_range("Index out of range");
    }
    sequence<T> *subsequence = new list_sequence<T>();
    for (int i = start_index; i <= end_index; ++i)
    {
        subsequence->append_element(l_sequence.get(i));
    }
    return subsequence;
}

template <typename T>
sequence<T> *list_sequence<T>::append_element(const T &element)
{
    l_sequence.append_element(element);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::prepend_element(const T &element)
{
    l_sequence.prepend_element(element);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::insert_element(const T &element, const int index)
{
    if (index >= l_sequence.get_length() || (-index) >= l_sequence.get_length())
    {
        throw std::out_of_range("Index out of range");
    }
    if (index < 0)
    {
        l_sequence.insert_element(element, l_sequence.get_length() + index);
        return this;
    }
    l_sequence.insert_element(element, index);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::concat(const sequence<T> &other)
{
    for (int i = 0; i < other.get_length(); ++i)
    {
        l_sequence.append_element(other.get(i));
    }
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_append_element(const T &element) const
{
    sequence<T> *new_sequence = new list_sequence<T>(*this);
    new_sequence->append_element(element);
    return new_sequence;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_prepend_element(const T &element) const
{
    sequence<T> *new_sequence = new list_sequence<T>(*this);
    new_sequence->prepend_element(element);
    return new_sequence;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_insert_element(const T &element, const int index) const
{
    if (index >= l_sequence.get_length() || (-index) >= l_sequence.get_length())
    {
        throw std::out_of_range("Index out of range");
    }
    sequence<T> *new_sequence = new list_sequence<T>(*this);
    if (index < 0)
    {
        new_sequence->insert_element(element, l_sequence.get_length() + index);
        return new_sequence;
    }
    new_sequence->insert_element(element, index);
    return new_sequence;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_concat(const sequence<T> &other) const
{
    sequence<T> *new_sequence = new list_sequence<T>(*this);
    for (int i = 0; i < other.get_length(); ++i)
    {
        new_sequence->append_element(other.get(i));
    }
    return new_sequence;
}

template <typename T>
void list_sequence<T>::print() const
{
    l_sequence.print();
}

template <typename T>
void list_sequence<T>::clear()
{
    l_sequence.clear();
}