#include "../headers/linked_list.hpp"

template <typename T>
linked_list<T>::node::node(const T &item) : element(item), next(nullptr), prev(nullptr) {}

template <typename T>
linked_list<T>::node::~node()
{
    next->prev = prev;
    prev->next = next;
}

template <typename T>
linked_list<T>::list_iterator::list_iterator(node *ptr) : current(ptr) {}
