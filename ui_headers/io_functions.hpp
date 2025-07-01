#pragma once
#include "../headers/sequence.hpp"
#include "../types_headers/complex.hpp"
#include "../types_headers/student.hpp"
#include "../types_headers/professor.hpp"

template <typename T>
void print(sequence<T> *container);

inline std::istream &operator>>(std::istream &is, student &s);
inline std::istream &operator>>(std::istream &is, complex &c);
inline std::istream &operator>>(std::istream &is, professor &p);
inline std::ostream &operator<<(std::ostream &os, const student &s);
inline std::ostream &operator<<(std::ostream &os, const complex &c);
inline std::ostream &operator<<(std::ostream &os, const professor &p);