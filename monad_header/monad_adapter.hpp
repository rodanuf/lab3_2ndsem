#pragma once

template <typename F, typename T>
concept callable = requires(F &&func, const T &value) {
    std::invoke(std::forward<F>(func), value);
};

template <typename T>
concept monad_container = requires(T container, const typename T::value_type &value) {
    typename T::value_type;
    container.begin();
    container.end();
    container.clear();
    { container + value };
};

template <typename F, typename T>
concept map_function = callable<F, T>;

template <typename F, typename T>
concept where_function = requires(F function, const T &value) {
    { function(value) } -> std::convertible_to<bool>;
};

template <typename F, typename R, typename T>
concept reduce_function = requires(F function, R &result, T &value) {
    { function(result, value) } -> std::convertible_to<R>;
};

template <typename F>
struct transform_st
{
    F func;

    template <typename next>
    auto operator<<(const next &function) const;
};

template <typename P>
struct keep_st
{
    P pred;

    template <typename next>
    auto operator<<(const next &function) const;
};

template <typename F>
auto transform(F &&func);

template <typename P>
auto keep(P &&pred);

template <typename first_op, typename second_op>
struct compose_st
{
    first_op first;
    second_op second;

    template <typename next>
    auto operator<<(const next &function) const;

    template <typename container>
    auto compose(container &other) const;
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
    auto where(F &&func) const;

    template <typename R, typename F>
        requires reduce_function<F, R, result_type>
    R reduce(F &&func, R initial) const;

    template <typename F>
        requires map_function<F, result_type>
    auto immutable_map(F &&func) const;

    template <typename F>
        requires where_function<F, result_type>
    auto immutable_filter(F &&func) const;

    template <typename F>
        requires callable<F, result_type>
    auto operator>>(const transform_st<F> &st);

    template <typename F>
        requires where_function<F, result_type>
    auto operator>>(const keep_st<F> &st);

    template <typename first_op, typename second_op>
    auto operator>>(const compose_st<first_op, second_op> &st);
};

#include "../monad_template/monad_adapter.tpp"