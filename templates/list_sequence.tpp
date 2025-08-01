#include <stdexcept>
#include "../headers/list_sequence.hpp"

template <typename T>
list_sequence<T>::ls_iterator::ls_iterator(const typename linked_list<T>::list_iterator &it) : it(it) {}

template <typename T>
list_sequence<T>::ls_iterator::ls_iterator(const ls_iterator &other) : it(other.it) {}

template <typename T>
typename list_sequence<T>::ls_iterator &list_sequence<T>::ls_iterator::operator++()
{
    ++it;
    return *this;
}

template <typename T>
typename list_sequence<T>::ls_iterator *list_sequence<T>::ls_iterator::operator++(int)
{
    ls_iterator *tmp = new ls_iterator(*this);
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
typename list_sequence<T>::ls_iterator *list_sequence<T>::ls_iterator::operator--(int)
{
    ls_iterator *tmp = new ls_iterator(*this);
    it--;
    return tmp;
}

template <typename T>
typename list_sequence<T>::ls_iterator &list_sequence<T>::ls_iterator::operator=(const typename sequence<T>::iterator_impl &other)
{
    const ls_iterator &derived = dynamic_cast<const ls_iterator &>(other);
    if (this == &derived)
    {
        return *this;
    }
    it = derived.it;
    return *this;
}

template <typename T>
typename list_sequence<T>::ls_iterator *list_sequence<T>::ls_iterator::operator+(const int n) const
{
    return new ls_iterator(it + n);
}

template <typename T>
typename list_sequence<T>::ls_iterator *list_sequence<T>::ls_iterator::operator-(const int n) const
{
    return new ls_iterator(it - n);
}

template <typename T>
typename list_sequence<T>::ls_iterator *list_sequence<T>::ls_iterator::clone() const
{
    return new ls_iterator(*this);
}

template <typename T>
T &list_sequence<T>::ls_iterator::operator*()
{
    return (*it)->element;
}

template <typename T>
const T &list_sequence<T>::ls_iterator::operator*() const
{
    return const_cast<ls_iterator *>(this)->operator*();
}

template <typename T>
bool list_sequence<T>::ls_iterator::operator==(const typename sequence<T>::iterator_impl &other) const
{
    const ls_iterator &derived = dynamic_cast<const ls_iterator &>(other);
    return *it == *derived.it;
}

template <typename T>
bool list_sequence<T>::ls_iterator::operator!=(const typename sequence<T>::iterator_impl &other) const
{
    const ls_iterator &derived = dynamic_cast<const ls_iterator &>(other);
    return *it != *derived.it;
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
typename list_sequence<T>::ls_iterator *list_sequence<T>::begin_impl()
{
    return new ls_iterator(l_sequence.begin());
}

template <typename T>
typename list_sequence<T>::ls_iterator *list_sequence<T>::end_impl()
{
    return new ls_iterator(l_sequence.end());
}

template <typename T>
list_sequence<T>::const_ls_iterator::const_ls_iterator(const typename linked_list<T>::const_list_iterator &it) : it(it) {}

template <typename T>
list_sequence<T>::const_ls_iterator::const_ls_iterator(const const_ls_iterator &other) : it(other.it) {}

template <typename T>
typename list_sequence<T>::const_ls_iterator &list_sequence<T>::const_ls_iterator::operator++()
{
    ++it;
    return *this;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator *list_sequence<T>::const_ls_iterator::operator++(int)
{
    auto tmp = this->clone();
    ++(*this);
    return tmp;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator &list_sequence<T>::const_ls_iterator::operator--()
{
    --it;
    return *this;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator *list_sequence<T>::const_ls_iterator::operator--(int)
{
    auto tmp = this->clone();
    --(*this);
    return tmp;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator &list_sequence<T>::const_ls_iterator::operator=(const typename sequence<T>::iterator_impl &other)
{
    const const_ls_iterator &derived = dynamic_cast<const const_ls_iterator &>(other);
    if (this == &derived)
    {
        return *this;
    }
    it = derived.it;
    return *this;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator *list_sequence<T>::const_ls_iterator::operator+(const int n) const
{
    return new const_ls_iterator(it + n);
}

template <typename T>
typename list_sequence<T>::const_ls_iterator *list_sequence<T>::const_ls_iterator::operator-(const int n) const
{
    return new const_ls_iterator(it - n);
}

template <typename T>
typename list_sequence<T>::const_ls_iterator *list_sequence<T>::const_ls_iterator::clone() const
{
    return new const_ls_iterator(it);
}

template <typename T>
T &list_sequence<T>::const_ls_iterator::operator*()
{
    throw std::runtime_error("Cannot modify const iterator");
}

template <typename T>
const T &list_sequence<T>::const_ls_iterator::operator*() const
{
    return (*it)->element;
}

template <typename T>
bool list_sequence<T>::const_ls_iterator::operator==(const typename sequence<T>::iterator_impl &other) const
{
    const const_ls_iterator &derived = dynamic_cast<const const_ls_iterator &>(other);
    return *it == *derived.it;
}

template <typename T>
bool list_sequence<T>::const_ls_iterator::operator!=(const typename sequence<T>::iterator_impl &other) const
{
    const const_ls_iterator &derived = dynamic_cast<const const_ls_iterator &>(other);
    return *it != *derived.it;
}

template <typename T>
typename list_sequence<T>::const_ls_iterator *list_sequence<T>::cbegin_impl() const
{
    return new const_ls_iterator(l_sequence.cbegin());
}

template <typename T>
typename list_sequence<T>::const_ls_iterator *list_sequence<T>::cend_impl() const
{
    return new const_ls_iterator(l_sequence.cend());
}

template <typename T>
list_sequence<T>::list_sequence() : l_sequence() {}

template <typename T>
list_sequence<T>::list_sequence(const int &size) : l_sequence(size) {}

template <typename T>
list_sequence<T>::list_sequence(const T *items, const int &size) : l_sequence(items, size) {}

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
T &list_sequence<T>::get(const int index)
{
    if (index >= l_sequence.get_length() || (-index) >= l_sequence.get_length())
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
T &list_sequence<T>::get_first()
{
    if (l_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return l_sequence.get_first();
}

template <typename T>
T &list_sequence<T>::get_last()
{
    if (l_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return l_sequence.get_last();
}

template <typename T>
const T &list_sequence<T>::get(const int index) const
{
    if (index >= l_sequence.get_length() || (-index) >= l_sequence.get_length())
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
const T &list_sequence<T>::get_first() const
{
    if (l_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return l_sequence.get_first();
}

template <typename T>
const T &list_sequence<T>::get_last() const
{
    if (l_sequence.get_length() == 0)
    {
        throw std::out_of_range("Sequence is empty");
    }
    return l_sequence.get_last();
}

template <typename T>
int list_sequence<T>::get_length() const
{
    return l_sequence.get_length();
}

template <typename T>
sequence<T> &list_sequence<T>::operator+(const T &value)
{
    l_sequence.append_elemnt(value);
    return *this;
}

template <typename T>
sequence<T> &list_sequence<T>::operator+=(const T &value)
{
    l_sequence.append_elemnt(value);
    return *this;
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
sequence<T> *list_sequence<T>::remove_at(const int index)
{
    if (index > get_length() || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    l_sequence.remove_at(index);
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
sequence<T> *list_sequence<T>::clone() const
{
    return new list_sequence(*this);
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
sequence<T> *list_sequence<T>::immutable_remove_at(const int index) const
{
    if (index > get_length() || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    sequence<T> *new_sequence = new list_sequence(*this);
    new_sequence->remove_at(index);
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
void list_sequence<T>::clear()
{
    l_sequence.clear();
}