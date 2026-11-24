#pragma once

#include <cstddef>

template <typename T, std::size_t N>
class fixed_array
{
private:
    T _array[N];

public:
    fixed_array() = default;
    fixed_array(const fixed_array &other);
    fixed_array(fixed_array &&other);

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    int get_length() const;
};

#include "../templates/fixed_array.tpp"