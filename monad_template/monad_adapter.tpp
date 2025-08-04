#include "../monad_header/monad_adapter.hpp"

template <typename F>
auto transform(F &&func)
{
    return transform_st {func};
}

template <typename F>
template <typename next>
auto transform_st<F>::operator<<(const next &function) const
{
    return compose_st<transform_st<F>, next>{*this, function};
}

template <typename P>
auto keep(P &&pred)
{
    return keep_st {pred};
}

template <typename P>
template <typename next>
auto keep_st<P>::operator<<(const next &function) const
{
    return compose_st<keep_st<P>, next> {*this, function};
}

template <typename first_op, typename second_op>
template <typename next>
auto compose_st<first_op, second_op>::operator<<(const next &function) const
{
    return compose_st<compose_st<first_op, second_op>, next> {*this, function};
}

template <typename first_op, typename second_op>
template <typename container>
auto compose_st<first_op, second_op>::compose(container &other) const
{
    return other >> second >> first;
}

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
auto monad_adapter<container>::where(F &&func) const
{
    container result;
    for (auto it = cont.cbegin(); it != cont.cend(); ++it)
    {
        result += func(*it);
    }
    return monad_adapter<container>(result);
}

template <monad_container container>
template <typename R, typename F>
    requires reduce_function<F, R, typename container::value_type>
R monad_adapter<container>::reduce(F &&func, R initial) const
{
    R result = initial;
    for (auto it = cont.cbegin(); it != cont.cend(); ++it)
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
    for (auto it = cont.cbegin(); it != cont.cend(); ++it)
    {
        result += func(*it);
    }
    return monad_adapter<container>(result);
}

template <monad_container container>
template <typename F>
    requires where_function<F, typename container::value_type>
auto monad_adapter<container>::immutable_filter(F &&func) const
{
    container result;
    for (auto it = cont.cbegin(); it != cont.cend(); ++it)
    {
        if (func(*it))
        {
            result += *it;
        }
    }
    return monad_adapter<container>(result);
}

template <monad_container container>
template <typename F>
    requires callable<F, typename container::value_type>
auto monad_adapter<container>::operator>>(const transform_st<F> &st)
{
    return immutable_map(st.func);
}

template <monad_container container>
template <typename F>
    requires where_function<F, typename container::value_type>
auto monad_adapter<container>::operator>>(const keep_st<F> &st)
{
    return immutable_filter(st.pred);
}

template <monad_container container>
template <typename first_op, typename second_op>
auto monad_adapter<container>::operator>>(const compose_st<first_op, second_op> &st)
{
    return st.compose(*this);
}