#include <iostream>
#include <cmath>
#include "../types_headers/complex.hpp"

complex::complex() : real(0.0), imag(0.0) {}
complex::complex(double real) : real(real), imag(0.0) {}
complex::complex(double real, double imag) : real(real), imag(imag) {}

complex complex::operator+(const complex &other)
{
    return complex(real + other.real, imag + other.imag);
}

complex complex::operator-(const complex &other)
{
    return complex(real - other.real, imag - other.imag);
}

complex complex::operator*(const complex &other)
{
    return complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

complex complex::operator/(const complex &other)
{
    double denominator = other.real * other.real + other.imag * other.imag;
    return complex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
}

bool complex::operator==(const complex &other)
{
    return (real == other.real) && (imag == other.imag);
}

bool complex::operator!=(const complex &other)
{
    return !(real == other.real) || (imag != other.imag);
}

bool complex::operator<(const complex &other)
{
    return get_modulus() < other.get_modulus();
}

bool complex::operator>(const complex &other)
{
    return get_modulus() > other.get_modulus();
}

bool complex::operator<=(const complex &other)
{
    return get_modulus() <= other.get_modulus();
}

bool complex::operator>=(const complex &other)
{
    return get_modulus() >= other.get_modulus();
}

double complex::get_modulus() const
{
    return sqrt(real * real + imag * imag);
}

double complex::get_real() const
{
    return real;
}

double complex::get_imag() const
{
    return imag;
}

void complex::set_real(double real)
{
    this->real = real;
}

void complex::set_imag(double imag)
{
    this->imag = imag;
}

inline std::istream &operator>>(std::istream &is, complex &c)
{
    double real = 0.0;
    double imag = 0.0;
    char next_symbol;
    is >> real;
    next_symbol = is.peek();
    if (next_symbol == 'i')
    {
        c.set_real(0.0);
        c.set_imag(real);
        return is;
    }
    if (next_symbol == '+')
    {
        char plus, i;
        is >> plus >> imag >> i;
        if (plus != '+' || i != 'i')
        {
            is.setstate(std::ios::failbit);
            return is;
        }
    }
    c.set_real(real);
    c.set_imag(imag);
    return is;
}

inline std::ostream &operator<<(std::ostream &os, const complex &c)
{
    if (c.get_imag() < 0 && c.get_imag() != -1)
    {
        os << c.get_real() << c.get_imag() << "i";
    }
    else if (c.get_imag() == -1)
    {
        os << c.get_real() << "-i";
    }
    else if (c.get_imag() == 0)
    {
        os << c.get_real();
    }
    else
    {
        os << c.get_real() << " + " << c.get_imag() << "i";
    }
    return os;
}