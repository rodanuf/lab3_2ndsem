#include <stdexcept>
#include "../headers/stack.hpp"

template <typename T>
stack<T>::stack(sequence<T> *s) : container(s) {}

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
int stack<T>::size() const
{
    return container->get_length();
}

template <typename T>
T &stack<T>::top()
{
    return container->get_last();
}

template <typename T>
const T &stack<T>::top() const
{
    return container->get_last();
}

template <typename T>
void stack<T>::push(const T &element)
{
    container = container->append_element(element);
}

template <typename T>
void stack<T>::pop()
{
    container = container->remove_at(size() - 1);
}

template <typename T>
bool stack<T>::is_empty()
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

template <typename T>
template <typename map_func>
stack<T> *stack<T>::map(const map_func &func)
{
    stack<T> *new_stack = new stack<T>();
    for (int i = 0; i < size() + new_stack->size(); i++)
    {
        new_stack->push(func(top()));
        pop();
        std::cout << new_stack->top() << std::endl;
    }
    for (int i = 0; i < new_stack->size() + size(); i++)
    {
        push(new_stack->top());
        new_stack->pop();
    }
    delete new_stack;
    return this;
}

template <typename T>
template <typename predicate>
stack<T> *stack<T>::where(const predicate &pred)
{
    stack<T> *new_stack = new stack<T>();
    stack<T> *result_stack = new stack<T>();
    int stack_size = size();
    for (int i = 0; i < stack_size; i++)
    {
        if (pred(top()))
        {
            new_stack->push(top());
        }
        pop();
    }
    stack_size = new_stack->size();
    for (int i = 0; i < stack_size; i++)
    {
        result_stack->push(new_stack->top());
        new_stack->pop();
    }
    delete new_stack;
    return result_stack;
}

template <typename T>
template <typename R, typename bin_op>
R stack<T>::reduce(const bin_op &op, R init)
{
    stack<T> *new_stack = new stack<T>(*this);
    for (int i = 0; i < size(); ++i)
    {
        init = op(init, new_stack->top());
        new_stack->pop();
    }
    delete new_stack;
    return init;
}

template <typename T>
template <typename map_func>
stack<T> *stack<T>::immutable_map(const map_func &func) const
{
    stack<T> *buffer_stack = new stack<T>(*this);
    stack<T> *new_stack = new stack<T>();
    stack<T> *result_stack = new stack<T>();
    for (int i = 0; i < size(); i++)
    {
        new_stack->push(func(buffer_stack->top()));
        buffer_stack->pop();
    }
    for (int i = 0; i < size(); i++)
    {
        result_stack->push(new_stack->top());
        new_stack->pop();
    }
    delete new_stack;
    delete buffer_stack;
    return result_stack;
}
