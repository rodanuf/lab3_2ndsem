#pragma once

template <typename T>
concept monad_container = requires(T container, const typename T::value_type &value) {
    typename T::value_type;
    container.begin();
    container.end();
    container.clear();
    { container + value };
};

template <typename F, typename T>
concept map_function = requires(F function, const T &value) {
    {
        function(value)
    };
};

template <typename F, typename T>
concept where_function = requires(F function, const T &value) {
    { function(value) } -> std::convertible_to<bool>;
};

template <typename F, typename R, typename T>
concept reduce_function = requires(F function, R &result, T &value) {
    { function(result, value) } -> std::convertible_to<R>;
};

template <monad_container container>
class monad_adapter
{
public:
    using result_type = container::value_type;

private:
    container cont;

public:
    monad_adapter();
    monad_adapter(const container &other);
    monad_adapter(container &&other);
    monad_adapter(const monad_adapter &other);
    monad_adapter(monad_adapter &&other);
    ~monad_adapter();

    monad_adapter &operator=(const container &other);
    monad_adapter &operator=(container &&other);
    monad_adapter &operator=(const monad_adapter &other);
    monad_adapter &operator=(monad_adapter &&other);

    container *operator->();
    const container *operator->() const;
    container &operator*();
    const container &operator*() const;

    template <typename F>
        requires map_function<F, result_type>
    void map(F &&func);

    template <typename F>
        requires where_function<F, result_type>
    void filter(F &&func);

    template <typename F>
        requires where_function<F, result_type>
    auto where(F &&func);

    template <typename R, typename F>
        requires reduce_function<F, R, result_type>
    R reduce(F &&func, R initial);

    template <typename F>
        requires map_function<F, result_type>
    auto immutable_map(F &&func) const;
};

#include "../monad_template/monad_adapter.tpp"