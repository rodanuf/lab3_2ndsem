#include "../ui_headers/io_functions.hpp"

template <typename T>
void print(sequence<T> *container)
{
    std::cout << "[";
    for (int i = 0; i != container->get_length(); ++i)
    {
        if (i != container->get_length() - 1)
        {
            std::cout << ", ";
        }
        std::cout << container->get(i);
    }
    std::cout << "]" << std::endl;
}

inline std::istream &operator>>(std::istream &is, student &s)
{
    std::string name, surname, group_number;
    float grade;
    is >> name >> surname >> group_number >> grade;
    if (grade < 0 || grade > 5.0)
    {
        is.setstate(std::ios::failbit);
    }
    s.set_name(name);
    s.set_surname(surname);
    s.set_group_number(group_number);
    s.set_grade(grade);
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

inline std::ostream &operator<<(std::ostream &os, const student &s)
{
    os << s.get_name() << " " << s.get_surname() << " " << s.get_group_number() << " " << s.get_grade();
    return os;
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
