#pragma once
#include <iostream>
#include "../headers/sequence.hpp"
#include "../types_headers/complex.hpp"
#include "../types_headers/student.hpp"
#include "../types_headers/professor.hpp"

template <typename T>
void print(sequence<T> *container)
{
    std::cout << "[";
    for (int i = 0; i != container->get_length(); ++i)
    {
        if (i != 0)
        {
            std::cout << ", ";
        }
        std::cout << container->get(i);
    }
    std::cout << "]" << std::endl;
}

std::istream &operator>>(std::istream &is, student &s);
std::istream &operator>>(std::istream &is, complex &c);
std::istream &operator>>(std::istream &is, professor &p);
std::ostream &operator<<(std::ostream &os, const student &s);
std::ostream &operator<<(std::ostream &os, const complex &c);
std::ostream &operator<<(std::ostream &os, const professor &p);