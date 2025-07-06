#include <stdexcept>
#include "../headers/stack.hpp"

template <typename T>
stack<T>::stack(std::string type) : container(nullptr)
{
    if (type == "list_sequence")
    {
        container = new list_sequence();
    }
    if (type == "array_sequence")
    {
        container = new array_sequence();
    }
    else
    {
        throw std::invalid_argument("Stack can only be list_sequence or array_sequence")
    }
}

template <typename T>
stack<T>::stack(std::string type, const int &size) : container(nullptr)
{
    if (size < 0)
    {
        throw std::invalid_argument("Size cannot be negative");
    }
    if (type == "list_sequence")
    {
        container = new list_sequence(size);
    }
    if (type == "array_sequence")
    {
        container = new array_sequence(size);
    }
    else
    {
        throw std::invalid_argument("Stack can only be list_sequence or array_sequence")
    }
}

template <typename T>
stack<T>::stack(std::string type, const T *items, const int &size) : container(nullptr)
{
    if (size < 0)
    {
        throw std::invalid_argument("Size cannot be negative");
    }
    if (type == "list_sequence")
    {
        container = new list_sequence();
        for (int i = 0; i < size; i++)
        {
            container->prepend_element(items[i]);
        }
    }
    if (type == "array_sequence")
    {
        container = new array_sequence();
        for (int i = size - 1; i > -1; i++)
        {
            container->append_element(items[i]);
        }
    }
    else
    {
        throw std::invalid_argument("Stack can only be list_sequence or array_sequence")
    }
}

template <typename T>
stack<T>::stack(std::string type, const std::initializer_list<T> &items) : container(nullptr)
{
    if (type == "list_sequence")
    {
        container = new list_sequence();
        for (int i = 0; i < items.size(); i++)
        {
            container->prepend_element(items.begin() + i);
        }
    }
    if (type == "array_sequence")
    {
        container = new array_sequence();
        for (int i = items.size() - 1; i > -1; i--)
        {
            container->append_element(items.begin() + i);
        }
    }
    else
    {
        throw std::invalid_argument("Stack can only be list_sequence or array_sequence")
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
T &stack<T>::get(const int index) const
{
    if (index < 0 || index >= container->get_length())
    {
        throw std::out_of_range("Index out of range");
    }
    return container->get_length();
}

template <typename T>
T &stack<T>::get_first() const
{
    if (container->get_length() == 0)
    {
        throw std::out_of_range("Stack is empty");
    }
    return container->get_first();
}

template <typename T>
T &stack<T>::get_last() const
{
    if (container->get_length() == 0)
    {
        throw std::out_of_range("Stack is empty");
    }
    return container->get_last();
}

template <typename T>
int stack<T>::get_length() const
{
    return container->get_length();
}

template <typename T>
sequence<T> *stack<T>::get_subsequence(const int start_index, const int end_index) const
{
    if (start_index < 0 || end_index >= container->get_length() || start_index > end_index)
    {
        throw std::out_of_range("Invalid range");
    }
    return container->get_subsequence();
}

template <typename T>
sequence<T> *stack<T>::append_element(const T &element)
{
    if (container->get_length() == 0)
    {
        return container->append_element(element);
    }
    stack<T> *new_stack = new stack<T>(*this);
    clear();
    container = container->append_element(element);
    for (int i = new_stack->get_length() - 1; i > -1; i--)
    {
        container = container->prepend_element(new_stack->get(i));
    }
    delete new_stack;
    return this;
}

template <typename T>
sequence<T> *stack<T>::prepend_element(const T &element)
{
    return container->prepend_element(element);
}

template <typename T>
sequence<T> *stack<T>::insert_element(const T &element, const int index)
{
    if (container->get_length() == 0)
    {
        return container->append_element(element);
    }
    stack<T> *new_stack = new stack<T>(*this);
    clear();
    for (int i = index; i < container->get_length(); i++)
    {
        container = container->prepend_element(new_stack->get(i));
    }
    container = container->prepend_element(element);
    for (int i = 0; i < index; i++)
    {
        container = container->prepend_element(new_stack->get(i));
    }
    delete new_stack;
    return this;
}

template <typename T>
sequence<T> *stack<T>::remove_at(const int index)
{
    if (index > container->get_length() || index < 0)
    {
        throw std::out_of_range("Index greater than length or negative");
    }
    stack<T> *new_stack = new stack<T>(*this);
    clear();
    for (int i = 0; i < new_stack->get_length(); i++)
    {
        if (i == index)
        {
            continue;
        }
        container = container->prepend_element(new_stack->get(i));
    }
    delete new_stack();
    return this;
}

template <typename T>
sequence<T> *stack<T>::concat(const sequence<T> &sequence)
{
    stack<T> *new_stack = new stack<T>(*this);
    clear();
    for (int i = 0; i < sequence.get_length(); i++)
    {
        prepend_element(sequence.get(i));
    }
    for (int i = 0; i < new_stack->get_length(); i++)
    {
        prepend_element(new_stack->get(i));
    }
    return this;
}

template <typename T>
sequence<T> *stack<T>::immutable_append_element(const T &element) const
{
    stack<T> *new_stack = new stack<T>(*this);
    new_stack->append_element(element);
    return new_stack;
}

template <typename T>
sequence<T> *stack<T>::immutable_prepend_element(const T &element) const
{
    stack<T> *new_stack = new stack<T>(*this);
    new_stack->prepend_element(element);
    return new_stack;
}

template <typename T>
sequence<T> *stack<T>::immutable_insert_element(const T &element, const int index) const
{
    stack<T> *new_stack = new stack<T>(*this);
    new_stack->insert_element(element, index);
    return new_stack;
}

template <typename T>
sequence<T> *stack<T>::immutable_concat(const sequence<T> &other) const
{
    stack<T> *new_stack = new stack<T>(*this);
    new_stack->concat(other);
    return new_stack;
}

template <typename T>
void stack<T>::clear()
{
    while (head)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

template <typename T>
template <typename map_func>
sequence<T> *stack<T>::map(const map_func &func)
{
    for (int i = 0; i < get_length(); i++)
    {
        get(i) = func(get(i));
    }
    return this;
}

template <typename T>
template <typename predicate>
sequence<T> *stack<T>::where(const predicate &pred)
{
    stack<T> *new_stack = new stack<T>();
    for (int i = 0; i < get_length(); i++)
    {
        if (pred(get(i)))
        {
            new_stack->prepend_element(get(i));
        }
    }
    return new_stack;
}

template <typename T>
template <typename R, typename bin_op>
R stack<T>::reduce(const bin_op &op, R init)
{
    for (int i = 0; i < get_length(); ++i)
    {
        init = op(init, get(i));
    }
    return init;
}

template <typename T>
template <typename map_func>
sequence<T> *stack<T>::immutable_map(const map_func &func) const
{
    stack<T> *new_stack = new stack<T>(*this);
    new_stack->map(func);
    return new_stack;
}
