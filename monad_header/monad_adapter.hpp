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
    template <map_function, monad_container>
    auto map(map_function function, monad_container container);
};

#include "../monad_template/monad_adapter.tpp"