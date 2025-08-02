#include "../monad_header/monad_adapter.hpp"

template <monad_container container>
monad_adapter<container>::monad_adapter() {}

template <monad_container container>
monad_adapter<container>::monad_adapter(const container &other) : cont(other) {}

template <monad_container container>
monad_adapter<container>::monad_adapter(container &&other) : cont(std::move(other)) {}

template <monad_container container>
monad_adapter<container>::monad_adapter(const monad_adapter &other) : cont(other.cont) {}

template <monad_container container>
monad_adapter<container>::monad_adapter(monad_adapter &&other) : cont(std::move(other.cont)) {}

template <monad_container container>
monad_adapter<container>::~monad_adapter() {}

template <monad_container container>
monad_adapter<container> &monad_adapter<container>::operator=(const container &other)
{
    cont = other;
    return *this;
}

template <monad_container container>
monad_adapter<container> &monad_adapter<container>::operator=(container &&other)
{
    cont = std::forward(other);
    return *this;
}

template <monad_container container>
monad_adapter<container> &monad_adapter<container>::operator=(const monad_adapter &other)
{
    cont = other.cont;
    return *this;
}

template <monad_container container>
monad_adapter<container> &monad_adapter<container>::operator=(monad_adapter &&other)
{
    cont = std::forward(other.cont);
    return *this;
}

template <monad_container container>
container *monad_adapter<container>::operator->()
{
    return &cont;
}

template <monad_container container>
const container *monad_adapter<container>::operator->() const
{
    return &cont;
}

template <monad_container container>
container &monad_adapter<container>::operator*()
{
    return cont;
}

template <monad_container container>
const container &monad_adapter<container>::operator*() const
{
    return cont;
}

template <monad_container container>
template <typename F>
    requires map_function<F, typename container::value_type>
void monad_adapter<container>::map(F &&func)
{
    container buffer_cont = cont;
    cont.clear();
    for (auto it = buffer_cont.begin(); it != buffer_cont.end(); ++it)
    {
        cont += func(*it);
    }
}

template <monad_container container>
template <typename F>
    requires where_function<F, typename container::value_type>
void monad_adapter<container>::filter(F &&func)
{
    container buffer_cont = cont;
    cont.clear();
    for (auto it = buffer_cont.begin(); it != buffer_cont.end(); ++it)
    {
        if (func(*it))
        {
            cont += *it;
        }
    }
}

template <monad_container container>
template <typename F>
    requires where_function<F, typename container::value_type>
auto monad_adapter<container>::where(F &&func)
{
    container result;
    for (auto it = cont.begin(); it != cont.end(); ++it)
    {
        result += func(*it);
    }
    return monad_adapter<container>(result);
}

template <monad_container container>
template <typename R, typename F>
    requires reduce_function<F, R, typename container::value_type>
R monad_adapter<container>::reduce(F &&func, R initial)
{
    R result = initial;
    for (auto it = cont.begin(); it != cont.end(); ++it)
    {
        result = func(result, *it);
    }
    return result;
}

template <monad_container container>
template <typename F>
    requires map_function<F, typename container::value_type>
auto monad_adapter<container>::immutable_map(F &&func) const
{
    container result;
    for (auto it = cont.begin(); it != cont.end(); ++it)
    {
        result += *it;
    }
    return monad_adapter<container>(result);
}