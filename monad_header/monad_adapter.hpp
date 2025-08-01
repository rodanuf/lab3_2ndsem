#pragma once

template <typename T>
concept monad_container = requires(T container) {
    typename T::value_type;
    container.begin();
    container.end();
};

template <typename F, typename T>
concept map_function = requires(F function, const T &value) {
    {
        function(value)
    };
};

template <typename F, typename T>
concept map_function = requires(F function, const T &value) {
    {
        function(value)->std::convertible_to<bool>
    };
};

template <typename F, typename R, typename T>
concept reduce_function = requires(F function, R &result, T &value) {
    {
        function(result, value)->std::convertible_to<R>;
    };
};

template <monad_container container, typename result_type = container::value_type>
class monad_adapter
{
private:
    container cont;

public:
    monad_adapter();
    monad_adapter(const container &other);
    monad_adapter(container &&other);
    monad_adapter(const monad_adapter &other);
    ~monad_adapter();

    monad_adapter &operator=(const container &other);
    monad_adapter &operator=(container &&other);
    monad_adapter &operator=(const monad_adapter &other);
    monad_adapter &operator=(monad_adapter &&other);

    template <map_function<result_type> F>
    auto map(F &&func);

    template <where_function func, monad_container cont>
    auto where(func &&function, cont &container);

    template <reduce_function func, monad_container cont>
    auto reduce(func &&function, cont &container);

    template <map_function func, monad_container cont>
    auto immutable_map(func &&function, cont &container);
};

#include "../monad_template/monad_adapter.tpp"