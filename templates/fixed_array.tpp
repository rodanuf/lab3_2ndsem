#include "../headers/fixed_array.hpp"

template <typename T, std::size_t N>
fixed_array<T, N>::fixed_array(const fixed_array<T, N> &other)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        _array[i] = other._array[i];
    }
}

template <typename T, std::size_t N>
fixed_array<T, N>::fixed_array(fixed_array<T, N> &&other)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        _array[i] = std::move(other._array[i]);
    }
}

template <typename T, std::size_t N>
T& fixed_array<T, N>::operator[](std::size_t index)
{
    return _array[index];
}

template <typename T, std::size_t N>
const T& fixed_array<T, N>::operator[](std::size_t index) const
{
    return _array[index];
}

template <typename T, std::size_t N>
int fixed_array<T, N>::get_length() const
{
    return N;
}