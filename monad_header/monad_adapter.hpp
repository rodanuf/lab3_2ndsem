#pragma once

template <typename F, typename T, typename R>
class monad_adapter
{
private:
    concept monad_container = requires(T container);
    concept map_function = requires(F function, T &value);
    concept where_function = requires(F function, T &value);
    concept reduce_function = requires(F function, R &result, T &value);

public:
    template <map_function func, monad_container cont>
    auto map(func &&function, cont &container);

    template <where_function func, monad_container cont>
    auto where(func &&function, cont &container);

    template <reduce_function func, monad_container cont>
    auto reduce(func &&function, cont &container);

    template <map_function func, monad_container cont>
    auto immutable_map(func &&function, cont &container);
};

#include "../monad_template/monad_adapter.tpp"